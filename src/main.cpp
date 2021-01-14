#include <stdio.h>

#include "cbase.h"

#include <libpad.h>

#include "pad.h"

int main()
{
    pad_init();

    while (1) 
    {
        padSystem* pPad = do_pad();
        
        if(pPad->new_pad & PAD_LEFT)
            printf("LEFT\n");
        
        if(pPad->new_pad & PAD_UP)
            printf("cry ab dox che\n"); 
        end_pad(pPad);       
    }
    
    return 0;    
}
