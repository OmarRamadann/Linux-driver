#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
static int __init  my_init(void) //__init:is just a macro to help in searching for init in large code
{
	printk("heelo kernel!\n");
	return 0;
}
static void __exit my_exit (void) //__exit: same concept as __init.
{
	printk("hello - Goodbye!\n");
}

module_init (my_init); //those are like keywords that tell the module where are its start and end funcs.
module_exit(my_exit);
MODULE_LICENSE("GPL"); //some metadata.
MODULE_AUTHOR("Omar");
MODULE_DESCRIPTION("HIIIII");
MODULE_VERSION("1.0.0");
