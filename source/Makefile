# Project: arquitetura
# Compiler: Default GCC compiler
# Compiler Type: MingW 3
# Makefile created by wxDev-C++ 6.10.2 on 15/07/07 20:41

CPP       = g++
CC        = gcc
WINDRES   = windres.exe
OBJ       = obj/arquiteturaApp.o obj/arquiteturaDlg.o obj/londGrid.o obj/arquitetura.o obj/arquitetura_private.res
LINKOBJ   = obj/arquiteturaApp.o obj/arquiteturaDlg.o obj/londGrid.o obj/arquitetura.o obj/arquitetura_private.res
RCINCS    = --include-dir "C:/ARQUIV~1/Dev-Cpp/include/common"
BIN       = arquitetura
CXXFLAGS  = $(CXXINCS) $(DEFINES) -fno-exceptions -fno-pcc-struct-return -fstrict-aliasing -Wall -fexpensive-optimizations
CFLAGS    = $(INCS) $(DEFINES) -fno-exceptions -fno-pcc-struct-return -fstrict-aliasing -Wall -fexpensive-optimizations
GPROF     = gprof.exe
RM        = rm -f
LINK      = g++.exe

.PHONY: all all-before all-after clean clean-custom
all: all-before $(BIN) all-after

clean: clean-custom
	$(RM) $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(LINK) $(LINKOBJ) -o "obj/arquitetura"

obj/arquiteturaApp.o: $(GLOBALDEPS) arquiteturaApp.cpp
	$(CPP) -c arquiteturaApp.cpp -o obj/arquiteturaApp.o $(CXXFLAGS) `wx-config --cppflags`

obj/arquiteturaDlg.o: $(GLOBALDEPS) arquiteturaDlg.cpp
	$(CPP) -c arquiteturaDlg.cpp -o obj/arquiteturaDlg.o $(CXXFLAGS) `wx-config --cppflags`

obj/londGrid.o: $(GLOBALDEPS) londGrid.cpp
	$(CPP) -c londGrid.cpp -o obj/londGrid.o $(CXXFLAGS) `wx-config --cppflags`

obj/arquitetura.o: $(GLOBALDEPS) arquitetura.cpp
	$(CPP) -c arquitetura.cpp -o obj/arquitetura.o $(CXXFLAGS) `wx-config --cppflags`

obj/arquitetura_private.res: obj/arquitetura_private.rc arquiteturaApp.rc
	$(WINDRES) --input-format=rc -o obj/arquitetura_private.res $(RCINCS) obj/ARQUIT~1.RC -O coff
