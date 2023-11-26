#include"headers.h"
#include"declarations.h"

/**************************************************************************
 
do not use them since exterm is already defined/intialized in init.c

	extern int major_No,minor_No,nod;
	extern dev_t device_id,dev_no;
	
	extern int dataSize,devSize,regSize,noOfReg;


**************************************************************************/

Qset*  creatScull ( size_t size)
{
	Qset *first=NULL , *last=NULL;

	int no_of_item,i;

	printk(KERN_INFO "START: #%s #%s \n",__FILE__,__func__);
	first=last=(Qset*)kmalloc(sizeof(Qset),GFP_KERNEL);
	if(!first)
	{
		printk(KERN_ERR "kmalloc() failed \n");
		goto OUT;
	}

	no_of_item= (size/( noOfReg * regSize ));
	printk(KERN_INFO " NO.OF ITEMS %d\n",no_of_item);
	
	for( i=0; i< no_of_item -1; i++ )
	{
		last->next=(Qset*)kmalloc(sizeof(Qset),GFP_KERNEL);
		if(!last->next)
		{
                	printk(KERN_ERR "kmalloc() failed \n");
                	goto OUT;
        	}
		last=last->next;
		last->next=NULL;
		last->data=NULL;
	}

	last=first;


	printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
return first;

OUT:
        {
                printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
                return (Qset*)(-1);
        }
}

