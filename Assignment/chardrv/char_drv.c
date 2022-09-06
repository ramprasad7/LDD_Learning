#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

int major;

int device_open(struct inode *pinode, struct file *fp){
	printk("Device has been opened\n");
	return 0;
}


ssize_t device_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset){

	if(copy_to_user(buffer,device_buffer,length)){
		printk("writing failed\n");
		return -1;
	}
	else{
		printk("writing to user success <%s>\n",device_buffer);
	}	
	printk("Device requested for read for %ld number of bytes\n",length);
	
	return len;
}

ssize_t device_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){

	if(copy_from_user(device_buffer,buffer,length)){
		printk("failed to write\n");
		return -1;
	}
	else{
		printk("copying from user success with <%s>\n",buffer);
	}

	printk("Device requested for write for %ld number of bytes\n",length);
	return length;
}


int device_release(struct inode *pinode,struct file *fp){
	printk("Device has been closed\n");
	return 0;
}

struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_release
};


static int hello_init(void){
	printk(KERN_ALERT "Hello World! from %s\n",__func__);
	major = register_chrdev_region(0,1,"Example_Driver");
	if(major < 0){
		printk("Failed to register device\n");
	}else{
		printf("Major Number: %d\n",major);
	}
	return 0;
}

static void hello_exit(void){
	unregister_chrdev_region(major,1);
	printk(KERN_ALERT "Good Bye! %s\n",__func__);
}


module_init(hello_init);
module_exit(hello_exit);


MODULE_AUTHOR("Example User");
MODULE_DESCRIPTION("Example Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
