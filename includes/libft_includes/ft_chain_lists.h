/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chain_lists.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:37 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:23:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAIN_LISTS_H
# define FT_CHAIN_LISTS_H

# include <stdlib.h>
# include <stdio.h>
# include "ft_printing.h"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
} t_list,	t_cell;

/* ────────────────────────────────────────────────────────────────────────── */
/*                                  Free List                                 */
/* ────────────────────────────────────────────────────────────────────────── */

void	free_list(t_list **L);
t_list	*free_at(t_list *L, int pos);
void	ft_list_remove_if(t_list **begin_list, void *data_ref);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                 Get a value                                */
/* ────────────────────────────────────────────────────────────────────────── */

void	*get_at(t_list *L, int pos);
int		ft_list_find_pos(t_list *begin_list, void *data_ref);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                  Len List                                  */
/* ────────────────────────────────────────────────────────────────────────── */

long	len_list(t_list *L);

/* ────────────────────────────────────────────────────────────────────────── */
/*                               Memory allocation                            */
/* ────────────────────────────────────────────────────────────────────────── */

t_cell	*create_cell(void *data);
t_list	*ft_listdup(t_list *src);
char	**splited_list(t_list *list);
t_list	*ft_listndup(t_list *src, int n);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                Modification                                */
/* ────────────────────────────────────────────────────────────────────────── */

int		ft_is_sorted_list(t_list *list);
void	ft_list_sort(t_list **begin_list);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                 Print List                                 */
/* ────────────────────────────────────────────────────────────────────────── */

void	print_list(t_list *L, char *data_type);

/* ────────────────────────────────────────────────────────────────────────── */
/*                               Search a value                               */
/* ────────────────────────────────────────────────────────────────────────── */

int		ft_list_find_data(t_list *begin_list, void *data_ref);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                 Set a value                                */
/* ────────────────────────────────────────────────────────────────────────── */

void	set_at(t_list *L, void *data, int pos);
t_list	*add_at(t_list *L, void *data, int pos);
void	ft_listadd_back(t_list **list, t_list *new);
void	ft_list_foreach_data(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_data_if(t_list *begin_list, void (*f)(void *),
			void *data_ref);

#endif