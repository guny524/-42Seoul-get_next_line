/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:39:58 by min-jo            #+#    #+#             */
/*   Updated: 2022/04/08 17:07:44 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/*
* Malloc new bucket for tree map. and return it.
* Node not created in this func.
*
* @param[in] fd is the file descriptor number for read.
*/
t_gnl_tree	*new_bucket(int fd)
{
	t_gnl_tree	*ret;

	ret = malloc(sizeof(t_gnl_tree));
	if (NULL == ret)
		return (NULL);
	ret->fd = fd;
	ret->head = NULL;
	ret->last = NULL;
	ret->node_cnt = 0;
	ret->start = 0;
	ret->end = 0;
	ret->cnt = 0;
	ret->height = 1;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}

/*
* Search the bucket associated with fd in tree map started with root.
* and return it. and set pre to found bucket's parent.
* If do not need to update pre just pass NULL to pre argument.
* If GNL_TREE_UPDATE_HEIGHT falg specified, plus one all bucket's height
* on the way search path.
* Perform O(logn).
*
* @param[in] fd is the file descriptor number for read.
* @param[in] root is the pointer to tree root for searching bucket.
*/
t_gnl_tree	*tree_map_search(int fd, t_gnl_tree *root, t_gnl_tree **pre,
				t_e_gnl_tree flag)
{
	if (pre)
		*pre = NULL;
	while (NULL != root)
	{
		if (GNL_TREE_UPDATE_HIEGHT == flag)
			++root->height;
		if (fd == root->fd)
			return (root);
		else
		{
			if (pre)
				*pre = root;
			if (fd < root->fd)
				root = root->left;
			else if (fd > root->fd)
				root = root->right;
		}
	}
	return (NULL);
}

/*
* Delete all the data associated with fd.
* Delete GNL data nodes that chained with bucket and erase bucket.
* and rotate it to balance.
*
* @param[in] fd is the file descriptor number for read.
* @param[out] root is the pointer to tree root for searching bucket.
*/
char	*tree_map_delete(int fd, t_gnl_tree *root, char *ret)
{
	t_gnl_tree	*bucket;
	t_gnl_node	*n;
	t_gnl_node	*tmp;

	bucket = tree_map_search(fd, root);
	n = bucket->node;
	while (NULL != n->next)
	{
		tmp = n;
		n = n->next;
		free(tmp);
	}
	return (ret);
}

void	tree_map_update_height()
{

}

/*
*
*
* @param[in] ro is the rotate will be performed to balance AVL tree.
*/
void	tree_map_valance()
{

}

char	*free_tree_map(t_gnl_tree *root)
{
	t_index	*tmp_index;
	t_data	*tmp_data;

	while (fds->head)
	{
		while (fds->head->data_head)
		{
			tmp_data = fds->head->data_head;
			fds->head->data_head = fds->head->data_head->next;
			free(tmp_data);
		}
		tmp_index = fds->head;
		fds->head = fds->head->next;
		free(tmp_index);
	}
	fds->tail = NULL;
	return (-1);
}
//////
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	ret = dst;
	if (dst == src)
		return (ret);
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		src++;
		dst++;
	}
	return (ret);
}
