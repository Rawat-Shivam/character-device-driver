#include"headers.h"
#include"declarations.h"

// this prototype is changed for thread 
//int writeFile(int fd)

void writeFile(void *arg)
{
	int ret;
	int fd=*(int*)arg;

int *retval;

	char buffer[35]="tu mil mere ko kal 11 baje raat ko";

	printf("BEGIN: %s, %s -- FD=%d   THREAD=%d \n\n",__FILE__,__func__,fd, pthread_self() );
		
	ret=write(fd,buffer,35);
	if(ret==-1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}	
	printf("SUCCESS :: wrote %d bytes in fd: %d \n\n",ret,fd);
	
	printf("END: %s, %s THREAD=%d \n",__FILE__,__func__,pthread_self());
//return 0;
pthread_exit((void*)retval);

}
