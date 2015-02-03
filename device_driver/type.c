#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

static int type_init(void){
	printk("Please type a number\n");
	return 0;
}

static void type_exit(void){
	printk("Bye , you fucker");
}

module_init(type_init);
module_exit(type_exit);