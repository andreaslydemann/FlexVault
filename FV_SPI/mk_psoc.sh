rmmod spi.ko
rmmod hotplug_psoc_spi_device.ko
insmod spi.ko
insmod hotplug_psoc_spi_device.ko
rm /dev/spidev0
mknod /dev/spidev0 c 247 0
echo 0x44ff > /dev/spidev0