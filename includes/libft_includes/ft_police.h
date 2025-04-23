/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:05 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 16:24:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POLICE_H
# define FT_POLICE_H

/* ══════════════════════════════════════════════════════════════════════════ */
/*                                 TEXT STYLES                                */
/* ══════════════════════════════════════════════════════════════════════════ */

/* Reset all text formatting */
# ifndef RESET
#  define RESET				"\033[0m"
# endif

/* Bold text */
# ifndef BOLD
#  define BOLD				"\033[1m"
# endif

/* Underlined text */
# ifndef UNDERLINE
#  define UNDERLINE			"\033[4m"
# endif

/* Italic text */
# ifndef ITALIC
#  define ITALIC			"\033[3m"
# endif

/* Reverse foreground and background */
# ifndef REVERSED
#  define REVERSED			"\033[7m"
# endif

/* Blinking text (may not work in all terminals) */
# ifndef BLINK
#  define BLINK				"\033[5m"
# endif

/* Makes text invisible */
# ifndef INVISIBLE
#  define INVISIBLE			"\033[8m"
# endif

#endif