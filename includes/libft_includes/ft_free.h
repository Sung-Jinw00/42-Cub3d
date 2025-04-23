/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:23:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include <stddef.h>

void	ft_free(char **str);
void	free_array(char ***str);
void	multi_free(char *to_free, ...);
void	ft_free_array_of_array(char ****cmd_s);

#endif