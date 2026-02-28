CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wno-unused-result -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

all: release

debug : CFLAGS += -g3 -O0
debug : app.exe

release : CFLAGS += -g0 -O2
release : app.exe

clean :
	$(RM) *.o *.d *.exe

app.exe : main.o inout.o process.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean debug release
