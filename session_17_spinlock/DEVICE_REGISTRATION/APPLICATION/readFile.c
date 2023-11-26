#include"headers.h"
#include"declarations.h"
//the below protoype is changed for threads
//int readFile(int fd)
void readFile(void *arg)
{
	int ret;

int *retval;

	char buffer[10];
	int fd=*(int*)arg;

	printf("BEGIN: %s, %s -- FD=%d THREAD=%d \n \n",__FILE__,__func__,fd,pthread_self() );

// we commented lseek just for not using it in threads	
// and synchronization 
//	ret=lseek( fd , 5 , SEEK_END );
//	if(ret==-1)
//	{
//		perror("lseek");
//		exit(EXIT_FAILURE);
//	}
//	printf("lseek returned %d \n",ret);
	
	ret=read(fd, buffer , 5);
	if(ret==-1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("SUCCESS :: read %d bytes from fd: %d \n \n",ret,fd);

	printf("END: %s, %s THREAD=%d\n",__FILE__,__func__,pthread_self());
//return 0;

pthread_exit((void*)retval);

}
