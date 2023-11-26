#include"headers.h"
#include"declarations.h"


ssize_t readMyDev ( struct file *file_localp, char __user *ubuff,size_t size,loff_t *lofset)
{
	printk(KERN_INFO "%s: BEGIN \n",__func__);
	printk(KERN_INFO "%s: END \n",__func__);

return 0;
}

