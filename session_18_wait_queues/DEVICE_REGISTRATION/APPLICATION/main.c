#include"headers.h"
#include"declarations.h"

int i=0;

int main()
{
	pthread_t readT , writeT;
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	int t_ret, choice , fd ;
	char ch;
	printf("BEGIN:%s;%s\n",__FILE__,__func__);
			
		choice=mainMenu();
		
		fd=openFile();
		
		printf("%s ; %s READ WRITE THREADS __BEGIN__  \n",__FILE__,__func__);
	// in wait queue lets say many reader start reading
	// but in driver code we have given condition and due to its false state
	// they will wait in waitQueue
	//
	// now writer will come and write and make the condition true
	// so the **only one**	 reader will move ahead and other will wait.
	// till the other writer comes and makes the conditon true 
	// so the next one reader reads.
	

/*
*
*		while(i < 1)
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

                }//inner while ends
*
*
*/

	 //but now we will run multiple read
	 //and then we will run writer one by one
	 
/*
 *
 *
 * 	while(i < 3)
	  	{	      
		 	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

                        t_ret = pthread_create(&readT,&attr,(void*)readFile,(void*)&fd);
                        if(t_ret == -1)
                        {
                                perror("pthread create READ");
                                exit(EXIT_FAILURE);
                        }
                        i++;

                }

		i=0;
		while(i < 3)
		{
			printf("-------- make writer run once \n");
			scanf(" %c",ch);
			
			pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
			
			t_ret = pthread_create(&writeT,&attr,(void*)writeFile,(void*)&fd);
			if(t_ret == -1)
			{
				perror("pthread create WRITE");
				exit(EXIT_FAILURE);
			}

			i++;

		}

*
*
*/

//now whata has happened 
//the reader reads first and the file_pos is zero  
//the writer comes and writes and make file_pos at end 
//so the reader after wake up reads and 
//start reading from end and it finds ... null or bad refrence /null pointer
//
//
//so we will have to do something in read that it reads from correct pos by chaining something somethng
//and we can do something in write also
//
//



//
//but now 		
//we can do one thing that only one open read write 
//and then close
//
//and again open read /write
//
		
                        t_ret = pthread_create(&readT,&attr,(void*)readFile,(void*)&fd);
			sleep(5);
                        t_ret = pthread_create(&writeT,&attr,(void*)writeFile,(void*)&fd);
			sleep(10);
closeFile(fd);
		fd=openFile();
                        
			t_ret = pthread_create(&readT,&attr,(void*)readFile,(void*)&fd);
			sleep(5);
                        t_ret = pthread_create(&writeT,&attr,(void*)writeFile,(void*)&fd);
			sleep(10);
closeFile(fd);
		
		/*switch(choice)
		{
			case 1: 
				fd=openFile();
				break;
			case 2: 
				closeFile(fd);
				fd=-1;
				break;
			//
			 * now these read write will be called by threads 
			 * 
			 * case 3: 
				writeFile(fd);
				break;
			case 4: 
				readFile(fd);
				break;
			*
			case 0: 
				printf("END:%s;%s\n",__FILE__,__func__);
				exit(EXIT_FAILURE);
			default: 
				printf("INVALID CHOICE\n");
		}*/
		
		printf("%s ; %s READ WRITE THREADS __END__  \n",__FILE__,__func__);
		
closeFile(fd);

	
	
	printf("END:%s;%s\n",__FILE__,__func__);
//return 0;
exit(0);
}
