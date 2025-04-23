/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:29 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:24:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTING_H
# define FT_PRINTING_H

# include <unistd.h>

/* ────────────────────────────────────────────────────────────────────────── */
/*                                 Print Chars                                */
/* ────────────────────────────────────────────────────────────────────────── */

void	ft_putchar_fd(int fd, char c);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                Print Strings                               */
/* ────────────────────────────────────────────────────────────────────────── */

int		ft_write(int fd, char *s);
void	ft_putstr_fd(int fd, char *s);
void	ft_putendl_fd(int fd, char *s);
int		ft_multi_write(int fd, char *s1, ...);
void	ft_putcstr_fd(int fd, char *s, char c);
void	ft_putnstr_fd(int fd, char *s, size_t n);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                Print Arrays                                */
/* ────────────────────────────────────────────────────────────────────────── */

void	print_array(char **tab);
void	print_array_fd(int fd, char **tab);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                Print Numbers                               */
/* ────────────────────────────────────────────────────────────────────────── */

void	ft_putnbr_fd(int fd, int n);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_base_fd(int fd, int nbr, char *base);

#endif