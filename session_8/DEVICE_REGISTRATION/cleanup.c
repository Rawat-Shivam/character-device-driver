#include"headers.h"
#include"declarations.h"

/* 
 * clean up always execute from down to up 
 */

static void __exit exit_func(void)
{
	int i;	
	printk(KERN_INFO "START: #%s #%s \n",__FILE__,__func__);

	kfree(dev);
	for(i=0; i< nod ; i++)
	{	
	
		cdev_del(&dev[i].c_dev);
	}
	unregister_chrdev_region(device_id,nod);
//	unregister_chrdev(major_No,"CDD__005");
	
	printk(KERN_INFO "bye...         KERNEL\n");
	printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
}

module_exit(exit_func);
