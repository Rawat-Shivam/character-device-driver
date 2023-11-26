#include"headers.h"
#include"declarations.h"
#include"funOps.h"

int dataSize,devSize,regSize,noOfReg;

int major_No,minor_No,nod;

dev_t dev_no;

dev_t device_id;

Dev *dev;

module_param(nod,int,S_IRUGO); 
// module_param (name, type , permissions)
// it is used to accept the arguments in the module  during run time(inserting)...
// just like command like argument 
// called module parameter
//it will take the input from insmod and store in nod(extern_variable_int)

module_param(regSize,int,S_IRUGO); 
module_param(noOfReg,int,S_IRUGO); 

static int __init start_func(void)
{
	int ret,i;
	printk(KERN_INFO "%s: BEGIN \n",__func__);

	dataSize=DATASIZE;
        devSize=DEVSIZE;

	minor_No=MINOR_NO;
	//here the MINOR_NO macro constant 
       	//assigned to minor_NO( extern int variable )

	
//	nod=NOD;
	// earlier it was user defined macro (constant) but now we are taking as module_parameter

	printk(KERN_INFO "hello KERNEL \n");
	
	ret=alloc_chrdev_region(&device_id,minor_No,nod,DEVICE_NAME);//
	if(ret== -1)
	{
		 printk(KERN_ERR " alloc_chrdev_region() is failed \n");
		 goto OUT;
	}

	major_No=MAJOR(device_id);
	//MAJOR is a pre-kernel-defined macro
	//MAJOR() gives major_number_of_device and we are assiging it to
	//major_No (extern variable)
	
	printk(KERN_INFO " major_No= %d \n", major_No);
	
	dev=(Dev*)kmalloc(sizeof(Dev)*nod,GFP_KERNEL);
	if(!dev)
	{
		 printk(KERN_ERR " kmalloc() is failed \n");
		 goto OUT;
	}
	memset(dev,'\0',sizeof(Dev)*nod);

	for(i=0 ; i < nod ; i++)
	{
		dev_no=MKDEV(major_No,i);
		//MKDEV it returns the device_number/id 
		//it combines both major_No and i(minor_number)
		//and returns the device_id

		minor_No=MINOR(dev_no);
		// now we are extracting minor_number form MINOR pre-kernel-defined macro
		//and assiging it to  minor_No(extern int variable)

		printk(KERN_INFO " minor_No= %d \n", minor_No);
      		
		cdev_init(&dev[i].c_dev,&fops);

		ret=cdev_add(&dev[i].c_dev,dev_no,1);		
		if(ret==-1)
		{
			printk(KERN_ERR " cdev_add() is failed \n");
		 	goto OUT;// it will go to OUT: label and return -1(ie.... exit)	
		}

		dev[i].dataSize=dataSize;
		dev[i].devSize=devSize;
		dev[i].regSize=regSize;
		dev[i].noOfReg=noOfReg;
	}
	
//	minor_No=MINOR(device_id);//was used eariler when we were registering only one  device
//	but for multiple devices( nod ) we used above for loop and MKDEV() and then MINOR()


//	printk(KERN_INFO " minor_No= %d \n", minor_No);

/*	major_No =register_chrdev(0,"CDD__005",&fops); //static inline int register_chrdev();
	if(major_No==-1)
	{
		 printk(KERN_ERR " register_chrdev() is failed \n");
		 goto OUT;
	}
*/	
	printk(KERN_INFO "%s: END \n",__func__);
	return 0;

OUT:
	{
		printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
		return -1;
	}

}


module_init(start_func);
