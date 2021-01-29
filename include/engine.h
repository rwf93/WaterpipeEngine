#ifndef ENGINE_H
#define ENGINE_H

class CGSKitRenderImpl;
class padSystem;

class CEngine
{
public:
    CEngine();
    ~CEngine();
    
    void Initalize();

    void Think();
    void Thought();

    CGSKitRenderImpl* engineRender;    
    padSystem* input;
    float currentTime;
};

extern CEngine* g_Engine;

#endif
