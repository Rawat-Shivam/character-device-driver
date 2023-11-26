#include"headers.h"
#include"declarations.h"


int releaseMyDev (struct inode *inode_p, struct file *file_p)
{
	printk(KERN_INFO "START: #%s #%s \n",__FILE__,__func__);
	printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);

return 0;
}

