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
    {0xeb233a45, "__kmalloc"},
    {0x2e2fddd3, "vCanCleanup"},
    {0xe25ee9d3, "_raw_write_lock_irqsave"},
    {0x9cd571dc, "vCanCardRemoved"},
    {0xae630ce8, "pci_disable_device"},
    {0xd981b7ff, "seq_printf"},
    {0x7154900d, "pci_release_regions"},
    {0x36e58bcd, "pv_ops"},
    {0x1c1b9f8e, "_raw_write_unlock_irqrestore"},
    {0xd9a5ea54, "__init_waitqueue_head"},
    {0x679e43d1, "queue_empty"},
    {0xfb578fc5, "memset"},
    {0xfaa20ff6, "queue_front"},
    {0xb14f58c1, "vCanDispatchEvent"},
    {0x4681df01, "pci_iounmap"},
    {0x3812050a, "_raw_spin_unlock_irqrestore"},
    {0x1b44c663, "current_task"},
    {0xc5850110, "printk"},
    {0x8b2c612b, "set_capability_value"},
    {0xa1c76e0a, "_cond_resched"},
    {0xe6cf5658, "queue_wakeup_on_space"},
    {0x220f6eb0, "queue_pop"},
    {0x2072ee9b, "request_threaded_irq"},
    {0xfe487975, "init_wait_entry"},
    {0x65c1309b, "vCanInitData"},
    {0x736b5662, "_raw_read_lock_irqsave"},
    {0x6a1ac2ee, "vCanGetCardInfo2"},
    {0xdecd0b29, "__stack_chk_fail"},
    {0x8ddd8aad, "schedule_timeout"},
    {0xb8b9f817, "kmalloc_order_trace"},
    {0xa16c8613, "_raw_read_unlock_irqrestore"},
    {0xbdfb6dbb, "__fentry__"},
    {0xcbd4898c, "fortify_panic"},
    {0x478f00e1, "pci_unregister_driver"},
    {0xf5cb25c8, "kmem_cache_alloc_trace"},
    {0xdbf17652, "_raw_spin_lock"},
    {0x51760917, "_raw_spin_lock_irqsave"},
    {0x3eeb2322, "__wake_up"},
    {0x8c26d495, "prepare_to_wait_event"},
    {0xfa253959, "vCanGetCardInfo"},
    {0x37a0cba, "kfree"},
    {0xedf4f48c, "pci_request_regions"},
    {0x3292177a, "vCanInit"},
    {0x24694125, "__pci_register_driver"},
    {0xbccf3847, "vCanFlushSendBuffer"},
    {0x92540fbf, "finish_wait"},
    {0x55555880, "queue_reinit"},
    {0x30372d96, "queue_release"},
    {0xc5b6f236, "queue_work_on"},
    {0x29361773, "complete"},
    {0x66374091, "pci_iomap"},
    {0x4a453f53, "iowrite32"},
    {0x42980214, "pci_enable_device"},
    {0x4d1ff60a, "wait_for_completion_timeout"},
    {0xe484e35f, "ioread32"},
    {0xc1514a3b, "free_irq"},
};

MODULE_INFO(depends, "kvcommon");

MODULE_INFO(srcversion, "B8A9614101626BF0D54780F");
