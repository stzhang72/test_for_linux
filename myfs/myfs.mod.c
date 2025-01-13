#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

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
	{ 0xb0055659, "simple_fill_super" },
	{ 0xbd988885, "simple_release_fs" },
	{ 0xfa550e49, "unregister_filesystem" },
	{ 0xd976db1e, "new_inode" },
	{ 0x1e362ae8, "pcpu_hot" },
	{ 0x714367d4, "init_special_inode" },
	{ 0xa7d4ea46, "simple_dir_inode_operations" },
	{ 0xb63da163, "simple_dir_operations" },
	{ 0x4e8d1717, "inc_nlink" },
	{ 0x57bc19d2, "down_write" },
	{ 0x754d539c, "strlen" },
	{ 0xc124bacc, "lookup_one_len" },
	{ 0xcaa6e957, "d_instantiate" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0xce807a25, "up_write" },
	{ 0xb40dfe8b, "register_filesystem" },
	{ 0xd1652016, "kern_mount" },
	{ 0x9cf8de0e, "kill_litter_super" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x30a80826, "__kfifo_from_user" },
	{ 0xea4ba114, "current_time" },
	{ 0x64210cf6, "__mark_inode_dirty" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x4578f528, "__kfifo_to_user" },
	{ 0x1cf6db68, "mount_single" },
	{ 0xf079b8f9, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DF297A3C0C953EBA7B0A81A");
