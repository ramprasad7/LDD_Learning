#include<MAX.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#include<linux/slab.h>
#include<linux/uaccess.h>

#define MAX 512

char device_buffer[MAX];

/* this device number */
dev_t device_number;

/* cdev struct variable */
struct cdev cdp_cdev;

/* class struct pointer */
struct class *class_cdp;

/* device struct pointer */
struct device *cdp_device;



int device_open(struct inode *pinode, struct file *pfile){

	printk("device opened\n");	
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

	return 0;
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


int device_release(struct inode *pinode, struct file *pfile){


	printk("Device closed\n");
	return 0;
}



struct file_operations fops = { 
	.read = device_read, 
	.write = device_write, 
	.open = device_open, 
	.release = device_release 
};


static int __init cdp_init(void){
	int err = alloc_chrdev_region(&device_number,0,1,"cdp");
	if(err==0){
		printk("Device number <major>:<minor> = %d:%d\n",MAJOR(device_number),MINOR(device_number));

		cdev_init(&cdp_cdev,&fops);

		cdp_cdev.owner = THIS_MODULE;

		cdev_add(&cdp_cdev,device_number,1);

		class_cdp = class_create(THIS_MODULE,"cdp_class");

		cdp_device = device_create(class_cdp,NULL,device_number,NULL,"cdp"); /* this name appears in /dev/filename */
	}
	else{
		printk("failed to allocate region\n");
	}

	printk("Module loaded sucessfully\n");
	return 0;
}


static void __exit cdp_cleanup(void){

	device_destroy(class_cdp,device_number);

	class_destroy(class_cdp);

	cdev_del(&cdp_cdev);

	unregister_chrdev_region(device_number,1);

	printk("Module removed successfully\n");
}


MODULE_AUTHOR("Ram");
MODULE_DESCRIPTION("Character Device Driver");
MODULE_LICENSE("GPL");



module_init(cdp_init);
module_exit(cdp_cleanup);

