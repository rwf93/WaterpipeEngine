#include <stdio.h>

#include <tamtypes.h>
#include <sifrpc.h>
#include <debug.h>
#include <unistd.h>

#include <libpad.h>

extern int port, slot;
extern int pad_init();
u32 old_pad = 0;

u32 do_pad()
{
    struct padButtonStatus buttons;
	u32 paddata;
	u32 new_pad;
	int ret;
	float fXOff;
	float fYOff;
	static float fXOffAccum = 0.0f;
	static float fYOffAccum = 0.0f;

    do
    {
		ret=padGetState(port, slot);
	} 
    while((ret != PAD_STATE_STABLE) && (ret != PAD_STATE_FINDCTP1));
    
    ret = padRead(port, slot, &buttons);

    if (ret != 0)
    {
        paddata = 0xffff ^ buttons.btns;

		new_pad = paddata & ~old_pad;
		old_pad = paddata;
        
        return new_pad;
    }

    return new_pad;
}

int main()
{
    pad_init();
    
    while (1) 
    {
        u32 pad = do_pad();
        if(pad & PAD_LEFT)
            printf("LEFT\n");
    }
    return 0;    
}
