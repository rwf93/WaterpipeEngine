EE_BIN = waterpipe.elf
EE_OBJS = main.o
EE_LIBS = -ldraw -lgraph -lmath3d -lpacket2 -ldma

clean: 
	rm -f $(EE_BIN) $(EE_OBJS)

all: $(EE_BIN)
	$(EE_STRIP) --strip-all $(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal