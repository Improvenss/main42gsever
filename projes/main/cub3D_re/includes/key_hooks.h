/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:37:47 by gsever            #+#    #+#             */
/*   Updated: 2023/01/12 16:29:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOKS_H
# define KEY_HOOKS_H

// https://www.toptal.com/developers/keycode
// https://docs.oracle.com/cd/E67482_01/oscar/pdf/45/OnlineHelp_45/helpOnPS2keyCodes.html

// PS2 keyboard Key code (Windows) oracle linux //
//---->My PC(PS2 keyboard) Key Codes<----//
# if defined(__APPLE__)
#  define FREE_MLX			0
#  define KEY_W				13
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_R				15

#  define KEY_ESC			53

#  define KEY_ARROW_UP		126
#  define KEY_ARROW_DOWN	125
#  define KEY_ARROW_LEFT	123
#  define KEY_ARROW_RIGHT	124

#  define GO_FORWARD		1
#  define GO_BACKWARD		2
#  define GO_LEFT			4
#  define GO_RIGHT			8
#  define TURN_UP			16
#  define TURN_DOWN			32
#  define TURN_LEFT			64
#  define TURN_RIGHT		128
# endif

// ---->AppleScript Key Codes<----//
# if defined(linux)
#  define FREE_MLX			1
#  define KEY_W				119
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
// #  define KEY_R				??

#  define KEY_ESC			65307

#  define KEY_ARROW_UP		65362
#  define KEY_ARROW_DOWN	65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363

#  define GO_FORWARD		1
#  define GO_BACKWARD		2
#  define GO_LEFT			4
#  define GO_RIGHT			8
#  define TURN_UP			16
#  define TURN_DOWN			32
#  define TURN_LEFT			64
#  define TURN_RIGHT		128
# endif

#endif