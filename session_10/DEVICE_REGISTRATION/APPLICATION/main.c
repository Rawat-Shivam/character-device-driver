#include"headers.h"
#include"declarations.h"

int main()
{
	printf("BEGIN:%s;%s\n",__FILE__,__func__);
	
	int choice,fd;
	while(1)
	{
		choice=mainMenu();
		switch(choice)
		{
		
			case 1: 
				fd=openFile();
				break;

			case 2: 
				closeFile(fd);
				break;
			case 3: 
				writeFile(fd);
				break;
			
			case 4: 
				readFile(fd);
				break;

			case 0: 
				printf("END:%s;%s\n",__FILE__,__func__);
				exit(EXIT_FAILURE);
		
			default: 
				printf("INVALID CHOICE\n");
				
		}
	
	}
	printf("END:%s;%s\n",__FILE__,__func__);
return 0;
}
