#include"headers.h"
#include"declarations.h"

/* 
 * clean up always execute from down to up 
 */

static void __exit exit_func(void)
{

unsigned long jiff_2;


	int i;	
	printk(KERN_INFO "%s:BEGIN \n",__func__);

	kfree(dev);
	for(i=0; i< nod ; i++)
	{	
	
		cdev_del(&dev[i].c_dev);
	}
	unregister_chrdev_region(device_id,nod);
//	unregister_chrdev(major_No,"CDD__005");
	
	printk(KERN_INFO "bye...         KERNEL\n");


jiff_2=jiffies;

	printk(KERN_INFO "%s: END  %ld\n",__func__,jiff_2);
}

module_exit(exit_func);
