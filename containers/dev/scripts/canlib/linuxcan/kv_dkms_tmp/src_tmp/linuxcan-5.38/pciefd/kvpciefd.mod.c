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
    {0x2e2fddd3, "vCanCleanup"},
    {0xe25ee9d3, "_raw_write_lock_irqsave"},
    {0x9cd571dc, "vCanCardRemoved"},
    {0xd8fd6a9a, "dma_set_mask"},
    {0xae630ce8, "pci_disable_device"},
    {0xd981b7ff, "seq_printf"},
    {0x56470118, "__warn_printk"},
    {0xbddf62d2, "dma_direct_sync_single_for_cpu"},
    {0x7154900d, "pci_release_regions"},
    {0xc6f46339, "init_timer_key"},
    {0x97651e6c, "vmemmap_base"},
    {0x3c3ff9fd, "sprintf"},
    {0x36e58bcd, "pv_ops"},
    {0x15ba50a6, "jiffies"},
    {0x1c1b9f8e, "_raw_write_unlock_irqrestore"},
    {0xbfc177bc, "iowrite32_rep"},
    {0xd9a5ea54, "__init_waitqueue_head"},
    {0x679e43d1, "queue_empty"},
    {0x6de13801, "wait_for_completion"},
    {0xfee56dca, "pci_set_master"},
    {0x7e526bfa, "__x86_indirect_thunk_r10"},
    {0xfb578fc5, "memset"},
    {0xfaa20ff6, "queue_front"},
    {0xb14f58c1, "vCanDispatchEvent"},
    {0x4681df01, "pci_iounmap"},
    {0x3812050a, "_raw_spin_unlock_irqrestore"},
    {0x1b44c663, "current_task"},
    {0xc5850110, "printk"},
    {0x449ad0a7, "memcmp"},
    {0x4c9d28b0, "phys_base"},
    {0x8b2c612b, "set_capability_value"},
    {0xd453333e, "set_capability_ex_mask"},
    {0xe6cf5658, "queue_wakeup_on_space"},
    {0x37805d7b, "dma_direct_map_page"},
    {0x220f6eb0, "queue_pop"},
    {0x69dd3b5b, "crc32_le"},
    {0x235ea4c1, "calculateCRC32"},
    {0x24d273d1, "add_timer"},
    {0x2072ee9b, "request_threaded_irq"},
    {0x276940fc, "pci_clear_master"},
    {0x7cd8d75e, "page_offset_base"},
    {0x9e163a88, "dma_direct_unmap_page"},
    {0x65c1309b, "vCanInitData"},
    {0x736b5662, "_raw_read_lock_irqsave"},
    {0x31b4ff83, "set_capability_ex_value"},
    {0x6a1ac2ee, "vCanGetCardInfo2"},
    {0xdecd0b29, "__stack_chk_fail"},
    {0x9cb986f2, "vmalloc_base"},
    {0x8ddd8aad, "schedule_timeout"},
    {0xb8b9f817, "kmalloc_order_trace"},
    {0x47941711, "_raw_spin_lock_irq"},
    {0x2ea2c95c, "__x86_indirect_thunk_rax"},
    {0xa16c8613, "_raw_read_unlock_irqrestore"},
    {0x38c0115f, "dev_driver_string"},
    {0xbdfb6dbb, "__fentry__"},
    {0xcbd4898c, "fortify_panic"},
    {0x478f00e1, "pci_unregister_driver"},
    {0xf5cb25c8, "kmem_cache_alloc_trace"},
    {0xdbf17652, "_raw_spin_lock"},
    {0x51760917, "_raw_spin_lock_irqsave"},
    {0xab755367, "set_capability_mask"},
    {0x3eeb2322, "__wake_up"},
    {0x206ebad6, "queue_irq_lock"},
    {0xfa253959, "vCanGetCardInfo"},
    {0x37a0cba, "kfree"},
    {0x69acdf38, "memcpy"},
    {0xedf4f48c, "pci_request_regions"},
    {0x3292177a, "vCanInit"},
    {0xb893b480, "dma_direct_sync_single_for_device"},
    {0x24694125, "__pci_register_driver"},
    {0x55555880, "queue_reinit"},
    {0x30372d96, "queue_release"},
    {0xc5b6f236, "queue_work_on"},
    {0x29361773, "complete"},
    {0x66374091, "pci_iomap"},
    {0x4a453f53, "iowrite32"},
    {0x42980214, "pci_enable_device"},
    {0x4d1ff60a, "wait_for_completion_timeout"},
    {0xdd7bab0c, "dma_ops"},
    {0xe484e35f, "ioread32"},
    {0xc1514a3b, "free_irq"},
};

MODULE_INFO(depends, "kvcommon");

MODULE_INFO(srcversion, "ECFE9CB742C5996B7E68355");
