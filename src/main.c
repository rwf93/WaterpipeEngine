#include <debug.h>
#include <stdio.h>
#include <kernel.h>
#include <sifrpc.h>
#include <loadfile.h>

void reset_iop() {
    SifIopReset();
    while(!SifIopSync()) {
        printf("Syncing IOP\n");
    }
}

void load_sifs() {
    typedef struct sifmodule {
        const char* path;
        const char* args;
        int arg_length;
    } sifmod_t;

    sifmod_t mods[] = {
        {"rom0:SIO2MAN", NULL, 0},
        {"rom0:PADMAN", NULL, 0},
    };

    for(int i = 0; i < sizeof(mods) / sizeof(sifmod_t); i++) {
        if(SifLoadModule(mods[i].path, mods[i].arg_length, mods[i].args) < 0) {
            scr_printf("Couldn't load SIF module: %s", mods[i].path);
            SleepThread();
        }
    }
}

int main() {
    SifInitRpc(0);
    init_scr();
    reset_iop();
    load_sifs();
    
    SleepThread();

    return 0;
}