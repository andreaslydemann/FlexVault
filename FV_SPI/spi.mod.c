#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xf3c390b5, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x53c7ab95, __VMLINUX_SYMBOL_STR(spi_bus_type) },
	{ 0x679344f8, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x96cb78f4, __VMLINUX_SYMBOL_STR(driver_unregister) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xf1f8f312, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x16c549e4, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x4ded0af, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x6a204038, __VMLINUX_SYMBOL_STR(spi_register_driver) },
	{ 0xad71faa8, __VMLINUX_SYMBOL_STR(spi_setup) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "5AB689BE43EDC1392E071BA");
