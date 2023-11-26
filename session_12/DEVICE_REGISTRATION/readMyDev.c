#include"headers.h"
#include"declarations.h"


ssize_t readMyDev ( struct file *file_localp, char __user *ubuff,size_t size,loff_t *lofset)
{
	size_t local_size = 0;
        Dev *localDev;
        int i=0;
        int ctr=0;      //no_of_char_to_read = 0;
        int ur=0;        //no_of_unsuccess_read = 0;
        int csr=0;      //no_of_char_successfully_read =0;
        Qset *item ;
        item = NULL;
        localDev=NULL;
        
	printk(KERN_INFO "%s: BEGIN \n",__func__);

        localDev=(Dev*)file_localp->private_data;

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
	}

                item = localDev->first;
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

                        ur /*no_of_unsuccess_read*/ = copy_to_user( (ubuff+csr) , item->data[i] , ctr /*no_of_char_to_read*/);
                        if(ur /*no_of_unsuccess_read*/ > 0)
                        {
                                printk(KERN_INFO " PARTIAL_READ \n");
                        }

                        csr/*no_of_char_successfully_read*/ =csr /* no_of_char_successfully_read*/ + ( ctr /*no_of_char_to_read*/ - ur /*no_of_unsuccess_read*/ );
                        local_size = local_size - (ctr /*no_of_char_to_read*/ - ur /* no_of_unsuccess_read*/);
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
       


        printk(KERN_INFO "%s: END \n",__func__);

return csr;

}

