#include"headers.h"
#include"declarations.h"


ssize_t readMyDev ( struct file *file_localp, char __user *ubuff,size_t size,loff_t *lofset)
{
	printk(KERN_INFO "START: #%s #%s \n",__FILE__,__func__);
	printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);

return 0;
}

