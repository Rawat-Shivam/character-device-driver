#ifndef TASK_INTERRUPTIBLE
#define TASK_INTERRUPTIBLE
#endif

// this below is a macro which is a function
// #define init_waitqueue_head(myQueue)



#ifndef DEBUG
#define DEBUG
#endif

//this NOD=0  macro was used earlier to to have pre-user-defined no_of_devices
//but not used now since we are have no_of_devices as module_parameters(during runtime)
#ifndef NOD
#define NOD 
#endif

#ifndef MINOR_NO
#define MINOR_NO 0
#endif

#ifndef DEVICE_NAME
#define DEVICE_NAME "CDD__005"  
#endif

#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEVSIZE
#define DEVSIZE 256
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

#ifndef REGSIZE
#define REGSIZE 4
#endif

#ifndef NOOFREG
#define NOOFREG 8
#endif

extern int major_No,minor_No,nod;
extern dev_t device_id,dev_no;

extern int dataSize,devSize,regSize,noOfReg;

typedef struct qset
{
	struct qset *next;
	void **data;

}Qset;

typedef struct 
{
	struct qset *first;
	struct cdev c_dev;
	int dataSize;
	int devSize;
	int regSize;
	int noOfReg;
	
	// a macfo defined above to do interruptible events ie.. TASK_INTERRUPTIBLE
	wait_queue_head_t myQueue;//here declared a variable of wait_queue_head_t ( typedef wait_queue_t )	

	// in wait queue lets say many reader start reading
	// but in driver code we have given condition and due to its false state
	// they will wait in waitQueue
	//
	// now writer will come and write and make the condition true
	// so the **only one**	 reader will move ahead and other will wait.
	// till the other writer comes and makes the conditon true 
	// so the next one reader reads.

}Dev;
extern Dev *dev;

/******** IMPORTANT ************
 
int (*open) (struct inode *, struct file *);
	// here this  (*open) is a function pointer 
	// in funOps.h file we are pointing a user defined  function " openMyDev " to the 
	// kernel defined function_pointer " (*open) "
	// and below is that function,which is a pointer to that (*open)						
	//
	//	open: openMyDev    
	//

int (*release) (struct inode *, struct file *);
	// just same as above a user defined function " releaseMyDev " which is 
	// pointing to a kernel defined function_pointer " (*release) "
	//
	//	release: releaseMyDev
	//
**********************************/

int openMyDev (struct inode *, struct file *);
int releaseMyDev (struct inode *, struct file *);
int trimDev(Dev*);
Qset*  creatScull ( size_t size);
//ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
//ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);

ssize_t readMyDev (struct file *, char __user *, size_t, loff_t *);
ssize_t writeMyDev (struct file *, const char __user *, size_t, loff_t *);

int  validIOCheck (struct file *, const char __user *, size_t);

//loff_t (*llseek) (struct file *, loff_t, int);
loff_t lseekDev (struct file *, loff_t, int);

