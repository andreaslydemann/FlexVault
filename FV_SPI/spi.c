 #include <linux/spi/spi.h>
 #include <linux/fs.h>
 #include <linux/cdev.h>
 #include <linux/device.h>
 #include <asm/uaccess.h>
 #include <linux/module.h>
 #include <linux/err.h>
 #include <linux/ctype.h>

#define psoc_dev_count 1

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("spi driver"); 

dev_t devno; 

static int psoc_spi_probe(struct spi_device *spi);
static int psoc_spi_remove(struct spi_device *spi);

struct cdev *my_cdev;
struct file_operations psoc_fops;
struct psoc { int revision;};
static struct spi_device *psoc_spi_device = NULL;

static struct spi_driver psoc_spi_driver = {
  .driver = {
    .name = "psoc",
    .bus = &spi_bus_type,
    .owner = THIS_MODULE,
  },
  .probe = psoc_spi_probe,
  .remove = psoc_spi_remove,
};

static int psoc_spi_init(void)
{
    int err;

    err = spi_register_driver(&psoc_spi_driver);

    if(err<0)
    {
        printk (KERN_ALERT "Error %d registering the PSoC SPI driver\n", err);
        goto exit_err;
    }
  
  
    err = alloc_chrdev_region(&devno, 0, psoc_dev_count, "PSoC4"); //Register device
    if (err != 0)
    {
        printk(KERN_ALERT "DYNAMIC ALLOCATION FAILURE!");
        goto regDev_err;
    }
    else
    {
        printk(KERN_ALERT "The major number is %d", MAJOR(devno));
    }
    
    my_cdev = cdev_alloc(); //Allocate device
    
    cdev_init(my_cdev, &psoc_fops); //Initialize cdev and associate fileoperation struct with driver

    err = cdev_add(my_cdev, devno, psoc_dev_count); // Add cdev
    if (err != 0)
    {
        printk(KERN_ALERT "CDEV ADD FAILED!");
        goto regDev_err;
    }

    printk(KERN_ALERT "PSoC initialized\n");
    return 0;

    regDev_err:
    unregister_chrdev_region(devno, psoc_dev_count);

    spi_unregister_driver(&psoc_spi_driver); 
    exit_err:
    return err;
  
  
}

//static int __devinit ads7870_spi_probe(struct spi_device *spi)
static int psoc_spi_probe(struct spi_device *spi)
{
 
  printk(KERN_DEBUG "Probe called: New SPI device: %s using chip select: %i\n",
	 spi->modalias, spi->chip_select);
  
  spi->bits_per_word = 8;  
  spi_setup(spi);

  /* In this case we assume just one device */ 
  psoc_spi_device = spi;  
 
  return 0;
}


static void psoc_spi_exit(void)
{
    cdev_del(my_cdev); // Delete cdev
    unregister_chrdev_region(devno, psoc_dev_count); // Unregister device
    spi_unregister_driver(&psoc_spi_driver); 

}

static int psoc_spi_remove(struct spi_device *spi)
{
  psoc_spi_device = 0;
  
  printk (KERN_ALERT "Removing SPI device %s on chip select %i\n", 
	  spi->modalias, spi->chip_select);

  return 0;
}

int psoc_open(struct inode *inode, struct file *filep)

{

 return 0; 

}

int psoc_release(struct inode *inode, struct file *filep)

{

 return 0;

}

size_t psoc_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos)
{
  int minor, len, value;
  char buffer[MAXLEN];
   
    
  minor = iminor(filep->f_inode);

  printk(KERN_ALERT "Writing to PSoC4 [Minor] %i \n", minor);
    
  /* Limit copy length to MAXLEN allocated andCopy from user */
  len = count < MAXLEN ? count : MAXLEN;
  if(copy_from_user(buffer, ubuf, len))
    return -EFAULT;
	
  /* Pad null termination to string */
  buffer[len] = '\0';   

  if(MODULE_DEBUG)
    printk("string from user: %s\n", buffer);

  sscanf(buffer,"%i", &value);
  if(MODULE_DEBUG)
    printk("value %i\n", value);

  *f_pos += len;

  /* return length actually written */
  return len;
}



struct file_operations psoc_fops = {
    .owner = THIS_MODULE,
    //.read = psoc_read,
    //.write = psoc_write,
    .open = psoc_open,
    .release = psoc_release
};

module_init(psoc_spi_init);
module_exit(psoc_spi_exit);
