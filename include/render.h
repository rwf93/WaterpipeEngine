#ifndef RENDER_H
#define RENDER_H

typedef struct gsGlobal GSGLOBAL;

struct RenderParamaters
{
    // init params
    int rele, mfd, sts, std, rcyc;
    unsigned int fastwaitchannels;
    // chan_init
    int channel;
    // mode switch
    unsigned int mode;
};

class CGSKitRenderImpl
{
public:
    CGSKitRenderImpl();
    ~CGSKitRenderImpl();
    void Initalize(RenderParamaters params);
    void Render();
    void Clear(int colour);
private:
     GSGLOBAL *gsGlobal;
};

extern CGSKitRenderImpl *g_RenderAPI;

#endif
