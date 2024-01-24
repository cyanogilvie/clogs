DESTDIR =
PREFIX = /usr/local

VER = 0.1

CC = gcc
AR = ar
RANLIB = ranlib
VALGRIND = valgrind
DEBUG = 0
DEFS = 

CFLAGS = -std=gnu17 -fPIC -Wall -Wextra -Werror -Wpointer-arith -Wno-missing-braces -Wno-missing-field-initializers -Wno-unused-parameter -I. -DDEBUG=$(DEBUG) $(DEFS)
CFLAGS_DEBUG = -ggdb3 -Og -DPURIFY
CFLAGS_OPTIMIZE = -ggdb3 -Ofast -march=native -mtune=native -flto
CFLAGS_PROFILE = -pg
LDFLAGS =
PGO =
VALGRINDARGS_EXTRA = 
VALGRINDARGS	= --tool=memcheck --num-callers=8 --leak-resolution=high \
		  --leak-check=yes -v --suppressions=suppressions --keep-debuginfo=yes \
		  --trace-children=yes $(VALGRINDARGS_EXTRA)
CACHEGRINDARGS	= --tool=cachegrind --cachegrind-out-file=cachegrind.out --cache-sim=yes --branch-sim=no
TESTARGS = a b c d e f j k l m n o p q r s t u v w x y z

C_OBJS = clogs.o
OBJS = $(C_OBJS)

all: libclogs.a libclogs_dbg.a

$(C_OBJS): %.o: %.c Makefile
	$(CC) -c $(CFLAGS) $(CFLAGS_OPTIMIZE) $(PGO) -o $@ $<

libclogs.a: $(OBJS)
	echo "create $@\n $(foreach mod,$(OBJS),addmod $(mod)\n) save\n end\n" | $(AR) -M
	$(RANLIB) $@

libclogs$(VER).so: $(OBJS)
	$(CC) -o $@ --shared -fPIC $(OBJS)

testex: testex.c libclogs.a
	$(CC) testex.c -o $@ $(CFLAGS) $(CFLAGS_OPTIMIZE) $(LDFLAGS) $(PGO) -L. -lclogs


# Debug
$(addprefix dbg_,$(C_OBJS)): dbg_%.o: %.c Makefile
	$(CC) -c $(CFLAGS) $(CFLAGS_DEBUG) $(PGO) -o $@ $<

libclogs_dbg.a: $(addprefix dbg_,$(OBJS))
	echo "create $@\n $(foreach mod,$(addprefix dbg_,$(OBJS)),addmod $(mod)\n) save\n end\n" | $(AR) -M
	$(RANLIB) $@

dbg_testex: testex.c libclogs_dbg.a
	$(CC) testex.c -o $@ $(CFLAGS) $(CFLAGS_DEBUG) $(LDFLAGS) $(PGO) -L. -lclogs_dbg


# Profile
$(addprefix prof_,$(C_OBJS)): prof_%.o: %.c Makefile
	$(CC) -c $(CFLAGS) $(CFLAGS_PROFILE) $(PGO) -o $@ $<

libclogs_prof.a: $(addprefix prof_,$(OBJS))
	echo "create $@\n $(foreach mod,$(addprefix prof_,$(OBJS)),addmod $(mod)\n) save\n end\n" | $(AR) -M
	$(RANLIB) $@

prof_testex: testex.c libclogs_prof.a
	$(CC) testex.c -o $@ $(CFLAGS) $(CFLAGS_DEBUG) $(LDFLAGS) $(PGO) -L. -lclogs_prof


vim-gdb: dbg_testex tags
	vim -c "set number" -c "set mouse=a" -c "set foldlevel=100" -c "Termdebug -ex set\ print\ pretty\ on --args ./dbg_testex $(wordlist 1,15,$(TESTARGS))" -c "2windo set nonumber" -c "1windo set nonumber" testex.c

test: testex
	./$< $(TESTARGS)

valgrind: dbg_testex
	$(VALGRIND) $(VALGRINDARGS) ./$< $(TESTARGS)

cachegrind: testex
	-rm cachegrind.out
	$(VALGRIND) $(CACHEGRINDARGS) ./$< $(TESTARGS)

profile: prof_testex
	./$< $(TESTARGS)

perf: testex
	sudo perf record ./$< $(TESTARGS)

perfstats: testex
	sudo perf stat ./$< $(TESTARGS)

tags: *.def *.h *.c Makefile
	-ctags-exuberant --recurse=yes --langmap=c:+.def *.c *.h *.defs

clean:
	-rm -f core testex dbg_testex prof_testex libclogs.a libclogs_dbg.a libclogs_prof.a libclogs*.so $(OBJS) $(addprefix dbg_,$(OBJS)) $(addprefix prof_,$(OBJS)) tags cachegrind.out gmon.out

install: libclogs.a libclogs$(VER).so clogs*.def
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include
	cp libclogs.a $(DESTDIR)$(PREFIX)/lib/
	cp libclogs$(VER).so $(DESTDIR)$(PREFIX)/lib/
	cp clogs.h clogs*.defs $(DESTDIR)$(PREFIX)/include/

install_dbg: libclogs_dbg.a clogs*.def
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include
	cp libclogs_dbg.a $(DESTDIR)$(PREFIX)/lib/
	cp clogs.h clogs*.defs $(DESTDIR)$(PREFIX)/include/

uninstall:
	-rm -f $(DESTDIR)$(PREFIX)/lib/libclogs.a
	-rm -f $(DESTDIR)$(PREFIX)/lib/libclogs_dbg.a
	-rm -f $(DESTDIR)$(PREFIX)/lib/libclogs*.so
	-rm -f $(DESTDIR)$(PREFIX)/include/clogs.h
	-rm -f $(DESTDIR)$(PREFIX)/include/clogs*.def

.PHONY: all clean vim-gdb valgrind cachegrind install uninstall test profile perf perfstats

