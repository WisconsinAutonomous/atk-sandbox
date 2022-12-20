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
    {0x2d3385d3, "system_wq"},
    {0x35216b26, "kmalloc_caches"},
    {0xfe2fd6f8, "queue_init"},
    {0xeb233a45, "__kmalloc"},
    {0x2e2fddd3, "vCanCleanup"},
    {0xa02aea3a, "queue_length"},
    {0x9cd571dc, "vCanCardRemoved"},
    {0xad9670f1, "seq_puts"},
    {0xd981b7ff, "seq_printf"},
    {0xfb40661a, "usb_kill_urb"},
    {0x15388bbc, "convert_vcan_to_hydra_cmd"},
    {0xa2bc981, "softSyncLoc2Glob"},
    {0x36e58bcd, "pv_ops"},
    {0x6cc93fc8, "softSyncAddMember"},
    {0xe8bc695c, "kthread_create_on_node"},
    {0xd9a5ea54, "__init_waitqueue_head"},
    {0xaad8c7d6, "default_wake_function"},
    {0x679e43d1, "queue_empty"},
    {0x6782eeca, "queue_push"},
    {0x6de13801, "wait_for_completion"},
    {0x2289f050, "ticks_init"},
    {0xfb578fc5, "memset"},
    {0xfaa20ff6, "queue_front"},
    {0x87d7787f, "queue_add_wait_for_space"},
    {0xb14f58c1, "vCanDispatchEvent"},
    {0x3812050a, "_raw_spin_unlock_irqrestore"},
    {0x1b44c663, "current_task"},
    {0x6b7ba003, "usb_deregister"},
    {0xc5850110, "printk"},
    {0x6adf812a, "ticks_to_64bit_ns"},
    {0x8b2c612b, "set_capability_value"},
    {0x9166fada, "strncpy"},
    {0xe6cf5658, "queue_wakeup_on_space"},
    {0x220f6eb0, "queue_pop"},
    {0x8c03d20c, "destroy_workqueue"},
    {0xc141228b, "usb_free_coherent"},
    {0x952664c5, "do_exit"},
    {0x42160169, "flush_workqueue"},
    {0xc8105e8d, "softSyncHandleTRef"},
    {0x3ba859c1, "module_put"},
    {0x65c1309b, "vCanInitData"},
    {0x43089b53, "usb_submit_urb"},
    {0xdecd0b29, "__stack_chk_fail"},
    {0x4913dc6e, "usb_bulk_msg"},
    {0x8ddd8aad, "schedule_timeout"},
    {0xb8b9f817, "kmalloc_order_trace"},
    {0x76d31a6d, "wake_up_process"},
    {0xbdfb6dbb, "__fentry__"},
    {0xf5cb25c8, "kmem_cache_alloc_trace"},
    {0xdbf17652, "_raw_spin_lock"},
    {0x51760917, "_raw_spin_lock_irqsave"},
    {0xab755367, "set_capability_mask"},
    {0x3eeb2322, "__wake_up"},
    {0x2a6aa565, "softSyncRemoveMember"},
    {0x37a0cba, "kfree"},
    {0x3292177a, "vCanInit"},
    {0xbccf3847, "vCanFlushSendBuffer"},
    {0xbf671e22, "usb_register_driver"},
    {0x10fa71db, "queue_remove_wait_for_space"},
    {0x244ab863, "queue_back"},
    {0x55555880, "queue_reinit"},
    {0x30372d96, "queue_release"},
    {0xc5b6f236, "queue_work_on"},
    {0x29361773, "complete"},
    {0xf98013c3, "usb_alloc_coherent"},
    {0x7f02188f, "__msecs_to_jiffies"},
    {0x4d1ff60a, "wait_for_completion_timeout"},
    {0xf4767a4c, "get_usb_root_hub_id"},
    {0xc9d8c16a, "usb_free_urb"},
    {0xdf9208c0, "alloc_workqueue"},
    {0x1937241e, "try_module_get"},
    {0x34ac35f4, "usb_alloc_urb"},
};

MODULE_INFO(depends, "kvcommon");

MODULE_ALIAS("usb:v0BFDp000Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp000Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp000Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp000Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp000Fd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0010d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0011d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0012d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0013d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0016d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0017d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0018d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0019d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp001Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp001Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp001Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp001Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0020d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0022d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0023d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0027d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0026d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0120d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0121d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0122d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0123d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0124d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0126d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0127d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0128d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "ACBC9A08014651BB76B4AF2");
