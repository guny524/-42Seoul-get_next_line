/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:26:37 by min-jo            #+#    #+#             */
/*   Updated: 2022/04/08 17:15:57 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

typedef enum e_state_gnl
{
	STATE_GNL_ERROR,
	STATE_GNL_START,
	STATE_GNL_CHECK_MALLOC_READ,
	STATE_GNL_MAKE_LINE,
	STATE_GNL_FINISH,
}	t_e_state_gnl;

typedef struct s_gnl_read_info
{
}	t_gnl_read_info;

typedef struct s_gnl_tree
{
	int			fd;
	t_gnl_node	*head;
	t_gnl_node	*last;
	size_t		node_cnt;
	size_t		start;
	size_t		end;
	size_t		cnt;
	int			height;
	t_gnl_tree	*left;
	t_gnl_tree	*right;
}	t_gnl_tree;

typedef struct s_gnl_node
{
	char		str[BUFFER_SIZE];
	t_gnl_node	*next;
}	t_gnl_node;

typedef enum e_gnl_tree
{
	GNL_TREE_DO_NOTHING,
	GNL_TREE_UPDATE_HIEGHT,
	GNL_TREE_ROTATE_LEFT,
	GNL_TREE_ROTATE_RIGHT,
}	t_e_gnl_tree;

/*
* get_next_line_utils.c
*/
t_gnl_tree		*new_bucket(int fd);
t_gnl_tree		*tree_map_search(int fd, t_gnl_tree *root, t_gnl_tree **pre,
					t_e_gnl_tree flag);
char			*tree_map_delete(int fd, t_gnl_tree *root, char *ret);
void			tree_map_valance();
char			*free_tree_map(t_gnl_tree *root);
/*
* get_next_line.c
*/
t_e_state_gnl	start(int fd, t_gnl_tree *root, t_gnl_tree **bucket_ret);
t_e_state_gnl	check_malloc_read(t_gnl_tree *bucket);
t_e_state_gnl	make_line(t_gnl_tree *bucket, char **ret);
char			*get_next_line(int fd);

#endif
