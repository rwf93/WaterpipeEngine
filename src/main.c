#include <stdio.h>

#include <tamtypes.h>
#include <sifrpc.h>
#include <debug.h>
#include <unistd.h>

#include <libpad.h>

#include "pad.h"

int main()
{
    pad_init();
    
    while (1) 
    {
        struct padSystem* pPad = do_pad();
        
        if(pPad->new_pad & PAD_LEFT)
            printf("LEFT\n");
        
        if(pPad->new_pad & PAD_UP)
            printf("UP\n"); 
        
        end_pad(pPad);
        
        u32* ptr = 0;
        u32 val;
        val = *ptr;
        printf("Not getting here... %i\n", val);

    }
    return 0;    
}
