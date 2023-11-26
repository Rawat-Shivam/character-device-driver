#include"headers.h"
#include"declarations.h"


int trimDev(Dev *localDev )
{
	
	int i=0 ,j=0 ;
	Qset *first_item, *last_item , *s_last_item;

	printk(KERN_INFO "%s: BEGIN \n",__func__);

	if(!localDev) // if null
	{
		printk(KERN_INFO "ERROR :localDev not found" );
		goto OUT;
	}
	
	if(!localDev->first)	// struct Qset *first, inside user-defined structure is a field  
	{
		printk(KERN_INFO "ERROR :localDev->first not found" );
		//goto OUT;
		return 0;
	}
	
	first_item = last_item = s_last_item = localDev->first;

	
	while( first_item->next || first_item->data!=NULL )
	{
		printk(KERN_INFO "............ outer while " );
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		while(last_item->next)
		{	
			printk(KERN_INFO "............ inner  while %d",j++ );
			s_last_item = last_item;
			last_item = last_item->next;
		}	
		
		if(last_item->data)
		{
			for(i = noOfReg-1 ; i >= 0 ; i-- )
			{
				printk(KERN_INFO "............ FOR loop %d ",i);
				
				if(last_item->data[i])
				{
					kfree(last_item->data[i]);
					last_item->data[i]=NULL;// null because ....it may become dangling pointer
				}
				
			
			}
				kfree(last_item->data);
				last_item->data=NULL;
		
		}
		
		kfree(last_item);
		last_item=NULL;

		if(s_last_item->next != NULL )
			s_last_item->next=NULL;
	
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		last_item=first_item;
	}
	
	localDev->first=NULL;
	printk(KERN_INFO "%s: END \n",__func__);

return 0;

OUT:
		printk(KERN_ERR " ERROR :%s: \n",__func__);
		return -1;

}

