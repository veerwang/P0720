##########################################################
#
#                    The Main project Makefile
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2011.08.31
# Comment:   Acoording to the PROJ parameters to design 
#            which project to be constructed
#            
###########################################################
.PHONY : all
all:
	@echo Building $(PROJ) Project...                                     
	@cd $(MAKE_DIR)/src/$(PROJ);$(MAKE) $(MAKECMDGOALS)
.PHONY : clean 
clean:
	@set -e;cd $(PROJ);$(MAKE) $(MAKECMDGOALS)
