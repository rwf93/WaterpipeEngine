struct padSystem
{
    u32 new_pad;
    u32 old_pad;

    struct padButtonStatus buttonStatus;
};

padSystem* do_pad();
void end_pad(padSystem* pad);
void pad_init();
