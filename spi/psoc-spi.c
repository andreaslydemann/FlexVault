
#include <linux/err.h>
#include <plat/mcspi.h>
#include <linux/spi/spi.h>
#include <linux/module.h>
#include "psoc.h"
#include "psoc-spi.h"


/* We are only using ONE SPI device so far */
static struct spi_device *psoc_spi_device = NULL;

/* Method to retrieve SPI device pointer */
struct spi_device* PSoC_get_device(void){
  return psoc_spi_device;
}



/*
 * PSoC SPI Read 16-bit Register
 * Reads 16-bit content of register at 
 * the provided PSoC address
 */
int PSoC_spi_read_reg16(struct spi_device *spi, u8 addr, u16* value)
{
	struct spi_transfer t[2];
	struct spi_message m;
	u16 cmd = 0;
	u16 data = 0;

    /* Check for valid spi device */
    if(!spi)
      return -ENODEV;

	/* Create Cmd byte:
	 *
	 * | 0|RD|16|     ADDR     |
	 *   7  6  5  4  3  2  1  0
     */	 
	cmd = (addr+1) << 8;

	/* Init Message */
	memset(t, 0, sizeof(t));
	spi_message_init(&m);
	m.spi = spi;

	/* Configure tx/rx buffers */
	t[0].tx_buf = &cmd;
	t[0].rx_buf = NULL;
	t[0].len = 2;
	t[0].delay_usecs = 150;
	spi_message_add_tail(&t[0], &m);

	t[1].tx_buf = NULL;
	t[1].rx_buf = &data;
	t[1].len = 2;
	spi_message_add_tail(&t[1], &m);

	/* Transmit SPI Data (blocking) */
	spi_sync(m.spi, &m);


    *value = data;
	return 0;
}

/*
 * PSoC SPI Write 8-bit Register
 * Writes 8-bit content to register at 
 * the provided PSoC address
 */
int PSoC_spi_write_reg8(struct spi_device *spi, u8 addr, u8 data)
{
  struct spi_transfer t[1];
  struct spi_message m;
  u16 cmd = 0;

  /* Check for valid spi device */
    if(!spi)
    return -ENODEV;

  
  /* Create Cmd byte:
   *
   * | 0|WR| 8|     ADDR     |
   *   7  6  5  4  3  2  1  0
   */ 
	cmd = (((1<<6) | (addr+1)) << 8) | data; //

  /* Init Message */
  memset(&t, 0, sizeof(t)); 
  spi_message_init(&m);
  m.spi = spi;
  spi_message_add_tail(&t[0], &m);
 
  /* Configure tx/rx buffers */
  t[0].tx_buf = &cmd;
  t[0].rx_buf = NULL;
  t[0].len = 2;
  spi_message_add_tail(&t[0], &m);



  /* Transmit SPI Data (blocking) */
  spi_sync(m.spi, &m);

  printk(KERN_INFO "sending %i\n",cmd);


  return 0;
}

/*
 * PsoC Probe/release
 * Used by the SPI Master to probe the device
 * when an SPI device is registered.
 */
static int __devinit psoc_spi_probe(struct spi_device *spi)
{

  printk(KERN_DEBUG "New SPI device: %s using chip select: %i\n",
	 spi->modalias, spi->chip_select);
  
  spi->bits_per_word = 16;  
  spi_setup(spi);

  /* In this case we assume just one device */ 
  psoc_spi_device = spi;  
 
  psoc_spi_device = spi;  
  printk(KERN_DEBUG "Probing PSoC");

return 0;
}

/*
 * PSoC Remove
 * Called when the SPI device is removed
 */
static int __devexit psoc_remove(struct spi_device *spi)
{
	
    psoc_spi_device = NULL;
    printk (KERN_ALERT "Removing SPI device %s on chip select %i\n", spi->modalias, spi->chip_select);
    return 0;

  return 0;
}

/*
 * psoc SPI Driver Struct
 * Holds function pointers to probe/release
 * methods and the name under which it is registered
 *
 */
static struct spi_driver psoc_spi_driver = {
  .driver = {
    .name = "PSoC",
    .bus = &spi_bus_type,
    .owner = THIS_MODULE,
  },
  .probe = psoc_spi_probe,
  .remove = __devexit_p(psoc_remove),
};


/*
 * psoc SPI Init
 * Registers the spi driver with the SPI host
 */
int PSoC_spi_init(void)
{
  int err;

  err = spi_register_driver(&psoc_spi_driver);
  
  if(err<0)
    printk (KERN_ALERT "Error %d registering the PSoC SPI driver\n", err);
  
  return err;
}

/*
 * PSoC SPI Exit
 * Exit routine called from character driver.
 * Unregisters the driver from the SPI host
 */
void PSoC_spi_exit(void)
{


	printk("PSoC spi driver Exit\n");

  spi_unregister_driver(&psoc_spi_driver); 
}