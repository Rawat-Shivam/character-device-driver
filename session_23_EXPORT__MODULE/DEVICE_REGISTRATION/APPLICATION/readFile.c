#include"headers.h"
#include"declarations.h"

int readFile(int fd)
{
	int ret;
	char buffer[10];

	printf("BEGIN: %s, %s\n",__FILE__,__func__);
	
	ret=lseek( fd , 5 , SEEK_END );
	if(ret==-1)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("lseek returned %d \n",ret);
	
	ret=read(fd, buffer , 5);
	if(ret==-1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("SUCCESS :: read %d bytes from fd: %d \n",ret,fd);

	printf("END: %s, %s\n",__FILE__,__func__);
return 0;
}
