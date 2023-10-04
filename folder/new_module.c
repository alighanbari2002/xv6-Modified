#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
    printk(KERN_INFO, " /-----------------------------\\\n | Group Members:              |\n |  - Ali Ghanbari %% 810199473 |\n |  - Behrad Elmi  %% 810199557 |\n |  - Bita Nasiri  %% 810199504 |\n \\-----------------------------/\n\n");
    return 0;
}

void cleanup_module(void) {}
