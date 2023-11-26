
extern int major_No,minor_No,nod;
extern int dev_no;
extern dev_t device_id;

typedef struct qset
{
	struct qset *next;
	void **data;

}Qset;

typedef struct 
{
	struct qset *first;
	struct cdev c_dev;
}Dev;
extern Dev *dev;
