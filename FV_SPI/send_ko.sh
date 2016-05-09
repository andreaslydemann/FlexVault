sudo ifdown usb0
sudo ifup usb0 
make
scp spi.ko root@10.9.8.2:
scp hotplug_psoc_spi_device.ko root@10.9.8.2:
scp mk_psoc.sh root@10.9.8.2: