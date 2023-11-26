#include"headers.h"
#include"declarations.h"


//long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
long ioctlDev (struct file *file_localp, unsigned int CMD , unsigned long arg/*flag*/)
{
	
	
	Dev *localDev;

	printk(KERN_INFO "%s: BEGIN \n",__func__);
	localDev=(Dev*)file_localp->private_data;
	switch( CMD )
	{
		case RESET:
				devSize=localDev->devSize=DEVSIZE;//256
				dataSize=localDev->dataSize=DATASIZE;//0
				regSize=localDev->regSize=REGSIZE;//4
				noOfReg=localDev->noOfReg=NOOFREG;//8			
				
				printk(KERN_INFO "RESET done..........\n");
			break;
		
		case GET_DEV:
				put_user(localDev->noOfReg,(int __user*)arg[0]);
				put_user(localDev->,(int __user*)arg[0]);
				put_user(localDev->regSize,(int __user*)arg[0]);
				put_user(localDev->noOfReg,(int __user*)arg[0]);
				
				
		
		
		
		
	}

	
	
	
	
	
	

	printk(KERN_INFO "%s: END \n",__func__);

return 0;
}

