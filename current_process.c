#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static int __init print_current_process(void)
{
    printk(KERN_INFO "the current process is \"%s\" (pid %i)\n",
            current->comm, current->pid);

    return 0;
}

static void __exit mod_exit(void)
{
    printk(KERN_INFO "the current process here is \"%s\" (pid %i)\n",
            current->comm, current->pid);
    printk(KERN_ALERT "bye!\n");
}

module_init(print_current_process);
module_exit(mod_exit);
