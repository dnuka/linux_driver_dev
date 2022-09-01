ARCH := x86
CROSS_COMPILE := x86_64-linux-gnu-

obj-m = hello_world.o

KDIR := /home/dhanuka/code/kernel/linux
PWD := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
