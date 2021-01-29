#include "cbase.h"

#include <cstdio>
#include <libpad.h>
#include <loadfile.h>

#include "engine.h"
#include "render.h"
#include "pad.h"
#include "colours.h"

#include "math.h"

#include <gsCore.h>

void loadPrimaries()
{
    SifInitRpc(0);
    
    int ret;

    ret = SifLoadModule("rom0:SIO2MAN", 0, NULL);
    if (ret < 0)
    {
        printf("sifLoadModule sio failed: %d\n", ret);
        SleepThread();
    }

    ret = SifLoadModule("rom0:PADMAN", 0, NULL);
    if (ret < 0)
    {
        printf("sifLoadModule pad failed: %d\n", ret);
        SleepThread();
    }
    
    ret = SifLoadModule("rom0:ADDDRV", 0, NULL);
    if (ret < 0)
    {
        printf("sifLoadModule dvd failed: %d\n", ret);
        SleepThread();
    }
}

int main()
{
    loadPrimaries();

    g_Engine->Initalize();

    RenderParamaters params;

    params.rele = D_CTRL_RELE_OFF;
    params.mfd  = D_CTRL_MFD_OFF;
    params.sts  = D_CTRL_STS_UNSPEC;
    params.std  = D_CTRL_STD_OFF;
    params.rcyc = D_CTRL_RCYC_8;
    params.fastwaitchannels = 1 << DMA_CHANNEL_GIF;
    
    params.channel = DMA_CHANNEL_GIF;

    params.mode = GS_PERSISTENT;  
    
    g_Engine->engineRender->Initalize(params);

    FILE* fp = fopen("rom1:SYSTEM.CNF", "r");

    while (1) 
    {
        g_Engine->Think();
        g_Engine->Thought();

        g_Engine->engineRender->Clear(Color(255, 255, 255).getColorInt());

        g_Engine->engineRender->Render();
    }
    
    return 0;    
}
