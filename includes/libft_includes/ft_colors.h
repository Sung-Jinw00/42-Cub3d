/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:56:34 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 17:56:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

/* ══════════════════════════════════════════════════════════════════════════ */
/*                              FOREGROUND COLORS                             */
/* ══════════════════════════════════════════════════════════════════════════ */

/* Black text */
# ifndef BLACK
#  define BLACK				"\033[30m"
# endif

/* Red text */
# ifndef RED
#  define RED				"\033[31m"
# endif

/* Green text */
# ifndef GREEN
#  define GREEN				"\033[32m"
# endif

/* Yellow text */
# ifndef YELLOW
#  define YELLOW			"\033[33m"
# endif

/* Blue text */
# ifndef BLUE
#  define BLUE				"\033[34m"
# endif

/* Magenta text */
# ifndef MAGENTA
#  define MAGENTA			"\033[35m"
# endif

/* Cyan text */
# ifndef CYAN
#  define CYAN				"\033[36m"
# endif

/* White text */
# ifndef WHITE
#  define WHITE				"\033[37m"
# endif

/* Bright black text */
# ifndef BRIGHT_BLACK
#  define BRIGHT_BLACK		"\033[90m"
# endif

/* Bright red text */
# ifndef BRIGHT_RED
#  define BRIGHT_RED		"\033[91m"
# endif

/* ══════════════════════════════════════════════════════════════════════════ */
/*                              BACKGROUND COLORS                             */
/* ══════════════════════════════════════════════════════════════════════════ */

/* Black background */
# ifndef BG_BLACK
#  define BG_BLACK			"\033[40m"
# endif

/* Red background */
# ifndef BG_RED
#  define BG_RED			"\033[41m"
# endif

/* Green background */
# ifndef BG_GREEN
#  define BG_GREEN			"\033[42m"
# endif

/* Yellow background */
# ifndef BG_YELLOW
#  define BG_YELLOW			"\033[43m"
# endif

/* Blue background */
# ifndef BG_BLUE
#  define BG_BLUE			"\033[44m"
# endif

/* Magenta background */
# ifndef BG_MAGENTA
#  define BG_MAGENTA		"\033[45m"
# endif

/* Cyan background */
# ifndef BG_CYAN
#  define BG_CYAN			"\033[46m"
# endif

/* White background */
# ifndef BG_WHITE
#  define BG_WHITE			"\033[47m"
# endif

/* Bright black background */
# ifndef BG_BRIGHT_BLACK
#  define BG_BRIGHT_BLACK	"\033[100m"
# endif

/* Bright red background */
# ifndef BG_BRIGHT_RED
#  define BG_BRIGHT_RED		"\033[101m"
# endif

/* Bright green background */
# ifndef BG_BRIGHT_GREEN
#  define BG_BRIGHT_GREEN	"\033[102m"
# endif

/* Bright yellow background */
# ifndef BG_BRIGHT_YELLOW
#  define BG_BRIGHT_YELLOW	"\033[103m"
# endif

/* Bright blue background */
# ifndef BG_BRIGHT_BLUE
#  define BG_BRIGHT_BLUE	"\033[104m"
# endif

/* Bright magenta background */
# ifndef BG_BRIGHT_MAGENTA
#  define BG_BRIGHT_MAGENTA	"\033[105m"
# endif

/* Bright cyan background */
# ifndef BG_BRIGHT_CYAN
#  define BG_BRIGHT_CYAN	"\033[106m"
# endif

/* Bright white background */
# ifndef BG_BRIGHT_WHITE
#  define BG_BRIGHT_WHITE	"\033[107m"
# endif

/* ══════════════════════════════════════════════════════════════════════════ */
/*                               RGBA HEX COLORS                              */
/* ══════════════════════════════════════════════════════════════════════════ */

/* RGBA black */
# ifndef OX_BLACK
#  define OX_BLACK			0x00000000
# endif

/* RGBA red */
# ifndef OX_RED
#  define OX_RED			0x00FF0000
# endif

/* RGBA green */
# ifndef OX_GREEN
#  define OX_GREEN			0x0000FF00
# endif

/* RGBA blue */
# ifndef OX_BLUE
#  define OX_BLUE			0x000000FF
# endif

/* RGBA yellow */
# ifndef OX_YELLOW
#  define OX_YELLOW			0x00FFFF00
# endif

/* RGBA magenta */
# ifndef OX_MAGENTA
#  define OX_MAGENTA		0x00FF00FF
# endif

/* RGBA cyan */
# ifndef OX_CYAN
#  define OX_CYAN			0x0000FFFF
# endif

/* RGBA white */
# ifndef OX_WHITE
#  define OX_WHITE			0x00FFFFFF
# endif

/* RGBA gray */
# ifndef OX_GRAY
#  define OX_GRAY			0x00808080
# endif

/* RGBA orange */
# ifndef OX_ORANGE
#  define OX_ORANGE			0x00FFA500
# endif

/* RGBA pink */
# ifndef OX_PINK
#  define OX_PINK			0x00FFC0CB
# endif

/* RGBA violet */
# ifndef OX_VIOLET
#  define OX_VIOLET			0x00800080
# endif

/* RGBA turquoise */
# ifndef OX_TURQUOISE
#  define OX_TURQUOISE		0x00E0D0D0
# endif

/* RGBA beige */
# ifndef OX_BEIGE
#  define OX_BEIGE			0x00F5DCBE
# endif

/* RGBA brown */
# ifndef OX_BROWN
#  define OX_BROWN			0x002A2A2A
# endif

/* RGBA olive */
# ifndef OX_OLIVE
#  define OX_OLIVE			0x00808000
# endif

/* RGBA lime */
# ifndef OX_LIME
#  define OX_LIME			0x0000FF00
# endif

/* RGBA indigo */
# ifndef OX_INDIGO
#  define OX_INDIGO			0x00820082
# endif

/* RGBA peach */
# ifndef OX_PEACH
#  define OX_PEACH			0x00DAB9D2
# endif

/* RGBA light blue */
# ifndef OX_LIGHT_BLUE
#  define OX_LIGHT_BLUE		0x00D8E6FF
# endif

/* RGBA navy blue */
# ifndef OX_NAVY_BLUE
#  define OX_NAVY_BLUE		0x00008080
# endif

/* RGBA forest green */
# ifndef OX_FOREST_GREEN
#  define OX_FOREST_GREEN	0x0028B22F
# endif

/* RGBA gold */
# ifndef OX_GOLD
#  define OX_GOLD			0x00D70000
# endif

/* RGBA chartreuse */
# ifndef OX_CHARTREUSE
#  define OX_CHARTREUSE		0x0000FF00
# endif

/* RGBA coral */
# ifndef OX_CORAL
#  define OX_CORAL			0x007F5042
# endif

/* RGBA pearl */
# ifndef OX_PEARL
#  define OX_PEARL			0x00E68C8C
# endif

#endif
