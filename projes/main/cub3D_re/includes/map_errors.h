/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:51:35 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 20:51:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ERRORS_H
# define MAP_ERRORS_H

# define ERR_ARGS				"Map argument unspecified!"
# define ERR_ARGS_MANY			"Too many arguments entered!"
# define ERR_ARGS_EXIST			"Map argument doesn't exist!"
# define ERR_EXTENSION			"Map extension is incorrect!"
# define ERR_MAP_EMPTY			"Map is empty!"
# define ERR_INVALID_INPUT		"Invalid input!"
# define ERR_DEF_MISSING		"Map definitions are missing or incorrect!"
# define ERR_FILE_WRONG			"File extension is incorrect!"
# define ERR_FILE_NOT_FOUND		"File does not exist!"
# define ERR_MAP_F				"Map F extension is incorrect!"
# define ERR_MAP_C				"Map C extension is incorrect!"
# define ERR_MALLOC				"Cannot allocate memory!"
# define ERR_BORDER				"Map Border"
# define ERR_ARG_OOB			"Out-of-Bounds Argument"
# define ERR_EMPTY_L			"Empty Line"
# define ERR_MAP_CHARS			"Map characters are used inappropriately!"
# define ERR_SET_MAP			"Set the map!"
# define ERR_WRONG_CHAR			"Don't use characters other than \
		\n'(space)','1','0','N','S','W','E' in the map!"
# define ERR_SPAWN_MULTIPLE		"Don't set multiple spawn points(N,S,W,E)!"
# define ERR_SPAWN_NOT_SET		"You need to set a spawn point(N,S,W,E)!"

#endif