 1                               44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/slab.h>


int major;
#define DEVICE_NAME "example_char_device"
//unsigned char  *ptr;
char x;
int device_open(struct inode *pinode, struct file *pfile){
	printk("%s function is called\n",__func__);
	return 0;
}

ssize_t device_read(struct file *pfile,char __user *buff, size_t length, loff_t *offset){
	printk("%s function is called\n",__func__);
	/*	if(copy_to_user(buff,ptr,length)){
		printk("copying failed\n");	
		return -1;
		}
		*/
	if(put_user(x,buff) != 0){
		printk("Failed to send data\n");
	}
	else{
		printk("copying from user is success with %s\n",buff);
	}
	/*	kfree(ptr); */
	return 0;
}

ssize_t device_write(struct file *pfile,const char __user *buff, size_t length, loff_t *offset){
	printk("%s function is called\n",__func__);
	//	ptr = kzalloc(length,GFP_KERNEL);
	/*if(ptr == NULL){
	  printk("mem allocation failed\n");
	  }
	  else{
	  printk("memory succefully allocated\n");*/
	/*if(copy_from_user(ptr,buff,length)){
	  printk("writing failed \n");
	  return -1;
	  }*/
	if(get_user(x,buff) !=0){
		printk("Failed to recieve data\n");
	}
	else{
		printk("copying to user is success with %s\n",buff);
	}
	//}
	return length;
}

int device_release(struct inode *pinode, struct file *pfile){
	printk("%s function is called\n",__func__);
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int charinit(void){
	printk("module loaded succesfully\n");
	major = register_chrdev(0,DEVICE_NAME,&fops);
	printk("major number is %d\n",major);
	return 0;
}

static void charexit(void){
	printk("module unloaded successfully\n");
	unregister_chrdev(major,DEVICE_NAME);
}


module_init(charinit);
module_exit(charexit);



MODULE_AUTHOR("Ram");
MODULE_DESCRIPTION("A simple character device");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");
