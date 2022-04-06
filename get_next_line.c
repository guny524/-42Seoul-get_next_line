/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:23:12 by min-jo            #+#    #+#             */
/*   Updated: 2022/04/08 17:15:26 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*
* Start state for gnl.
* Serach bucket associate with fd start form root.
* Return next state.
* If bucket exist, there may be strings with newlines inside.
* return STATE_GNL_CHECK_NEW_LINE state.
* Else bucket doesn't exist, make new one and
* return STATE_GNL_READ_BUFSIZE state.
*
* @param[in] fd is the file descriptor number for read.
* @param[in] root is the pointer to tree root for searching bucket.
* @param[out] bucket_ret is the double pointer using instead of return
* to set found bucket's address
*/
t_e_state_gnl	start(int fd, t_gnl_tree *root, t_gnl_tree **bucket_ret)
{
	t_gnl_tree	*parent;

	// 기존에 맵에 있는지 확인
	*bucket_ret = tree_map_search(fd, root, NULL, GNL_TREE_DO_NOTHING);
	// 있으면 개행확인, malloc, read
	if (*bucket_ret)
		return (STATE_GNL_CHECK_MALLOC_READ);
	// 없으면 동적할당
	*bucket_ret = new_bucket(fd);
	if (NULL == *bucket_ret)
		return (STATE_GNL_ERROR);
	// 동적할당 후 삽입
	tree_map_search(fd, root, &parent, GNL_TREE_UPDATE_HIEGHT);
	if (fd < parent->fd)
		parent->left = *bucket_ret;
	else
		parent->right = *bucket_ret;
	// 개행확인 후 read
	return (STATE_GNL_CHECK_MALLOC_READ);
}

/*
* Check_malloc_read state for gnl.
* Return next state.
* Repeat 3 things. check new line, malloc new node, read.
* If there is node in fd alreay, will be checked new line exist first.
* Else there is no node in fd, start, end, cnt will 0 and no check processed.
* Malloc new node and put it to bucket->last.
* Read count will be saved as bucket->end but not include Null character.
*
* @param[out] bucket is the pointer to found bucket.
*/
t_e_state_gnl	check_malloc_read(t_gnl_tree *bucket)
{
	t_gnl_node	*n;

	while (1)
	{
		if (1 == bucket->node_cnt)
			bucket->cnt = bucket->start - 1;
		else
			bucket->cnt = 0;
		while (++bucket->cnt < bucket->end)
			if ('\n' == bucket->last->str[bucket->cnt])
				return (STATE_GNL_MAKE_LINE);
		n = malloc(sizeof(t_gnl_node));
		if (NULL == n)
			return (STATE_GNL_ERROR);
		n->next = NULL;
		if (NULL == bucket->head && NULL == bucket->last)
			bucket->head = n;
		else
			bucket->last->next = n;
		bucket->last = n;
		++bucket->node_cnt;
		bucket->end = read(bucket->fd, n->str, BUFFER_SIZE);
		if (bucket->end == -1)
			return (STATE_GNL_ERROR);
	}
}

/*
*
*
*
*/
t_e_state_gnl	make_line(t_gnl_tree *bucket, char **ret)
{
	size_t		size;
	t_gnl_node	*n;
	void		*dst;

	if (1 == bucket->node_cnt)
		size = bucket->end - bucket->start + 1;
	else
		size = BUFFER_SIZE * (bucket->node_cnt - 1) + bucket->cnt - 1
			- (bucket->start + 1);
	*ret = malloc(sizeof(char) * size + 1);
	if (NULL == *ret)
		return (STATE_GNL_ERROR);
	*ret[size] = '\0';
	dst = *ret;
	n = bucket->head;
	while (n != bucket->last)
	{
		while ()
		{
			*(unsigned char*)dst = *(unsigned char*) ;

			tmp = (*index)->data_head;
			ft_memcpy(line, tmp->str + tmp->start, tmp->end - tmp->start);
			line += tmp->end - tmp->start;
			if ((*index)->data_head == (*index)->data_tail)
				break ;
			(*index)->data_head = tmp->next;
			free(tmp);
			(*index)->cnt--;
		}
	}
	(*index)->data_head->start = (*index)->data_head->end + 1;
	return (STATE_GNL_FINISH);
}

/*
*
*
*
*/
char	*get_next_line(int fd)
{
	static t_gnl_tree	*root;
	t_e_state_gnl		state;
	t_gnl_tree			*bucket;
	char				*ret;

	if (0 == BUFFER_SZIE)
		return (NULL);
	state = STATE_GNL_START;
	while (1)
	{
		if (state == STATE_GNL_ERROR)
			return (free_tree_map(root));
		else if (STATE_GNL_START == state)
			state = start(fd, &root, &bucket);
		else if (STATE_GNL_CHECK_MALLOC_READ == state)
			state = check_malloc_read(bucket);
		else if (STATE_GNL_MAKE_LINE == state)
			state = make_line(bucket, &ret);
		else if (STATE_GNL_FINISH == state)
			break ;
	}
	return (tree_map_delete(fd, root, ret));
}
