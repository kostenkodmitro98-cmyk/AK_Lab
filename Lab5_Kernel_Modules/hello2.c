// SPDX-License-Identifier: BSD-4-Clause

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/errno.h>

#include "hello1.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello2 kernel module");

static unsigned int repeat_count = 1;

module_param(repeat_count, uint, 0444);
MODULE_PARM_DESC(repeat_count, "Number of Hello, world! messages");

static int __init hello2_init(void)
{
	unsigned int i;
	int ret;

	if (repeat_count > 10) {
		pr_err("Invalid repeat_count: %u (maximum 10)\n",
		       repeat_count);
		return -EINVAL;
	}

	if (repeat_count == 0 ||
	    (repeat_count >= 5 && repeat_count <= 10))
		pr_warn("Warning: repeat_count = %u\n", repeat_count);

	for (i = 0; i < repeat_count; i++) {
		ret = print_hello();

		if (ret)
			return ret;
	}

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Hello2 module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

