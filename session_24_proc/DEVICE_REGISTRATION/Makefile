INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m :=test_mod.o

test_mod-objs := init.o cleanup.o releaseMyDev.o openMyDev.o  trimDev.o writeMyDev.o readMyDev.o validIOCheck.o creatScull.o lseekDev.o
else
	KERNELDIR ?= /lib/modules/4.16.9/build
#	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
