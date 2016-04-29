#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include "psoc-spi.h"
#include "psoc.h"

#define psoc_MAJOR 65
#define psoc_MINOR 0
#define NBR_MINORS 4


MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("PSoC Driver");
MODULE_AUTHOR("Gruppe 4 - Gubbi");

static struct cdev psoc_cdev; // creating character device
dev_t devno;

//Functions for file_operations - all of these functions have to have the parameters they have, because the have to match the file_operations functions' predefined parameters
int psoc_open(struct inode *inode, struct file *filep)
{
  int major, minor;
  major = MAJOR(inode->i_rdev);
  minor = MINOR(inode->i_rdev);
  printk("Opening MyGpio Device [major], [minor]: %i, %i\n", major, minor);
  	  if(!PSoC_get_device())
	    return -ENODEV;
  return 0;
}

int psoc_release(struct inode *inode, struct file *filep)
{
int minor, major;

  major = MAJOR(inode->i_rdev);
  minor = MINOR(inode->i_rdev);
  printk("Closing/Releasing MyGpio Device [major], [minor]: %i, %i\n", major, minor);
  return 0;
}

ssize_t psoc_read(struct file *filep, char __user *ubuf, 
           size_t count, loff_t *f_pos)
{  // adapted from ads7870 example

  int minor, len;
  char resultBuf[MAXLEN];
  s16 result;
  int err;
    
  minor = MINOR(filep->f_dentry->d_inode->i_rdev);
   
  err = PSoC_spi_read_reg16(PSoC_get_device(),(u8)minor,(u16*)&result);
	  if(err)
		  return err;
  
  /* Convert to string and copy to user space */
  //  len = snprintf(resultBuf, sizeof resultBuf, "%d\n", result);
  /* Convert integer to string limited to "count" size. Returns
   * length excluding NULL termination */
  len = snprintf(resultBuf, count, "%d\n", result);
  len++;

  /* Copy data to user space */
  if(copy_to_user(ubuf, resultBuf, len))
    return -EFAULT;

  /* Move fileptr */
  *f_pos += len;

  return len;
}

ssize_t psoc_write(struct file *filep, const char __user *ubuf, 
           size_t count, loff_t *f_pos)
{
  int minor, len, value;
  char kbuf[MAXLEN];    
    
  minor = MINOR(filep->f_dentry->d_inode->i_rdev);

  printk(KERN_ALERT "Writing to PSoC [Minor] %i \n", minor);
    
  /* Limit copy length to MAXLEN allocated andCopy from user */
  len = count < MAXLEN ? count : MAXLEN;
  if(copy_from_user(kbuf, ubuf, len))
    return -EFAULT;
	
  /* Pad null termination to string */
  kbuf[len] = '\0';   


  /* Convert string to int */
  sscanf(kbuf,"%i", &value);

	if (minor != LED_CONTROL)
		return -EFAULT;

  {
	int err = PSoC_spi_write_reg8(PSoC_get_device(),(u8)minor,(u16)value);
	if (err)
		return err;
  }

  /* Legacy file ptr f_pos. Used to support 
   * random access but in char drv we dont! 
   * Move it the length actually  written 
   * for compability */
  *f_pos += len;

  /* return length actually written */
  return len;
}

struct file_operations psoc_cdev_fops =
{
  .owner = THIS_MODULE,
  .open = psoc_open,
  .read = psoc_read,
  .write = psoc_write,
  .release = psoc_release,
};


//Init function
static int __init psoc_init(void)
{
  //Make device numbers (major,minor) - static allocated chosen
  devno = MKDEV(psoc_MAJOR, psoc_MINOR);
  //Make variable for errorhandling
  int err = 0;
  // request spi driver
  err = PSoC_spi_init();
  if (err < 0)
  {
    printk(KERN_ERR "SPI DRIVER REQUEST FAILED\n");
    goto err_exit;
  }
  
	devno = MKDEV(psoc_MAJOR, psoc_MINOR); // devno variable for major and minor numbers
	err = register_chrdev_region(devno,NBR_MINORS,"PSoC"); // registerering major and minor
	if(err < 0){
		printk(KERN_ERR "REGISTRATION OF CHRDEV REGION FAILED\n");
		goto err_release;
	}
	cdev_init(&psoc_cdev,&psoc_cdev_fops); // initialize charactor device containing file operations
	err = cdev_add(&psoc_cdev,devno,NBR_MINORS); // adding character device
	if(err < 0){
		printk(KERN_ERR "REGISTRATION OF CHRDEV FAILED\n");
		goto err_chrdev_region;
	}
	printk(KERN_INFO "PSoC DRIVER INSERTED\n");
	return 0;

  return err; //if everything succeeds the should be 0.
  
  //Handle errors
	err_chrdev_region:
		unregister_chrdev_region(devno,NBR_MINORS);
	err_release:
		PSoC_spi_exit();
	err_exit:
return err;
  
}

//Exit funktion
static void __exit psoc_exit(void)
{
  //Delete cdev
	cdev_del(&psoc_cdev);
  //Unregister devices
	unregister_chrdev_region(devno, NBR_MINORS);
	PSoC_spi_exit(); // remove spi
	printk(KERN_INFO "PSOC REMOVED\n");
	

}

module_init(psoc_init);
module_exit(psoc_exit);