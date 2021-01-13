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

        end_pad(pPad);
    }
    return 0;    
}
