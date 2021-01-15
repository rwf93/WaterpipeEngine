#include "cbase.h"

#include <gsKit.h>
#include <dmaKit.h>
#include <gsToolkit.h>

#include "render.h"

CGSKitRenderImpl::CGSKitRenderImpl()
{
    gsGlobal = nullptr;
}

CGSKitRenderImpl::~CGSKitRenderImpl()
{
    gsGlobal = nullptr;
}

void CGSKitRenderImpl::Initalize()
{
    gsGlobal = gsKit_init_global();

    dmaKit_init(D_CTRL_RELE_OFF, D_CTRL_MFD_OFF, D_CTRL_STS_UNSPEC,
		    D_CTRL_STD_OFF, D_CTRL_RCYC_8, 1 << DMA_CHANNEL_GIF);

    dmaKit_chan_init(DMA_CHANNEL_GIF);
    gsKit_init_screen(gsGlobal);

    gsKit_mode_switch(gsGlobal, GS_PERSISTENT);

    gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(rand() * 255, 0, 0, 0, 0));

    printf("Initalized GSGlobal at: %p\n", gsGlobal);
}

void CGSKitRenderImpl::Render()
{
    gsKit_queue_exec(gsGlobal);
    gsKit_sync_flip(gsGlobal);
}
