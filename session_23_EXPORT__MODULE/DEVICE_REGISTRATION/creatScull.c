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
	int no_of_items=0;

	int no_of_quantums=0;
	int i=0,l=0;
	
	Qset *first;
	Qset *last;
	first=last=NULL;

	printk(KERN_INFO "%s: BEGIN \n",__func__);

	
	first=last=(Qset*)kmalloc(sizeof(Qset),GFP_KERNEL);
	if(!first)
	{
		printk(KERN_ERR "kmalloc() failed \n");
		goto OUT;
	}
	memset(first ,'\0' ,sizeof(Qset));
/**************************************************************************/
	
	no_of_items= (size/( noOfReg * regSize ));
	if(size % (noOfReg * regSize))
		no_of_items++;

	printk(KERN_INFO " NO.OF ITEMS %d\n",no_of_items);
	
	for( i=0 ; i< (no_of_items -1) ; i++ )
	{
		last->next=(Qset*)kmalloc(sizeof(Qset),GFP_KERNEL); 
		if(!last->next)
		{
                	printk(KERN_ERR "kmalloc() failed \n");
                	goto OUT;
        	}
		memset(last->next,'\0',sizeof(Qset));

		last=last->next;
		last->next=NULL;
		last->data=NULL;
	}
/**************************************************************************/
	last=first;
/**************************************************************************/

	for(i=0 ; i < no_of_items ; i++ )
	{
		last->data=kmalloc((sizeof(char*)*noOfReg),GFP_KERNEL);
		if(!last->data)
                {
                        printk(KERN_ERR "kmalloc() failed \n");
                        goto OUT;
                }
		memset(last->data , '\0', (sizeof(char*)*noOfReg) );
		last=last->next;
	}
	
/**************************************************************************/
	no_of_quantums=size/regSize;
	if(size % regSize )
		no_of_quantums++;

/**************************************************************************/
	last=first;
/**************************************************************************/
	for(l=0 , i=0 ; l < no_of_quantums ; l++)
	{
				printk(KERN_INFO " iteration no :%d >> no_of_quantums loop loop loop -------- 1  \n",l);
	
		last->data[i]=kmalloc((sizeof(char)*regSize),GFP_KERNEL);
		if(!last->data[i])
                {
                        printk(KERN_ERR "kmalloc() failed \n");
                        goto OUT;
                }
		memset(last->data[i],'\0',(sizeof(char)*regSize));
		
		if(i == noOfReg -1)
		{
			i=0;
			last=last->next;
		}
		else
		{
			i++;
		}
	}
/**************************************************************************/
	
				printk(KERN_INFO " after >> no_of_quantums loop loop loop -------- 1 %d  \n", no_of_quantums);

	printk(KERN_INFO "%s: END \n",__func__);
return first;


OUT:
printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
return (Qset*)(-1);

}

