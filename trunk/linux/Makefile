SHARED_LIB := avsfilter.so
RELEASEDIR := /home/fahr/Xfilters/
AVIDEMUXSRCDIR := /media/src/avidemux_2.4.1/
SRC := avsfilter.cpp strnew.cpp avspipecomm.cpp cdebug.cpp

all: $(RELEASEDIR)$(SHARED_LIB)

#if you add strings from prefs.in.change into prefs.in 
#in avidemux2 src and reconfigure, recompile and installed new avidemux2,
#then add next define to DEFINES 
#-DPREFSINCHANGE
DEFINES := -DDEBUGMSG -DHAVE_CONFIG_H -DOS_LINUX -D_GNU_SOURCE=1 -D_REENTRANT -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -DPREFSINCHANGE
INCLUDES := -I. -I$(AVIDEMUXSRCDIR) -I$(AVIDEMUXSRCDIR)avidemux  -I$(AVIDEMUXSRCDIR)avidemux/ADM_libraries -I$(AVIDEMUXSRCDIR)avidemux/ADM_libraries/ADM_utilities -I$(AVIDEMUXSRCDIR)avidemux/ADM_libraries/ADM_lavutil
CXXFLAGS += -g -O2 -g3 -falign-loops=16 -shared -fPIC

$(SHARED_LIB): $(SRC)
	gcc $(DEFINES) $(INCLUDES) $(CXXFLAGS) $^ -o $@

$(RELEASEDIR)$(SHARED_LIB): $(SHARED_LIB)
	cp $(SHARED_LIB) $(RELEASEDIR)$(SHARED_LIB)

clean:
	rm -f $(SHARED_LIB)
