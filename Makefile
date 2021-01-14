EE_BIN = waterpipe.elf
EE_OBJS = src/main.o src/pad.o

EE_LIBS += -lc -ldebug -lmath3d
EE_LIBS += -ldraw -lgraph -lpacket2 -ldma
EE_LIBS += -lgskit_toolkit -lgskit
EE_LIBS += -lpad

all: $(EE_BIN)
	$(EE_STRIP) --strip-all $(EE_BIN)

sim: 
	/usr/bin/PCSX2 --elf=$(PWD)/$(EE_BIN) --nogui

clean: 
	rm -f $(EE_BIN) $(EE_OBJS)

include Makefile.pref
include Makefile.eeglobal
