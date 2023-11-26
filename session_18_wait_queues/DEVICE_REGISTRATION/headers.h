#include<linux/init.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/moduleparam.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/wait.h>// used earlier ,but also used for waitQueue-BLOCKING_IO
#include<linux/sched.h> // we used it for TASK_INTERRUPTIBLE macro


MODULE_LICENSE("GPL");
MODULE_AUTHOR("__RAWAT_SHIVAM__");
MODULE_DESCRIPTION("__character_device_driver_for_SCULL__");

