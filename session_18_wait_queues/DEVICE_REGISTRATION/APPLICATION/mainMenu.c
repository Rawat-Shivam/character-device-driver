#include"headers.h"
#include"declarations.h"

int mainMenu()
{
	printf("BEGIN:%s;%s\n",__FILE__,__func__);
	
	int choice;

	printf("select the choices \n");
	
	printf("1. open device \n");
	printf("2. close device \n");
	//we have commented this to use spinlock(semaphores) 
	//these will be called by threads
//	printf("3. write in  device \n");
//	printf("4. read from device \n");
	printf("0. EXIT SUCCESSFULLY \n");
	
	scanf(" %d", &choice);
	printf("END:%s;%s\n",__FILE__,__func__);

return choice;
}
