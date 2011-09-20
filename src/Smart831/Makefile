##########################################################
#
#                    The Smart831 project Makefile
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2011.08.31
# Comment:   Try to re-structure the Project Makefile
#            
#
###########################################################
TXTOBJS:=OBJS
TXTDEPS:=DEPS
OBJS_DIR:=./$(TXTOBJS)/
DEPS_DIR:=./$(TXTDEPS)/
SRCS:=$(wildcard *.cpp *.c *.s)
OBJS:=$(SRCS:=.o)
DEPS:=$(SRCS:=.dep)

OBJS:=$(addprefix $(OBJS_DIR),$(OBJS))
DEPS:=$(addprefix $(DEPS_DIR),$(DEPS))

all: $(DEPS) $(EXEC)

$(DEPS_DIR)%.cpp.dep: %.cpp
	@set -e; \
	$(RM) -rf $@.tmp; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.cpp.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

$(DEPS_DIR)%.c.dep: %.c
	@set -e; \
	$(RM) -rf $@.tmp; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.c.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

$(DEPS_DIR)%.s.dep: %.s
	@set -e; \
	$(RM) -rf $@.tmp; \
	echo $@ : $^ > $@.tmp; \
	sed 's,\(.*\)\.s.dep[ :]*,\1.s.o:,g' < $@.tmp > $@; \
	sed 's/$(TXTDEPS)/$(TXTOBJS)/g' < $@.tmp > $@; \
	$(RM) $@.tmp

-include $(DEPS)

$(EXEC): $(OBJS)
	$(CPP) $(FLAG) -o $@ $^

$(addprefix $(OBJS_DIR),%.s.o): %.s
	$(AS) $< -o $@

$(addprefix $(OBJS_DIR),%.c.o): %.c
	$(CC) -O2 -c $< -o $@

$(addprefix $(OBJS_DIR),%.cpp.o): %.cpp
	$(CPP) -O2 -c $< -o $@



.PHONY: clean
clean:
	$(RM) -rf $(addprefix $(OBJS_DIR),*.o) $(addprefix $(DEPS_DIR),*.dep) $(EXEC) 
