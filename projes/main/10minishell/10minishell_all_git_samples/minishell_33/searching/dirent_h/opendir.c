#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void traverse(char *fn, int indent) {
	DIR *dir;
	struct dirent *entry;
	int count;
	char path[1025]; /*** EXTRA STORAGE MAY BE NEEDED ***/
	struct stat info;

	for (count=0; count<indent; count++) printf("	");
	printf("%s\n", fn);

	if ((dir = opendir(fn)) == NULL)
		perror("opendir() error");
	else {
		while ((entry = readdir(dir)) != NULL) {
			if (entry->d_name[0] != '.') {
				strcpy(path, fn);
				strcat(path, "/");
				strcat(path, entry->d_name);
				if (stat(path, &info) != 0)
					fprintf(stderr, "stat() error on %s: %s\n", path,
									strerror(errno));
				else if (S_ISDIR(info.st_mode))
							 traverse(path, indent+1);
			}
		}
		closedir(dir);
	}
}

int	main() {
	puts("Directory structure:");
	traverse("/etc", 0);
}
