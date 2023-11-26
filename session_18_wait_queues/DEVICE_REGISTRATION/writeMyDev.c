#include"headers.h"
#include"declarations.h"


ssize_t  writeMyDev (struct file *file_localp, const char __user *ubuff, size_t size, loff_t *lofset)
{
	size_t local_size = 0;

	Dev *localDev;
	int i=0;
	int ctw=0;	//no_of_char_to_write = 0;
	int uc=0;	//no_of_unsuccess_char = 0;
	int csw=0;	//no_of_char_successfully_wrote =0;
	Qset *item ;
	item = NULL;
	localDev=NULL;


	printk(KERN_INFO "%s: BEGIN \n",__func__);
	
	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "lofset = %d \n",*(int*)lofset);

	localDev=(Dev*)file_localp->private_data;

	if(validIOCheck( file_localp, ubuff, size))
	{
		if( size > devSize )
		{
			local_size = ctw /*no_of_char_to_write*/ = devSize;
		}
		else
		{
			local_size = ctw /*no_of_char_to_write*/ = size;
		}

		localDev->first = creatScull(local_size);
		if(localDev->first == NULL)
		{
			printk(KERN_ERR "ERROR: creatScull() failure\n ");
                        goto OUT;
		}
		item = localDev->first;
		
		while( local_size > 0 )
		{
		
			if(local_size > regSize )
			{
				ctw /*no_of_char_to_write*/ = regSize;
			}
			else
			{
				ctw /*no_of_char_to_write*/ = local_size;

			}


		//		printk(KERN_INFO " local_size: %ld \n",local_size);
			
			uc /*no_of_unsuccess_char*/ = copy_from_user( item->data[i] , ( ubuff + csw ) , ctw /*no_of_char_to_write*/);
			if(uc /*no_of_unsuccess_char*/ > 0 )
			{
				printk(KERN_INFO " PARTIAL_WRITE \n");
			}
			
		
			printk(KERN_INFO " likh liya : %s  \n",(char*)item->data[i]);
		//	printk(KERN_INFO " unsuccess char : %d  \n", uc /*no_of_unsuccess_char*/);
			
			*lofset = dataSize = csw/*no_of_char_successfully_wrote*/ =csw /* no_of_char_successfully_wrote*/ + ( ctw /*no_of_char_to_write*/ - uc /*no_of_unsuccess_char*/ );
			local_size = local_size - (ctw /*no_of_char_to_write*/ - uc /* no_of_unsuccess_char*/);
 			//ubuff+=no_of_char_successfully_wrote;
		//	printk(KERN_INFO " success char : %d \n",csw /* no_of_char_successfully_wrote*/);
			
			if(i == noOfReg -1)
			{
				item = item->next;

				i=0;
			//printk(KERN_INFO " IIIIIIIIIIIIIIIIIIIIIII  \n");
			}
			else
			{
				i++;
			//printk(KERN_INFO "iiiiiiiiiiiiiiiiiiii: i=%d \n",i);
			}
		
		}
	}
	

	localDev->dataSize = dataSize;
	file_localp->f_pos = *lofset;
	
	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "lofset = %d \n",*(int*)lofset);
	printk(KERN_INFO "%s:END \n",__func__);
	
	wake_up_interruptible(&localDev->myQueue);
	
return  csw /*no_of_char_successfully_wrote*/;

OUT:
        {
                printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
                return -1;
        }
}

