#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int device_open(struct inode *pinode, struct file *fp);


struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_release
};


static int hello_init(void){
	printk(KERN_ALERT "Hello World! from %s\n",__func__);
	return 0;
}

static void hello_exit(void){
	printk(KERN_ALERT "Good Bye! %s\n",__func__);
}


module_init(hello_init);
module_exit(hello_exit);


MODULE_AUTHOR("Jyothirmai");
MODULE_DESCRIPTION("alias Gudur Bidda");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
:wqi
