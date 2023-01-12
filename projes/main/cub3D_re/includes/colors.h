/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:42:12 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 17:53:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

//	COLORS --> 🟥 🟩 🟦
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

//	COLORS BOLD --> B🟥 B🟩 B🟦
# define B_CYAN		"\033[1;36m"
# define B_BLUE		"\033[1;34m"
# define B_YELLOW	"\033[1;33m"
# define B_GREEN	"\033[1;32m"
# define B_RED		"\033[1;31m"
# define B_RESET	"\033[1m"

//	MLX COLORS --> ⚪️
# define COLOR_RED		0xFF0000
# define COLOR_GREEN	0x00FF00
# define COLOR_BLUE		0x0000FF
# define COLOR_BLACK	0x000000
# define COLOR_ORANGE	0xFFA500
# define COLOR_YELLOW	0xFFFF00
# define COLOR_CYAN		0x00ffff
# define COLOR_SILVER	0xCCCCCC
# define COLOR_TUNDORA	0x444444
# define COLOR_D_PURPLE	0x300B19
# define COLOR_D_GREEN	0x0B3025

#endif