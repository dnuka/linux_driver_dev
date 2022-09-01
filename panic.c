#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init cause_panic(void)
{
    panic("Forced panic");
    return 0;
}

static void __exit quit(void)
{
    printk(KERN_ALERT "Bye!\n");
}

module_init(cause_panic);
module_exit(quit);
