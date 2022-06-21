#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static char *whom = "world";
static int how_many = 1;

module_param(how_many, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init hello(void)
{
    for (int i = 0; i < how_many; i++)
        printk(KERN_ALERT "Hello %s!\n", whom);

    return 0;
}

static void __exit go(void)
{
    printk(KERN_ALERT "Bye %s!\n", whom);
}

module_init(hello);
module_exit(go);
