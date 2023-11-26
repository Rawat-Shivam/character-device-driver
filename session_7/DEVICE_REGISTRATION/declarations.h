

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
#define DEVSIZE 0
#endif

#ifndef DATASIZE
#define DATASIZE 256
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
