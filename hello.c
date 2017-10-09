#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>



static int hello_init(void)
{
	printk(KERN_ALERT "i bear a hello world.\n");
	return 0;
}




static void hello_exit(void)
{
	printk(KERN_ALERT "out out.\n");
	return 0;
}


module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
