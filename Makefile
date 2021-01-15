EE_BIN = packaged/WPIP.160.48
EE_OBJS = src/main.o src/pad.o src/render.o

EE_LIBS += -lc -ldebug -lmath3d
EE_LIBS += -lgskit_toolkit -lgskit -ldmakit 
EE_LIBS += -ldraw -lgraph -lpacket2 -ldma 
EE_LIBS += -lpad
EE_LIBS += -lstdc++

all: $(EE_BIN)
	$(EE_STRIP) --strip-all $(EE_BIN)
	mkisofs -o waterpipe.iso packaged
sim: 
	/usr/bin/PCSX2 --nogui waterpipe.iso

clean: 
	rm -f $(EE_BIN) $(EE_OBJS)

include Makefile.pref
include Makefile.eeglobal
