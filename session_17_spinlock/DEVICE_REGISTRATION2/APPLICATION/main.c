#include"headers.h"
#include"declarations.h"

int i=0;

int main()
{
	pthread_t readT , writeT;
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
char a;
int *retval;

	int t_ret, choice , fd ;

	printf("BEGIN:%s;%s\n",__FILE__,__func__);
			
		choice=mainMenu();
		
		fd=openFile();
		
		printf("%s ; %s READ WRITE THREADS __BEGIN__  \n",__FILE__,__func__);
		
		while(i < 3)
		{
			pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
			
			t_ret = pthread_create(&writeT,&attr,(void*)writeFile,(void*)&fd);
			if(t_ret == -1)
			{
				perror("pthread create WRITE");
				exit(EXIT_FAILURE);
			}

			t_ret = pthread_create(&readT,&attr,(void*)readFile,(void*)&fd);
			if(t_ret == -1)
			{
				perror("pthread create READ");
				exit(EXIT_FAILURE);
			}

			i++;
		}

		pthread_join(readT,(void**)retval);
		
		pthread_join(writeT,(void**)retval);


		printf("%s; %s: do you want to close the file (Y/N)\n",__FILE__,__func__);
		scanf(" %c",&a);
		
		if(a=='Y')
			closeFile(fd);

	
	printf("END:%s;%s\n",__FILE__,__func__);
//return 0;
exit(0);
}
