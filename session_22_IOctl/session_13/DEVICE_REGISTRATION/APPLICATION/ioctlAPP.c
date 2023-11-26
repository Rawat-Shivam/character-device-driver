#include"headers.h"
#include"declarations.h"

int ioctlAPP(int fd)
{

	int choice ,ret;
	
	printf("BEGIN:%s\n",__func__);

	printf("-------- IOCTL MENU --------\n");
	
	printf("1: RESET \n");
	
	printf("2: GET DEVICE INFO \n");
	printf("3: SET regSize\n");
	printf("4: SET noOfReg\n");
	printf("5: SET dataSize\n");
	printf("6: SET devSize\n");
	
	scanf(" %d",&choice);

	switch(choice)
	{
		case 1:
			ret=ioctl(fd , RESET);
			if(ret==-1)
			{
				perror("ioctl");
				exit(EXIT_FAILURE);
			}
			break;

		case 2:
			int arg[4];
			ret=ioctl(fd, GET_DEV ,arg);
			if(ret==-1)
			{
				perror("ioctl");
				exit(EXIT_FAILURE);
			}
			printf("DEVICE INFO :noOfReg=%d, regSize=%d, dataSize=%d, devSize=%d \n ",arg[],arg[1],arg[2],arg[3]);
			break;
	
	
	
	}
	
	printf("END:%s\n",__func__);

}

