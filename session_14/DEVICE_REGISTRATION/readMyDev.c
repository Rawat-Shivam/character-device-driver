#include"headers.h"
#include"declarations.h"


ssize_t readMyDev( struct file *file_localp, char __user *ubuff,size_t size,loff_t *lofset)
{
	size_t local_size = 0;
	Dev *localDev = NULL ;
	Qset *item = NULL ;
	int i=0;     // looping variable
	int ctr=0;      //no_of_char_to_read = 0;
	int ur=0;        //no_of_unsuccess_read = 0;
	int csr=0;      //no_of_char_successfully_read =0;
	int wi=0;	// which item
	int wq=0; 	//which quantum
	int biq=0; 	//byte in quantum
	printk(KERN_INFO "%s: BEGIN \n",__func__);


	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "lofset = %d \n",*(int*)lofset);
	printk(KERN_INFO "size (to read from read command) = %ld\n",size);

	localDev=(Dev*)file_localp->private_data;
	if(!localDev)
	{
		printk(KERN_ERR "ERROR: localDev  failure\n ");
		return -1;
	}

	item = localDev->first;
	if(validIOCheck( file_localp, ubuff, size))
	{
		if( size >localDev->dataSize )
		{
			local_size = ctr =localDev->dataSize - *lofset;
			printk(KERN_INFO " inside valid io IF..... local_size = %ld   greater than data size\n",local_size);
		}
		else
		{
			local_size = ctr = size;
			printk(KERN_INFO " ELSE valid io local_size = %ld  when less than data size\n",local_size);
		}
		wi=(*(int*)lofset)/(regSize*noOfReg);
		printk(KERN_INFO " which item=%d \n",wi);
		for(i=0;i<wi;i++)
			item=item->next;

		wq=(*(int*)lofset)/regSize;
		if( wq > (noOfReg -1))
			wq=wq-noOfReg;
		printk(KERN_INFO " which quantum=%d \n",wq);

		biq=(*(int*)lofset) % regSize;
		printk(KERN_INFO " byte in quantum=%d \n",biq);

		i=wq;			

		printk(KERN_INFO " [i=%d] \n",i);

		printk(KERN_INFO "going to while-----> > > \n");

		while( local_size > 0 )
		{	
			printk(KERN_INFO " while received  local_size=%ld \n",local_size);

			if(local_size > regSize )
			{
				ctr  = regSize-biq;
				printk(KERN_INFO "char_to_read =%d equal regSize- biq(%d)\n",ctr,biq);
			}
			else
			{
				ctr = local_size;
			}

			printk(KERN_INFO " going -------------- COPY: \n");
			ur = copy_to_user( (ubuff + csr) , item->data[i]+biq , ctr);
			if(ur > 0)
			{
				printk(KERN_INFO " PARTIAL_READ \n");
			}
			printk(KERN_INFO " success read :  .......... read : %s\n", (ubuff+csr));

			*lofset=  csr = csr + ( ctr - ur );
			local_size = local_size - (ctr - ur );

			printk(KERN_INFO " success read : %d \n",csr );

			if(i == noOfReg -1)
			{
				item = item->next;
				i=0;
			}
			else
			{
				i++;
			}
			biq=0;

		}
	}

	file_localp->f_pos = *lofset;

	printk(KERN_INFO "FILE_POSITION = %d \n",(int)file_localp->f_pos);
	printk(KERN_INFO "lofset = %d \n",*(int*)lofset);

	printk(KERN_INFO "%s: END \n",__func__);

	return csr;

}

