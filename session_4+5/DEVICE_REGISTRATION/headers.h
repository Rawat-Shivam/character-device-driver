#include<linux/init.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/moduleparam.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("__RAWAT__");
MODULE_DESCRIPTION("__character_device_driver_for_SCULL__");

//this NOD macro was used earlier to to have pre-defined no_of_devices
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
