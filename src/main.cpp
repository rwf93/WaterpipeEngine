#include "cbase.h"

#include <libpad.h>
#include "pad.h"
#include "render.h"

#include <vector>

int main()
{
    pad_init();
    
    CGSKitRenderImpl engineRender;
    engineRender.Initalize();    

    while (1) 
    {
        engineRender.Render();

        padSystem* pPad = do_pad();
        
        if(pPad->new_pad & PAD_LEFT)
            printf("LEFT\n");
        
        if(pPad->new_pad & PAD_UP)
            printf("kurwa\n");

//        printf("%s\n", a);
        end_pad(pPad);       
    }
    
    return 0;    
}
