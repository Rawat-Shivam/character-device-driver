#include"headers.h"
#include"declarations.h"


int openMyDev (struct inode *inode_p, struct file *file_p)
{
	int ret;
	Dev *localDev;
	// this localDev will store the adderess  of user defined structure Dev (inside declerarion.h)
	// returned by container_of
	// and this pointer can address the // IO_space / KERNEL_space / USER_space //
	
	printk(KERN_INFO "%s: BEGIN\n",__func__);
	
	

/*************************** container_of *********************
 * - cast a member of a structure out to the containing structure
 *
 * @ptr:        the pointer to the member in the struct
 * @type:       the type of the container struct this is embedded in
 * 		 (it is the data type ,the structure itself whose address will it return)
 * @member:     the name of the member within the struct.
 *
 * **************************************************************/
	
/************************************************************************
 
        #define container_of(ptr, type, member) ({                              \
        void *__mptr = (void *)(ptr);                                   \
        BUILD_BUG_ON_MSG(!__same_type(*(ptr), ((type *)0)->member) &&   \
                         !__same_type(*(ptr), void),                    \
                         "pointer type mismatch in container_of()");    \
        ((type *)(__mptr - offsetof(type, member))); })

* ***********************************************************************/
	localDev = container_of(inode_p->i_cdev, Dev, c_dev);
	if(!localDev)
	{
		printk(KERN_ERR "container_of is failed \n");
		goto OUT;
	}


	file_p->private_data=(void*)localDev;

// inode_p is user created pointer to the kernel structure inode . now this pointer will point to the member of kernel struct inode
/********************* Remember***************************************
 * 
 * struct file {};
 * is a structure in fs.h
 * inside it there is a void pointer named private_data
	
 	void                    *private_data;

 * ******************************************************************/

	if((file_p->f_flags & O_ACCMODE)== O_WRONLY)
	{
		
		ret=trimDev(localDev);
		if(ret==-1)
		{
			printk(KERN_ERR "ERROR: trimDev() failure in open() \n ");
			goto OUT;
		}
	}

	
	printk(KERN_INFO "%s: END \n",__func__);

return 0;


OUT:
        {
                printk(KERN_INFO "END: #%s #%s \n",__FILE__,__func__);
                return -1;
        }

}

