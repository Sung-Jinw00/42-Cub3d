/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_related_to_strings.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:44 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:24:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RELATED_TO_STRINGS_H
# define FT_RELATED_TO_STRINGS_H

# include <stdlib.h>
# include <stdbool.h>
# include "ft_structs.h"

/* ────────────────────────────────────────────────────────────────────────── */
/*                                 Comparisons                                */
/* ────────────────────────────────────────────────────────────────────────── */
// ───────────────────────────────
//  Return An Occurence
// ───────────────────────────────

char	*ft_strchr(const char *s, int c);
char	*get_multi_cmp(const char *s1, ...);
char	**ft_arr_strsrch(char **array, char *str);
void	*ft_memchr(const void *s, int c, size_t n);
char	*get_multi_ncmp(int n, const char *s1, ...);
char	*ft_str_charset(const char *s, char *charset);
int		ft_str_isformat(const char *s, char *format);
char	*get_multi_revncmp(int n, const char *s1, ...);
char	*ft_substr(char *s, unsigned int start, size_t len,
			bool to_free);
char	*ft_strnstr(const char *big, const char *little, size_t len);

// ───────────────────────────────
//  Return The Difference
// ───────────────────────────────

int		str_multi_cmp(const char *s1, ...);
char	multi_charcmp(char c, char *str_char);
int		ft_strcmp(const char *s1, const char *s2);
int		str_multi_ncmp(int n, const char *s1, ...);
int		str_multi_revncmp(int n, const char *s1, ...);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_str_revncmp(const char *s1, const char *s2, int n);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                   Lenght                                   */
/* ────────────────────────────────────────────────────────────────────────── */

size_t	ft_strlen(const char *s);
int		ft_count_words(void *arg);
int		ft_arrintlen(char *str_char);
size_t	ft_strclen(const char *s, char c);
size_t	ft_strrclen(const char *s, char c);
int		ft_roffset(const char *str, char c);
size_t	ft_str_strlen(const char *s1, char *s2);
int		ft_offset(const char *str, char *charset);
int		ft_strspn(const char *str, char *charset);
int		ft_strrspn(const char *str, char *charset);

/* ────────────────────────────────────────────────────────────────────────── */
/*                                Modifications                               */
/* ────────────────────────────────────────────────────────────────────────── */
// ───────────────────────────────
//  Apply A Function
// ───────────────────────────────

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// ───────────────────────────────
//  Concatenates
// ───────────────────────────────
// ----------------
//  Strings
// ----------------

char	*multi_join(char *s1, ...);
char	*ft_strcat(char *dest, char *src);
char	*ft_arr_to_str(char **arr, char *linker);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncat(char *dest, char *src, size_t nb);
char	*ft_arrn_to_str(char **arr, char *linker, int n);
char	*multi_join_n_free(char *to_free, char *s1, ...);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
char	*ft_strjoin_n_free(char *s1, char *s2, int tab_to_free);
char	*ft_strnjoin(char const *s1, size_t n_s1, char const *s2, size_t n_s2);
// ----------------
//  Arrays
// ----------------

char	**multi_arrjoin(char **s1, ...);
char	**ft_arrjoin(char **s1, char **s2);
char	**multi_arrjoin_n_free(char *to_free, char **s1, ...);
char	**ft_arrnjoin(char **s1, size_t n1, char **s2, size_t n2);
char	**ft_arrjoin_n_free(char **s1, char **s2, int tab_to_free);

// ───────────────────────────────
//  Replace Dest By Src
// ───────────────────────────────

char	*ft_strcpy(char *dst, const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
char	*ft_strncpy(char *dst, const char *src, size_t dsize);

// ───────────────────────────────
//  Reverse
// ───────────────────────────────

void	ft_swap_int(int *a, int *b);
void	ft_swap_char(char *c1, char *c2);
void	ft_swap_str(char **c1, char **c2);
void	ft_swap_int_array(int **a, int **b);
char	*ft_strrev(char *str, bool to_malloc);
char	**ft_revarray(char **array, bool to_malloc);
void	ft_swap(void *elem1, void *elem2, size_t size);

// ───────────────────────────────
//  Set A String
// ───────────────────────────────

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		*str_to_arrint(char *str_char, int *len_arrint);
char	*ft_remove_from_string(char *str, char *to_delete, int free_str);
char	*ft_replace_from_string(char *str, char *to_search, char *to_replace,
			int to_free);

// ───────────────────────────────
//  Splits
// ───────────────────────────────

char	**ft_strsplit(char *str, char *sep);
char	**ft_split(char *str, char *charset);
char	**ft_nsplit(char *str, char *charset, int n);

// ───────────────────────────────
//  Truncate
// ───────────────────────────────

char	*ft_strtrim(char *s1, char const *set, bool to_free);

#endif