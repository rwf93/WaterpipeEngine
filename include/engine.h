#ifndef ENGINE_H
#define ENGINE_H

class CGSRenderImpl;

class CEngine
{
public:
    CEngine();
    ~CEngine();
    
    void Initalize();

    void Think();
    void Frame();
    void Thought();
    
    CGSRenderImpl* getRenderAPI();

    double			m_flCurrentTime;
	float			m_flFrameTime;
	double			m_flPreviousTime;
};

extern CEngine* g_Engine;

#endif
