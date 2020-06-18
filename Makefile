.PHONY: all clean help
.PHONY: u-boot kernel kernel-config
.PHONY: linux pack

include chosen_board.mk

CROSS_COMPILE=$(COMPILE_TOOL)/arm-linux-gnueabihf-
U_CROSS_COMPILE=$(CROSS_COMPILE)
K_CROSS_COMPILE=$(CROSS_COMPILE)

ROOTFS=$(CURDIR)/rootfs/linux/default_linux_rootfs.tar.gz

Q=
J=$(shell expr `grep ^processor /proc/cpuinfo  | wc -l` \* 2)

all: bsp
bsp: u-boot kernel

u-boot:
	$(Q)$(MAKE) -C u-boot-sp $(UBOOT_CONFIG) CROSS_COMPILE=$(U_CROSS_COMPILE) -j$J
	$(Q)$(MAKE) -C u-boot-sp all CROSS_COMPILE=$(U_CROSS_COMPILE) -j$J

u-boot-clean:
	$(Q)$(MAKE) -C u-boot-sp CROSS_COMPILE=$(U_CROSS_COMPILE) -j$J distclean

kernel:
	$(Q)$(MAKE) -C linux-sp ARCH=$(ARCH) $(KERNEL_CONFIG) CROSS_COMPILE=${K_CROSS_COMPILE}
	$(Q)$(MAKE) -C linux-sp ARCH=$(ARCH) CROSS_COMPILE=${K_CROSS_COMPILE} -j$J INSTALL_MOD_PATH=output uImage dtbs
	$(Q)$(MAKE) -C linux-sp ARCH=$(ARCH) CROSS_COMPILE=${K_CROSS_COMPILE} -j$J INSTALL_MOD_PATH=output modules
	$(Q)$(MAKE) -C linux-sp ARCH=$(ARCH) CROSS_COMPILE=${K_CROSS_COMPILE} -j$J INSTALL_MOD_PATH=output modules_install
	$(Q)scripts/install_kernel_headers.sh $(K_CROSS_COMPILE)

kernel-clean:
	$(Q)$(MAKE) -C linux-sp ARCH=$(ARCH) CROSS_COMPILE=${K_CROSS_COMPILE} -j$J distclean
	rm -rf linux-sp/output/

kernel-config: $(K_DOT_CONFIG)
	$(Q)$(MAKE) -C linux-sp ARCH=$(ARCH) CROSS_COMPILE=${K_CROSS_COMPILE} -j$J menuconfig
	cp linux-sp/.config linux-sp/arch/$(ARCH)/configs/$(KERNEL_CONFIG)

clean: u-boot-clean kernel-clean
	rm -rf out/
	rm -f chosen_board.mk
	rm -f env.sh

distclean: clean
	rm -rf SD/

pack:
	$(Q)scripts/mk_pack.sh

install:
	$(Q)scripts/mk_install_sd.sh

linux: 
	$(Q)scripts/mk_linux.sh $(ROOTFS)

help:
	@echo ""
	@echo "Usage:"
	@echo "  make bsp             - Default 'make'"
	@echo "  make linux         - Build target for linux platform, as ubuntu, need permisstion confirm during the build process"
	@echo "   Arguments:"
	@echo "    ROOTFS=            - Source rootfs (ie. rootfs.tar.gz with absolute path)"
	@echo ""
	@echo "  make pack            - pack the images and rootfs to a PhenixCard download image."
	@echo "  make clean"
	@echo ""
	@echo "Optional targets:"
	@echo "  make kernel           - Builds linux kernel"
	@echo "  make kernel-config    - Menuconfig"
	@echo "  make u-boot          - Builds u-boot"
	@echo ""

