#include"headers.h"
#include"declarations.h"

int validIOCheck(struct file *local_filep, const char __user* ubuff, size_t size )
{

	Dev *localDev=NULL;
	int local_major;
	localDev= (Dev*)local_filep->private_data;
	
	
	printk(KERN_INFO "START: #%s #%s \n",__FILE__,__func__);

	local_major= MAJOR(localDev->c_dev.dev);
	if(!(local_major >0 && local_major <256))
	{
		printk(KERN_ERR "ERROR: invalid major number");
		return 0;
	}

	printk(KERN_INFO "major number is %d \n",local_major);
	if( ubuff == NULL)
	{
		printk(KERN_ERR "ERROR: invalid buffer");
		return 0;
	}	
	if(size < 0)
	{		
		printk(KERN_ERR "ERROR: invalid size");
		return 0;
	}

return 1;
}
