# ==========================================
#   String Buffer Project - A safe string library for C
#   Copyright (c) 2023 Alex Fabre
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

# GCC flags
CFLAGS=-std=c2x
CFLAGS += -c
CFLAGS += -Os
CFLAGS += -DNDEBUG
CFLAGS += -DUNITY_EXCLUDE_FLOAT
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wswitch-enum
CFLAGS += -Wconversion
CFLAGS += -Wsign-conversion
CFLAGS += -Wnull-dereference
CFLAGS += -Wshadow
CFLAGS += -Wformat=2
CFLAGS += -Wfloat-equal
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

# Set project directory two level above of Makefile directory.
SOURCEDIR := ../../
BUILDDIR := build/

# Decide whether the commands will be shwon or not
VERBOSE = FALSE

# Create the list of directories
DIRS = src examples/basic_usage
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(SOURCEDIR), $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR), $(dir)))

# Generate the GCC includes parameters by adding -I before each source folder
INCLUDES = $(foreach dir, $(SOURCEDIRS), $(addprefix -I, $(dir)))

# Add this list to VPATH, the place make will look for the source files
VPATH = $(SOURCEDIRS)

# Create a list of *.c sources in DIRS
SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.c))

# Define objects for all sources
OBJS := $(subst $(SOURCEDIR),$(BUILDDIR),$(SOURCES:.c=.o))

# Define dependencies files for all objects
DEPS = $(OBJS:.o=.d)

# OS specific part
ifeq ($(OS),Windows_NT)
	ifeq ($(shell uname -s),) # not in a bash-like shell
		RM = del /F /Q 
		RMDIR = -RMDIR /S /Q
		MKDIR = -mkdir
		ERRIGNORE = 2>NUL || true
		SEP=\\
	else # in a bash-like shell, like msys
		RM = rm -rf 
		RMDIR = rm -rf 
		MKDIR = mkdir -p
		ERRIGNORE = 2>/dev/null
		SEP=/
	endif
		TARGET_EXTENSION=.exe
else
	RM = rm -rf 
	RMDIR = rm -rf 
	MKDIR = mkdir -p
	ERRIGNORE = 2>/dev/null
	SEP=/
	TARGET_EXTENSION=.out
endif

# Name the compiler
CC = gcc
ifeq ($(shell uname -s), Darwin)
CC = clang
endif

# Name of the final executable
TARGET = basic_usage$(TARGET_EXTENSION)

# Remove space after separator
PSEP = $(strip $(SEP))

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
	HIDE =  
else
	HIDE = @
endif

# Define the function that will generate each rule
define generateRules
$(1)/%.o: %.c
	@echo Building $$@
	$(HIDE)$(CC) -c $(CFLAGS) $$(INCLUDES) -o $$(subst /,$$(PSEP),$$@) $$(subst /,$$(PSEP),$$<) -MMD
endef


#------------------------------------------------------------------------------
# Build

all: clean build

build: directories $(TARGET)

$(TARGET): $(OBJS)
	$(HIDE)echo Linking $@
	$(HIDE)$(CC) $(OBJS) -o $(TARGET)

# Include dependencies
-include $(DEPS)

# Generate rules
$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories: 
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)

# Remove all objects, dependencies and executable files generated during the build
clean:
	$(HIDE)$(RMDIR) $(BUILDDIR) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo Cleaning done ! 

.PHONY: all build clean directories
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Code quality

FORMAT_SOURCE_DIR = $(SOURCEDIR)src ./ 

# shellcheck 0.9.0
shellcheck:
	@shellcheck $(SOURCEDIR)scripts/*.sh
	@echo $$(find $(SOURCEDIR)scripts -type f -name '*.sh'):PASS

# clang-format on project code
format:
	@bash $(SOURCEDIR)scripts/clang-format-all.sh $(FORMAT_SOURCE_DIR)

# CI check format.
# Applying format should not modify any file
ci_check_format:
	@$(MAKE) --no-print-directory format
	# Checking no file is modified
	@git diff --exit-code
	# Checking no files is untracked
	# This generates spurious text when ok:
	#	"error: pathspec ... did not match any file(s) known to git.
	#	 Did you forget to 'git add'?"
	@git ls-files --others --exclude-standard --error-unmatch
	# OK
	@echo "Repo is ok"

# Clang static analysis (scan-build)
scan:
	@$(MAKE) --no-print-directory clean
	@scan-build --use-cc=gcc-13 -o docs/scan-report/ make build

.PHONY: shellcheck format ci_check_format scan
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Run

run: all
	./$(TARGET)

.PHONY: run
#------------------------------------------------------------------------------
