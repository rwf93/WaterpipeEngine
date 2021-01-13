struct padSystem
{
    u32 new_pad;
    u32 old_pad; 
};

extern struct padSystem* do_pad();
extern void pad_init();
extern struct padSystem* g_padSystem;
