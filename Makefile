##########################################################
#
#                    The Top level Makefile
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2011.08.31
# Comment:   Try to re-structure the Project Makefile
#            
#
###########################################################
###########################################################
#     Project name
#     Selection: Smart831
export PROJ     := Smart831
export EXEC     := mytool
###########################################################
#     Select which cross compiler tools to be used
#     Selection: armv41,armv42,armv64 or x86; 
#     default value is x86
export COMPILE  :=

ifeq ($(COMPILE),armv41)
	CROSS := /opt/host/armv4l/bin/armv4l-unknown-linux-
endif
ifeq ($(COMPILE),armv42)
	CROSS := /opt/host/arm41_new/bin/arm-unknown-linux-gnu-
endif
ifeq ($(COMPILE),armv64)
	CROSS := /opt/host/gcc-4.1.1-glibc-2.3.2/arm-9tdmi-linux-gnu/bin/arm-9tdmi-linux-gnu-
endif
ifeq ($(COMPILE),armv64-2)
	CROSS := /opt/host/arm-kevin-linux-gnueabi/bin/arm-kevin-linux-gnueabi-
endif

ifeq ($(COMPILE),x86)
	CROSS ?=
endif
CROSS ?=
###########################################################
export MAKE_DIR := $(PWD)
export PARENTS_DIR := $(dir $(MAKE_DIR))
export DIR_NAME    := $(notdir $(MAKE_DIR))
export INST_DIR     := /tftpboot/
export INST_NAME    := main 
###########################################################
export CROSS
export CC := $(CROSS)gcc
export CPP := $(CROSS)g++
export RM := rm
export AR := $(CROSS)ar
export AS := $(CROSS)as
export STRIP := $(CROSS)strip
export FLAG := -lpthread -Wall

.PHONY : all
all:
	$(make_command)
.PHONY : clean 
clean:
	@set -e;cd src;$(MAKE) $(MAKECMDGOALS)
	@$(RM) -f $(MAKE_DIR)/bin/$(EXEC)
.PHONY : install 
install: 
	@echo Copy  $(MAKE_DIR)/bin/$(EXEC) to $(INST_DIR)$(INST_NAME)
	@cp $(MAKE_DIR)/bin/$(EXEC) $(INST_DIR)$(INST_NAME)
.PHONY : tar 
tar: 
	@echo tar the Smart serial project 
	@cd $(PARENTS_DIR);tar -cjf $(DIR_NAME).tar.bz2 $(DIR_NAME);cd $(MAKE_DIR) 

.PHONY : test
test:
	@test -d ./bin && make || echo Flase

###########################################################
define make_command
@cd $(MAKE_DIR)/src;$(MAKE) $(MAKECMDGOALS)
@cp $(MAKE_DIR)/src/$(PROJ)/$(EXEC) $(MAKE_DIR)/bin/$(EXEC)
endef
