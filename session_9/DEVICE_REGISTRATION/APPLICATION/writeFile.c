#include"headers.h"
#include"declarations.h"

int writeFile(int fd)
{
	int ret;
	char buffer[1000]="This String Will Be Written In ,From The Application(user_space) ....................................................................................................................";

	printf("BEGIN: %s, %s\n",__FILE__,__func__);
		
	ret=write(fd,buffer,1000);
	if(ret==-1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}	
	printf("SUCCESS :: wrote %d bytes in fd: %d \n",ret,fd);
	
	printf("END: %s, %s\n",__FILE__,__func__);
return 0;
}
