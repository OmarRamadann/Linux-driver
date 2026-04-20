#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/gpio/consumer.h> //header file that provides GPIO standard functions

static struct gpio_desc *led, *button;
#define IO_LED 20 //select GPIO20 in RP for the led.
#define IO_BUTTON 21 //select GPIO21 in RP for the push button.
		  
static int my_init(void)
{
	int status;
	led=gpio_to_desc(IO_LED);
	if (!led){
		printk("Error getting pin %i \n",IO_LED);
		return -ENODEV;
	}
	button=gpio_to_desc(IO_BUTTON);
	if (!button){
		printk("Error getting pin %i \n",IO_BUTTON);
		return -ENODEV;
	}
	status=gpiod_direction_output(led,0);
	if (status){
		printk("Error setting pin %i \n",IO_LED);
		return status;
	}
	status=gpiod_direction_input(button);
	if (status){
		printk("Error setting pin %i \n",IO_BUTTON);
		return status;
	}

	
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
