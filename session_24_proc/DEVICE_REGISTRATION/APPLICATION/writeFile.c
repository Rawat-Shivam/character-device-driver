#include"headers.h"
#include"declarations.h"

int writeFile(int fd)
{
	int ret;
	char buffer[35]="tu mil mere ko kal 11 baje raat ko";

	printf("BEGIN: %s, %s \n",__FILE__,__func__);
		
	ret=write(fd,buffer,35);
	if(ret==-1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}	
	printf("SUCCESS :: wrote %d bytes in fd: %d \n",ret,fd);
	
	printf("END: %s, %s \n",__FILE__,__func__);
return 0;
}
