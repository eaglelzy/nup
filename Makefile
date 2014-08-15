##############################
# file   	Makefile
# author  	lizy
# date  	2014-08-15
###############################

SUBDIRS=lib intro

define make_subdir
@for subdir in $(SUBDIRS) ; do \
	( cd $$subdir && make $1) \
	done;
endef

all:
	$(call make_subdir, all)

clean:
	$(call make_subdir, clean) 
