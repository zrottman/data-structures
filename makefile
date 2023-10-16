# check OS
ifeq ($(OSTYPE),cygwin)
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
else ifeq ($(OS),Windows_NT)
	CLEANUP=del /F /Q
	MKDIR=mkdir
	TARGET_EXTENSION=exe
else
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
endif

PATHU = unity/
PATHS = src/
PATHT = test/
PATHB = build/
PATHD = build/depends/
PATHO = build/objs/
PATHR = build/results/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR) # build/ build/depends/ build/objs/ build/results/

SRC = $(wildcard $(PATHS)*.c)
OBJS = $(patsubst $(PATHS)%.c, $(PATHO)%.o, $(SRC))
MAIN = $(PATHO)main.o


.PHONY : clean
.PHONY : test

# get a list of all .c files in test/
SRCT = $(wildcard $(PATHT)*.c) # test/TestNode.c test/TestLinkedList.c

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHS) -DTEST

TARGET_EXTENSION=out

# $(patsubst pattern, replacement, text)
# # find words in text that match pattern and replace with replacement
RESULTS = $(patsubst $(PATHT)Test%.c, $(PATHR)Test%.txt, $(SRCT)) # build/results/TestNode.txt build/results/TestLinkedList.txt

# make test
test : $(BUILD_PATHS) $(RESULTS)
	@echo "-------------------------\nIGNORES:\n-------------------------"
	@echo `grep -s IGNORE $(PATHR)*.txt`
	@echo "-------------------------\nFAILURES:\n------------------------"
	@echo `grep -s FAIL $(PATHR)*.txt`
	@echo "\nDONE"

$(PATHR)%.txt : $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATHB)Test%.$(TARGET_EXTENSION) : $(PATHO)Test%.o $(filter-out $(MAIN), $(OBJS)) $(PATHO)unity.o 
	$(LINK) -o $@ $^

$(PATHO)%.o : $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o : $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o :: $(PATHU)%.c $(PATHU)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHD)%.d :: $(PATHT)%.c
	$(DEPEND) $@ $<

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHD)*.d
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt

.PRECIOUS: $(PATHB)Test%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt
