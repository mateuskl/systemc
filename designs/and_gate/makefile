DESIGN := and.elf

CXX := g++
TARGET_ARCH := linux

all: main_target
	

.SUFFIXES: .o .cc


CC_FILES := $(shell find . -name "*.cc" -type f)
OBJECTS := $(subst .cc,.o,$(CC_FILES))

SYSTEMC_PATH := /usr/local/local_programs/systemc/systemc-2.2.0

INC := -I. -I$(SYSTEMC_PATH)/include
LIBDIR := -L$(SYSTEMC_PATH)/lib-$(TARGET_ARCH)

LIBS   :=  -lsystemc -lm


# Related to scoot -------------------------------------------------------------
SRC := $(CC_FILES)

INCLUDE := $(INC)

SCOOT_OPT = -D SCOOT_SKIP_NOTIFICATION_PHASES

include /usr/local/local_programs/scoot/common.mk


# ------------------------------------------------------------------------------


# Related to CBMC --------------------------------------------------------------
SCOOT_OUT := scoot_out.cpp
INCLUDES_FOR_CBMC := /usr/local/local_programs/scoot/include/bv

check:
	cbmc $(SCOOT_OUT) --bounds-check --pointer-check -I $(INCLUDES_FOR_CBMC) -I /usr/local/local_programs/scoot/include/stl -I /usr/local/local_programs/scoot/include/systemc -I /usr/local/local_programs/scoot/include/tlm -I /usr/local/local_programs/scoot/include


# ------------------------------------------------------------------------------

main_target: $(OBJECTS) $(SYSTEMC_PATH)/lib-$(TARGET_ARCH)/libsystemc.a
	$(CXX) $(OBJECTS) $(LIBS) $(LIBDIR) -o $(DESIGN)



.cc.o :
	$(CXX) $(INC) -Werror -c -o $@ $<


cleandesign:
	rm -f $(OBJECTS) *~ $(DESIGN)

