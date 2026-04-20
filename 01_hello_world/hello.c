#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
static int my_init(void)
{
	printk("heelo kernel!\n");
	return 0;
}
static void my_exit (void)
{
	printk("hello - Goodbye!\n");
}

module_init (my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Omar");
MODULE_DESCRIPTION("HIIIII");
MODULE_VERSION("1.0.0");
