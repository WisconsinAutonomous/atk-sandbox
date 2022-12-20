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
    {0x35216b26, "kmalloc_caches"},
    {0x2e2fddd3, "vCanCleanup"},
    {0xd981b7ff, "seq_printf"},
    {0x7bb521a4, "vCanTime"},
    {0x36e58bcd, "pv_ops"},
    {0x679e43d1, "queue_empty"},
    {0xfb578fc5, "memset"},
    {0xfaa20ff6, "queue_front"},
    {0xb14f58c1, "vCanDispatchEvent"},
    {0x1b44c663, "current_task"},
    {0xc5850110, "printk"},
    {0x8b2c612b, "set_capability_value"},
    {0xe6cf5658, "queue_wakeup_on_space"},
    {0x220f6eb0, "queue_pop"},
    {0x65c1309b, "vCanInitData"},
    {0x6a1ac2ee, "vCanGetCardInfo2"},
    {0xdecd0b29, "__stack_chk_fail"},
    {0x8ddd8aad, "schedule_timeout"},
    {0xb8b9f817, "kmalloc_order_trace"},
    {0x2ea2c95c, "__x86_indirect_thunk_rax"},
    {0xbdfb6dbb, "__fentry__"},
    {0xf5cb25c8, "kmem_cache_alloc_trace"},
    {0xdbf17652, "_raw_spin_lock"},
    {0x3eeb2322, "__wake_up"},
    {0xfa253959, "vCanGetCardInfo"},
    {0x37a0cba, "kfree"},
    {0x3292177a, "vCanInit"},
    {0xbccf3847, "vCanFlushSendBuffer"},
    {0x30372d96, "queue_release"},
};

MODULE_INFO(depends, "kvcommon");

MODULE_INFO(srcversion, "3CD6BE4FBCB190D5D527B57");
