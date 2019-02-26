#define device_init_wakeup(dev,val) \
 do { \
 device_can_wakeup(dev) = !!(val); \
 device_set_wakeup_enable(dev,val); \
 } while(0)
