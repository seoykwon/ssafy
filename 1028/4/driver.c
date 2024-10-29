#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int __init driver_init(void)
{
    pr_info("[Seoyoung Kwon] Hello Kernel\n");
    return 0;
}

static void __exit driver_exit(void)
{
    pr_info("[SSAFY embedded] Good Bye Kernel\n");
}

module_init(driver_init);
module_exit(driver_exit);
