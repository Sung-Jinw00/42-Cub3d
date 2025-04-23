/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:19 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

# include <stdint.h>
# include <math.h>
# include <limits.h>
# include "ft_structs.h"
# include "ft_types.h" 

/* ────────────────────────────────────────────────────────────────────────── */
/*                             Digits in a number                             */
/* ────────────────────────────────────────────────────────────────────────── */

int				ft_nbdigit(long double nb, int base);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                Calculations                                */
/* ────────────────────────────────────────────────────────────────────────── */

int				ft_sqrt(int nb);
int				ft_min(int *tab);
int				ft_max(int *tab);
int				ft_is_prime(int nb);
int				ft_find_next_prime(int nb);
int				ft_recursive_factorial(int nb);
int				ft_recursive_power(int nb, int power);
char			*ft_multiply(const char *s1, const char *s2);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                 Convertions                                */
/* ────────────────────────────────────────────────────────────────────────── */
// ───────────────────────────────
//  STR TO NB
// ───────────────────────────────

int				ft_atoi(char *nptr);
long			ft_atol(char *nptr);
float			ft_atof(char *nptr);
double			ft_atod(char *nptr);
long long		ft_atold(char *nptr);
unsigned int	ft_atoui(char *nptr);
unsigned long	ft_atoul(char *nptr);
int64_t			ft_atoi64(char *nptr);
uint64_t		ft_atoui64(char *nptr);
int				ft_natoi(const char *nptr, int *i);
int				ft_atoi_base(const char *nptr, char *base);
void			one_for_all(char *nptr, void *value, char *type);

// ───────────────────────────────
//  NB TO STR
// ───────────────────────────────

char			*ft_itoa(long long n);
char			*ft_uitoa(uint64_t n);
char			*ft_itoa_base(int n, char *base);
char			*ft_ftoa(long double n, int precision);
char			*all_for_one(void *value, int precision, char *type);

// ───────────────────────────────
//  NB TO NB
// ───────────────────────────────

void			ft_absolu(void *nb, void *dup, char *type);

// ───────────────────────────────
//  STR TO STR
// ───────────────────────────────

char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

// ───────────────────────────────
//  UPPER/LOWERCASES
// ───────────────────────────────

int				ft_tolower(int c);
int				ft_toupper(int c);

#endif