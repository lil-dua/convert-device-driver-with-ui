#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x32e21920, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x748154da, "class_destroy" },
	{ 0xfdd66e81, "device_destroy" },
	{ 0xc7466e35, "cdev_del" },
	{ 0x6a0a71c7, "cdev_add" },
	{ 0x320c3a3f, "cdev_init" },
	{ 0xeea9753b, "cdev_alloc" },
	{ 0xa94ce2a9, "device_create" },
	{ 0xaf919f03, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x56470118, "__warn_printk" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x92997ed8, "_printk" },
	{ 0x754d539c, "strlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xa916b694, "strnlen" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A845D0346190D069A51A0F4");
