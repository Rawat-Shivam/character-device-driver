#include"headers.h"
#include"declarations.h"

int closeFile(int fd)
{
	printf("BEGIN: %s, %s\n",__FILE__,__func__);

	close(fd);	

	printf("END: %s, %s\n",__FILE__,__func__);
return 0;
}
