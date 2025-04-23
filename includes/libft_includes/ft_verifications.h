/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifications.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:22:34 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:22:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VERIFICATIONS_H
# define FT_VERIFICATIONS_H

# include <stdbool.h>

bool	ft_isnum(int c);
bool	ft_isalnum(int c);
bool	ft_isalpha(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);
bool	ft_isupalpha(int c);
bool	ft_islowalpha(int c);
bool	ft_iswhitespace(int c);
int		ft_isnum_equal_al(int c);
bool	ft_isbetween(int nb, int min, int max);
int		ft_strnchr(const char *s, const char *to_find, int len);

#endif