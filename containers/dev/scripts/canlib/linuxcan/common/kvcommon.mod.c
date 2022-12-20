#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module __section(.gnu.linkonce.this_module) = {
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

static const struct modversion_info ____versions[] __used __section(__versions) = {
    {0xb3753869, "module_layout"},
    {0x78f44845, "cdev_del"},
    {0x35216b26, "kmalloc_caches"},
    {0xeb233a45, "__kmalloc"},
    {0xa3036ef8, "cdev_init"},
    {0x1ed8b599, "__x86_indirect_thunk_r8"},
    {0xf6fa2eb9, "single_open"},
    {0x37110088, "remove_wait_queue"},
    {0xb3635b01, "_raw_spin_lock_bh"},
    {0x56470118, "__warn_printk"},
    {0xa3ee9e12, "remove_proc_entry"},
    {0x6729d3df, "__get_user_4"},
    {0xc29957c3, "__x86_indirect_thunk_rcx"},
    {0x6091b333, "unregister_chrdev_region"},
    {0x167e7f9d, "__get_user_1"},
    {0x4e22ab94, "seq_read"},
    {0x36e58bcd, "pv_ops"},
    {0xd9a5ea54, "__init_waitqueue_head"},
    {0xb44ad4b3, "_copy_to_user"},
    {0xe8c07ff2, "PDE_DATA"},
    {0x6de13801, "wait_for_completion"},
    {0xb8e7ce2c, "__put_user_8"},
    {0xfb578fc5, "memset"},
    {0x3812050a, "_raw_spin_unlock_irqrestore"},
    {0x1b44c663, "current_task"},
    {0xc5850110, "printk"},
    {0x9ec6ca96, "ktime_get_real_ts64"},
    {0xa1c76e0a, "_cond_resched"},
    {0x9166fada, "strncpy"},
    {0xc3aaf0a9, "__put_user_1"},
    {0x8c03d20c, "destroy_workqueue"},
    {0xfe487975, "init_wait_entry"},
    {0x7afe113a, "cdev_add"},
    {0xb601be4c, "__x86_indirect_thunk_rdx"},
    {0xb2fd5ceb, "__put_user_4"},
    {0x49c41a57, "_raw_spin_unlock_bh"},
    {0xdecd0b29, "__stack_chk_fail"},
    {0x1000e51, "schedule"},
    {0x8ddd8aad, "schedule_timeout"},
    {0xb8b9f817, "kmalloc_order_trace"},
    {0x6d334118, "__get_user_8"},
    {0x2ea2c95c, "__x86_indirect_thunk_rax"},
    {0xbdfb6dbb, "__fentry__"},
    {0xf5cb25c8, "kmem_cache_alloc_trace"},
    {0xdbf17652, "_raw_spin_lock"},
    {0x51760917, "_raw_spin_lock_irqsave"},
    {0x3eeb2322, "__wake_up"},
    {0x8c26d495, "prepare_to_wait_event"},
    {0xab62e5d0, "proc_create_data"},
    {0x4afb2238, "add_wait_queue"},
    {0xf77b56e2, "seq_lseek"},
    {0x37a0cba, "kfree"},
    {0x92540fbf, "finish_wait"},
    {0xc5b6f236, "queue_work_on"},
    {0x29361773, "complete"},
    {0xb145611f, "seq_release"},
    {0x7f02188f, "__msecs_to_jiffies"},
    {0x362ef408, "_copy_from_user"},
    {0xdf9208c0, "alloc_workqueue"},
    {0x88db9f48, "__check_object_size"},
    {0xe3ec2f2b, "alloc_chrdev_region"},
};

MODULE_INFO(depends, "");

MODULE_INFO(srcversion, "3CF1A15FF568D831D0A0A02");
