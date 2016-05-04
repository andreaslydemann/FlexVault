rmmod spi.ko
rmmod hotplug_psoc_device.ko
insmod spi.ko
insmod hotplug_psoc_device.ko
mknod /dev/spidev0 c 247 0
echo 0xff > /dev/spidev0
dmesg