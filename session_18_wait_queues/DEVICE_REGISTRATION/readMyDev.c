#include"headers.h"
#include"declarations.h"


ssize_t readMyDev ( struct file *file_localp, char __user *ubuff,size_t size,loff_t *lofset)
{
	size_t local_size = 0;
        Dev *localDev;
        int i=0 ;
        int ctr=0;      //no_of_char_to_read = 0;
        int ur=0;        //no_of_unsuccess_read = 0;
        int csr=0;      //no_of_char_successfully_read =0;
        Qset *item ;
        item = NULL;
        localDev=NULL;
      

	printk(KERN_INFO "%s: BEGIN \n",__func__);
	
	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "lofset = %d \n",*(int*)lofset);

	localDev=(Dev*)file_localp->private_data;
	item = localDev->first;
	
	printk(KERN_INFO "----------++++++++++++ datasize = %d \n",localDev->dataSize );
	wait_event_interruptible( localDev->myQueue, ( localDev->dataSize > 0) );

	printk(KERN_INFO "------------------------------lofset = %d \n",*(int*)lofset);
        if(validIOCheck( file_localp, ubuff, size))
        {
                if( size > localDev->dataSize )
                {
                        local_size = ctr /*no_of_char_to_read*/ = dataSize;
                }
                else
                {
                        local_size = ctr /*no_of_char_to_read*/ = size;
                }
                
		while( local_size > 0 )
                {

                        if(local_size > regSize )
                        {
                                ctr /*no_of_char_to_read*/ = regSize;
                        }
                        else
                        {
                                ctr /*no_of_char_to_read*/ = local_size;

                        }

                        ur = copy_to_user( (ubuff+csr) , item->data[i] , ctr /*no_of_char_to_read*/);
                        if(ur /*no_of_unsuccess_read*/ > 0)
                        {
                                printk(KERN_INFO " PARTIAL_READ \n");
                        }
                	printk(KERN_INFO " success read :  .......... read : %s\n", (ubuff+csr));

                        *lofset = csr =csr+ ( ctr- ur ) ;
                        local_size = local_size - (ctr - ur) ;
                  	printk(KERN_INFO " success read : %d \n",csr /* no_of_char_successfully_read*/);

                        if(i == noOfReg -1)
                        {
                                item = item->next;

                                i=0;
                        }
                        else
                        {
                                i++;
                        }

                }
	}

	file_localp->f_pos = *lofset;

	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "lofset = %d \n",*(int*)lofset);

        printk(KERN_INFO "%s: END \n",__func__);

return csr;

}

