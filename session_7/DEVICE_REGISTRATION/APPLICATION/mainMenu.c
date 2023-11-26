#include"headers.h"
#include"declarations.h"

int mainMenu()
{
	printf("BEGIN:%s;%s\n",__FILE__,__func__);
	
	int choice;

	printf("select the choices \n");
	
	printf("1. open device \n");
	printf("2. close device \n");
	printf("0. EXIT SUCCESSFULLY \n");
	scanf(" %d", &choice);
	printf("END:%s;%s\n",__FILE__,__func__);

return choice;
}
