GCC=g++
PRG=gcc.exe
GCCFLAGS=-O2 -Wall -Wextra -ansi -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -Wsign-promo  -Wctor-dtor-privacy -Wnon-virtual-dtor -Wreorder

MSC=cl
MSCFLAGS=/EHa /W4 /Za /Zc:forScope /nologo /D_CRT_SECURE_NO_DEPRECATE /D"_SECURE_SCL 0" /O2i /GL

VALGRIND_OPTIONS=-q --leak-check=full
DIFFLAGS=--strip-trailing-cr -y --suppress-common-lines

OBJECTS0=lis.cpp
DRIVER0=driver.cpp

OSTYPE := $(shell uname)
ifeq (,$(findstring CYGWIN,$(OSTYPE)))
CYGWIN=
else
CYGWIN=-Wl,--enable-auto-import
endif

gcc0:
	$(GCC) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS) $(INCLUDE) $(DEFINE) $(CYGWIN) -o $(PRG)
msc0:
	$(MSC) /Fe$@.exe $(DRIVER0) $(OBJECTS0) $(MSCFLAGS) $(MSCINCLUDE)  $(MSCDEFINE)
0 1 2:
	@echo "running test$@"
	@echo "should run in less than 800 ms"
	./$(PRG) $@ >studentout$@
	diff out$@ studentout$@ $(DIFFLAGS) > difference$@
3:
	@echo "running test$@"
	@echo "should run in less than 2000 ms"
	./$(PRG) $@ >studentout$@
	diff out$@ studentout$@ $(DIFFLAGS) > difference$@
mem1:
	@echo "running memory test $@"
	@echo "should run in less than 2000 ms"
	valgrind $(VALGRIND_OPTIONS) ./$(PRG) $(subst mem,,$@) 1>/dev/null 2>difference$@
	@echo "lines after this are memory errors"; cat difference$@
clean:
	rm -f *gcno *gcda *gcov *.exe *.o *.obj *.tds studentout* difference*