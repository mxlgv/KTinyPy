NAME=tinypy
CC = kos32-gcc
LD = kos32-ld

LDFLAGS = -static -nostdlib -T $(SDK_DIR)/sources/newlib/app.lds \
          --image-base 0 -lgcc -lc.dll

CFLAGS = -U_Win32 -U_WIN32 -U__MINGW32__ -mpreferred-stack-boundary=2 \
			-mincoming-stack-boundary=2 -fno-builtin -fno-common

INCLUDES= -I. -I$(SDK_DIR)/sources/newlib/libc/include
LIBPATH:= -L $(SDK_DIR)/lib -L /home/autobuild/tools/win32/mingw32/lib

STD_MODULES= ../std_modules/kolibri/init.o
		
OBJECTS =  tpmain.o $(STD_MODULES)

all:$(NAME)

$(NAME): $(OBJECTS)
	$(LD) $(LIBPATH) --subsystem native -o $@ $(OBJECTS) $(LDFLAGS) -n -Map $(NAME).map
	kos32-objcopy $@ -O binary
	kpack $@

%.o : %.c Makefile	
	$(CC) -c $(INCLUDES) $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME).map $(OBJECTS)
