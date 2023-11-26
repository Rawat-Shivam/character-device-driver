#include"headers.h"

static void __exit exit_func(void)
{
	printk(KERN_INFO "nikal ........pheli fursat mei nikal. koi jarurat nahi teri .nikal\n");
}

module_exit(exit_func);
