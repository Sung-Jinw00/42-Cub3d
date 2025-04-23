/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:36:57 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 23:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

// ───────────────────────────────
//  INTEGER LIMITS IN STRING
// ───────────────────────────────

# ifndef FT_INT64_MAX
#  define FT_INT64_MAX		"9223372036854775807"
# endif
# ifndef FT_INT64_MIN
#  define FT_INT64_MIN		"-9223372036854775808"
# endif

# ifndef FT_UINT64_MAX
#  define FT_UINT64_MAX		"18446744073709551615"
# endif

// ───────────────────────────────
//  SIGNED TYPES
// ───────────────────────────────

# ifndef FT_SIGNED
#  define FT_SIGNED			"signed"
# endif

# ifndef FT_INT
#  define FT_INT			"int"
# endif

# ifndef FT_LONG
#  define FT_LONG			"long"
# endif

# ifndef FT_LLONG
#  define FT_LLONG			"long long"
# endif

# ifndef FT_INT64
#  define FT_INT64			"int64"
# endif

// ───────────────────────────────
//  UNSIGNED TYPES
// ───────────────────────────────

# ifndef FT_UNSIGNED
#  define FT_UNSIGNED		"unsigned"
# endif

# ifndef FT_UINT
#  define FT_UINT			"unsigned int"
# endif

# ifndef FT_ULONG
#  define FT_ULONG			"unsigned long"
# endif

# ifndef FT_ULLONG
#  define FT_ULLONG			"unsigned long long"
# endif

# ifndef FT_UINT64
#  define FT_UINT64			"uint64"
# endif

// ───────────────────────────────
//  FOALTING-POINT TYPES
// ───────────────────────────────

# ifndef FT_FLOAT
#  define FT_FLOAT			"float"
# endif

# ifndef FT_DOUBLE
#  define FT_DOUBLE			"double"
# endif

# ifndef FT_LONGDOUBLE
#  define FT_LONGDOUBLE		"long double"
# endif

# ifndef FT_DBL_MAX
#  define FT_DBL_MAX		1.7976931348623157e+308
# endif

# ifndef FT_DBL_MIN
#  define FT_DBL_MIN		2.2250738585072014e-308
# endif

# ifndef FT_FLT_MAX
#  define FT_FLT_MAX		3.402823466e+38F
# endif

# ifndef FT_FLT_TRUE_MIN
#  define FT_FLT_TRUE_MIN	1.401298464324817e-45F
# endif

#endif