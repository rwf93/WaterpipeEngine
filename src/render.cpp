#include "cbase.h"

#include <gsKit.h>
#include <dmaKit.h>
#include <gsToolkit.h>

#include "gsCore.h"
#include "render.h"

CGSKitRenderImpl::CGSKitRenderImpl()
{
    gsGlobal = nullptr;
}

CGSKitRenderImpl::~CGSKitRenderImpl()
{
    gsGlobal = nullptr;
}

void CGSKitRenderImpl::Initalize(RenderParamaters params)
{
    gsGlobal = gsKit_init_global();

    dmaKit_init(params.rele, params.mfd, params.sts, 
            params.std, params.rcyc, params.fastwaitchannels);

    dmaKit_chan_init(params.channel);
    gsKit_init_screen(gsGlobal);

    gsKit_mode_switch(gsGlobal, params.mode);

    printf("Initalized GSGlobal at: %p\n", gsGlobal);
}

void CGSKitRenderImpl::Clear(int colour)
{
    gsKit_clear(gsGlobal, colour);
}

void CGSKitRenderImpl::Render()
{
    gsKit_queue_exec(gsGlobal);
    gsKit_sync_flip(gsGlobal);
}
