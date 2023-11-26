#include"headers.h"
#include"declarations.h"


int releaseMyDev (struct inode *inode_p, struct file *file_p)
{
	printk(KERN_INFO "%s: BEGIN \n",__func__);
	printk(KERN_INFO "%s: END \n",__func__);

return 0;
}

