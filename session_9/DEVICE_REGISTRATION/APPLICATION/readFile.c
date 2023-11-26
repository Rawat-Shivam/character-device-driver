#include"headers.h"
#include"declarations.h"

int readFile(int fd)
{
	int ret;
	char buffer[1000];

	printf("BEGIN: %s, %s\n",__FILE__,__func__);

	ret=read(fd,buffer,1000);
	if(ret==-1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("SUCCESS :: read %d bytes from fd: %d",ret,fd);

	printf("END: %s, %s\n",__FILE__,__func__);
return 0;
}
