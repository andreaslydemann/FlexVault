rmmod spi.ko
rmmod hotplug_psoc_spi_device.ko
echo 0x3 > /sys/class/cplddrv/cpld/spi_route_reg	
echo 0x1 > /sys/class/cplddrv/cpld/ext_serial_if_route_reg
insmod spi.ko
insmod hotplug_psoc_spi_device.ko
rm /dev/spidev0
mknod /dev/spidev0 c 247 0
echo 0x44ff > /dev/spidev0