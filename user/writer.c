#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
	int fd, bytes;
	char* a;

	if (argc == 3){
		open(argv[1], O_CREATE);	
		fd = open(argv[1], O_WRONLY);
		bytes = atoi(argv[2]);
		a = malloc(bytes);
		memset(a, 'a', bytes);
		write(fd, a, bytes);
		exit();	
	} else {
		printf("bad request: 'writer -filename -bytes'\n");
		exit();
	}
}