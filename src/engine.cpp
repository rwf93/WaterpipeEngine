#include "cbase.h"
#include "engine.h"

#include <libpad.h>

#include "render.h"
#include "pad.h"

static CEngine s_Engine;
CEngine *g_Engine = &s_Engine;

CEngine::CEngine()
{
    
}

CEngine::~CEngine()
{
    
}

CGSKitRenderImpl* getRenderAPI()
{
    return g_RenderAPI;
}

void CEngine::Initalize()
{
    pad_init();
    printf("Created pad structure\nCEngine: %p\nRenderAPI: %p\n", this, this);
}

void CEngine::Think()
{

}

void CEngine::Frame()
{
    m_flCurrentTime++;

    float dt = m_flCurrentTime - m_flPreviousTime;

    m_flPreviousTime = m_flCurrentTime;

    m_flFrameTime += dt;

    if ( m_flFrameTime < 0.0f )
		return;
}

void CEngine::Thought()
{
    
}
