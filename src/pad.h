struct padSystem
{
    u32 new_pad;
    u32 old_pad;

    struct padButtonStatus buttonStatus;
};

struct padSystem* do_pad();
void end_pad(struct padSystem* pad);
void pad_init();
