#include "cbase.h"
#include "engine.h"

#include <libpad.h>

#include "render.h"
#include "pad.h"

static CEngine s_Engine;
CEngine *g_Engine = &s_Engine;

CEngine::CEngine()
{
    engineRender = nullptr;
    engineRender = new CGSKitRenderImpl();
}

CEngine::~CEngine()
{
    delete engineRender;
    engineRender = nullptr;
}

void CEngine::Initalize()
{
    pad_init();
    printf("Created pad structure\nCEngine: %p\nCGSKitRenderImpl: %p\n", this, engineRender);
}

void CEngine::Think()
{
    currentTime++;
    
    input = do_pad();
}

void CEngine::Thought()
{
    end_pad(input);
}
