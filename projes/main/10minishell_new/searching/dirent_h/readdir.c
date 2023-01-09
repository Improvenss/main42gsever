/* CELEBR04

	 This example reads the contents of a root directory.

 */
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>

/**
 * @brief 
 * 
 * ls -la / | awk '{print $9}'
 * 
 * @return int 
 */
int	main() {
	DIR *dir;
	struct dirent *entry;

	if ((dir = opendir("/")) == NULL)
		perror("opendir() error");
	else {
		puts("contents of root:");
		while ((entry = readdir(dir)) != NULL)
			printf("	%s\n", entry->d_name);
		closedir(dir);
	}
}