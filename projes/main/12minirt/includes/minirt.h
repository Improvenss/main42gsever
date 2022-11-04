/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:40:24 by gsever            #+#    #+#             */
/*   Updated: 2022/11/02 20:12:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h> /* OK:
	write()		-> System call used to write data from the buffer
		ssize_t	write(int fd, const void *buf, size_t count);
https://man7.org/linux/man-pages/man2/write.2.html
	read()		-> Read from a file descriptor
		ssize_t read(int fd, void *buf, size_t count);
https://man7.org/linux/man-pages/man2/read.2.html
*/
# include <stdlib.h> /* OK:
	free()		-> Deallocatig all allocated memory
		void free(void *ptr);
https://www.ibm.com/docs/en/i/7.5?topic=functions-free-release-storage-blocks
	exit()		-> Closing everything with atexit() and terminates program
		noreturn void exit(int status);
https://man7.org/linux/man-pages/man3/exit.3.html
*/
# include <stdio.h> /* OK:
	printf()	-> A library function to send formatted output to the screen
		int printf(const char *restrict format, ...);
https://man7.org/linux/man-pages/man3/printf.3.html
	perror()	-> System error messages
		void perror(const char *string);
https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-perror\
-print-error-message
*/
# include <stdint.h> /* OK: -NUMBERS-
	Type	 	Name		Num_Bytes	Num_Bits	Integer_Range
	int8_t	 ->	char			1			8		-128 to 127,
	int16_t	 ->	short			2			16		-32768 to 32767,
	int32_t	 ->	int				4			32		-2147483648 to 2147483647,
	int64_t	 ->	long long		8			64	-9.223372e+18 to 9.223372e+18
	uint8_t	 ->	unsigned char	1			8			0 to 255,
	uint16_t ->	unsigned short	2			16			0 to 65535,
	uint32_t ->	unsigned int	4			32			0 to 4294967295,
	uint64_t ->	unsigned l_l 	8			64		0 to 18446744073709551615
*/
# include <string.h> /* OK:
	malloc()	-> Allocating memory with NULL
		void *malloc(size_t size);
https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-malloc-\
reserve-storage-block
	strerror()	-> System error messages; Writing int errno's string value.
		char *strerror(int errnum);
https://www.ibm.com/docs/en/zos/2.5.0?topic=functions-strerror-\
get-pointer-runtime-error-message
*/
# include <fcntl.h> /*  OK: -File control-
	open()		-> Open or Create a file for reading or writing.
		int open(const char *path, int oflag, . . .);
https://www.ibm.com/docs/en/i/7.5?topic=ssw_ibm_i_75/apis/open.htm
	close()		-> Close File or Socket descriptor.
		int close(int fd);
https://www.ibm.com/docs/en/i/7.5?topic=ssw_ibm_i_75/apis/close.htm
*/
# include <errno.h> /* OK: int errno = 0;
	errno;
*/
# include "../libraries/libft/includes/libft.h"
# include "colors.h" /* 🟥 🟩 🟦
	BLACK	"\033[0;30m"	B_RED		"\033[1;31m"
	RED		"\033[0;31m"	B_GREEN		"\033[1;32m"
	GREEN	"\033[0;32m"	B_YELLOW	"\033[1;33m"
	YELLOW	"\033[0;33m"	B_BLUE		"\033[1;34m"
	BLUE	"\033[0;34m"	B_CYAN		"\033[1;36m"
	PURPLE	"\033[0;35m"	B_RESET		"\033[1m"
	CYAN	"\033[0;36m"
	WHITE	"\033[0;37m"
	END		"\033[m"
	RESET	"\033[0m"
*/

# define CMD_CLEAR	"\e[1;1H\e[2J"

# define ERROR				-1

/* ************************************************************************** */
/* STRUCT DEFINES AREA													  	  */
/* ************************************************************************** */

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

#endif
