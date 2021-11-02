#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
#include <stdint.h>
#include <dirent.h>

int main(){

    DIR *Dir = opendir("/");
    struct dirent *ent;

	while (ent = readdir(Dir)) {
		if ((*ent).d_type == DT_REG || (*ent).d_type == DT_DIR)
			printf("%s\n", (*ent).d_name);
	}
	closedir(Dir);
}
