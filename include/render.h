#ifndef RENDER_H
#define RENDER_H

struct GSGLOBAL;

class CGSKitRenderImpl
{
public:
    CGSKitRenderImpl();
    ~CGSKitRenderImpl();
    void Initalize();
    void Render();
private:
    GSGLOBAL *gsGlobal;
};

#endif
