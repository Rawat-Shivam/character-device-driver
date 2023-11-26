#include"headers.h"
#include"declarations.h"

int openFile()
{
	printf("BEGIN:%s;%s\n",__FILE__,__func__);

	int fd;
	char *mode;
	mode=(char*)malloc(sizeof(char)*20);
	if(!mode)
	{
		perror("malloc");
		exit(EXIT_FAILURE);	
	}
	
	printf("give the MODE of opening the device\n");
	scanf(" %s",mode);

	if(strncmp(mode,"O_RDONLY",8)==0)
		fd=open("myDEV", O_RDONLY);
	
	if(strncmp(mode,"O_WRONLY",8)==0)
		fd=open("myDEV", O_WRONLY);
	
	if(strncmp(mode,"O_RDWR",6)==0)
		fd=open("myDEV", O_RDWR);
	
	if(fd==-1)
	{
		perror("open");
		free(mode);
		exit(EXIT_FAILURE);
	}
	printf("fd=%d\n",fd);
	printf("END:%s;%s\n",__FILE__,__func__);

return fd;
}
