#include"headers.h"
#include"declarations.h"

int writeFile(int fd)
{
	int ret;
	char buffer[63]="hi babes . kasi hai. hi babes . kasi hai. hi babes . kasi hai.";

	printf("BEGIN: %s, %s \n",__FILE__,__func__);
		
	ret=write(fd,buffer,63);
	if(ret==-1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}	
	printf("SUCCESS :: wrote %d bytes in fd: %d \n",ret,fd);
	
	printf("END: %s, %s \n",__FILE__,__func__);
return 0;
}
