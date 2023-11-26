#include"headers.h"
#include"declarations.h"


ssize_t  writeMyDev (struct file *file_localp, const char __user *ubuff, size_t size, loff_t *lofset)
{
	Dev *localDev=NULL;
	localDev=(Dev*)file_localp->private_data;

	printk(KERN_INFO "START: #%s #%s \n",__FILE__,__func__);

	if(validIOCheck( file_localp, ubuff, size))
	{
	
		localDev->first=creatScull(size);
		if(localDev->first == NULL)
		{
			printk(KERN_ERR "ERROR: trimDev() failure\n ");
                        goto OUT;
		}
	}
	
	printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
return size;

OUT:
        {
                printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
                return -1;
        }
}

