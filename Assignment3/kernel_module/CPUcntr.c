#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alireza Khodamoradi");
MODULE_DESCRIPTION("This module enables users to access performance counter");

static int __init CPUcntr_init(void){
  asm ("MCR p15, 0, %0, c9, c14, 0\n\t" :: "r"(1));
  // disable counter overflow interrupts
  asm ("MCR p15, 0, %0, c9, c14, 2\n\t" :: "r"(0x8000000f));
  printk(KERN_INFO "Vinit: CPU clock counter is enabled.\n");
  return 0;
}

static void __exit CPUcntr_clean(void){
  // disable user-mode access to the performance counter
  asm ("MCR p15, 0, %0, c9, c14, 0\n\t" :: "r"(0));
  printk(KERN_INFO "Vinit: CPU clock counter is disabled.\n");
}

module_init(CPUcntr_init);
module_exit(CPUcntr_clean);

