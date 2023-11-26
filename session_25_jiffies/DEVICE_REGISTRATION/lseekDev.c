#include"headers.h"
#include"declarations.h"

//	loff_t (*llseek) (struct file *, loff_t, int);
loff_t lseekDev (struct file *file_localp , loff_t size, int origin )
{
	loff_t ret;
	printk(KERN_INFO "%s: BEGIN \n",__func__);
	
	
	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "loff = %d \n",(int)size);


	switch(origin)
	{
		case SEEK_SET:
				printk(KERN_INFO "SEEK_SET: BEGIN \n");
				
				if( size > dataSize )
				{
		                        printk(KERN_ERR "ERROR: SEEK_SET failure\n ");
		                        goto OUT;
				}
				file_localp->f_pos = size;

					
				printk(KERN_INFO "SEEK_SET: END \n");
				
				break;
		case SEEK_CUR:
				printk(KERN_INFO "SEEK_CUR: BEGIN \n");
				
				if( (( file_localp->f_pos + size )  < 0 ) && (( file_localp->f_pos + size ) > dataSize ))
				{
		                        printk(KERN_ERR "ERROR: SEEK_CUR failure\n ");
		                        goto OUT;
				}	
				
				
				file_localp->f_pos += size;
					
				printk(KERN_INFO "SEEK_CUR: END \n");
				

				break;
		case SEEK_END:
				printk(KERN_INFO "SEEK_END: BEGIN \n");
				
				if( (size > dataSize) || (size < 0) )
				{
		                        printk(KERN_ERR "ERROR: SEEK_END failure\n ");
		                        goto OUT;
				}
				file_localp->f_pos = dataSize - size;
				
				printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
					
				printk(KERN_INFO "SEEK_END: END \n");

				break;
				
		default:
			printk("___ invalid flag ___  \n");
	
	}
	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	ret=(loff_t)file_localp->f_pos;
	printk(KERN_INFO "%s: END \n",__func__);

return ret;

OUT:
        {
                printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
                return -1;
        }

}

