#include"headers.h"

static int __init start_func(void)
{
	printk(KERN_INFO "dhaaat teri m ki hoot\n");
	return 0;
}

module_init(start_func);
