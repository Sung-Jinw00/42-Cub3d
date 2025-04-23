/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:13:53 by marvin            #+#    #+#             */
/*   Updated: 2025/04/13 20:13:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <stdarg.h>
# include <stdint.h>

// ───────────────────────────────
//  multi_join_n_free
// ───────────────────────────────

typedef struct s_mjnf
{
	char	*arg;
	va_list	args;
	char	*new_string;
	int		*tabs_to_free;
	int		cur_str;
	int		tab_increment;
	int		tab_len;
}	t_mjnf;

// ───────────────────────────────
//  multi_arrjoin_n_free
// ───────────────────────────────

typedef struct s_majnf
{
	char	**arg;
	va_list	args;
	char	**new_arr;
	int		*tabs_to_free;
	int		cur_str;
	int		tab_increment;
	int		tab_len;
}	t_majnf;

// ───────────────────────────────
//  ft_ftoa
// ───────────────────────────────

typedef struct s_ftoa
{
	char		*cpy;
	long double	nb;
	uint64_t	dec_nb;
	int			int_part;
	int			dec_part;
	int			sign;
}	t_ftoa;

// ───────────────────────────────
//  ft_sscanf
// ───────────────────────────────

typedef struct s_sscanf
{
	char		src[50000];
	int			len_src;
	int			i;
	char		end_arg;
	int			output;
}	t_sscanf;

#endif