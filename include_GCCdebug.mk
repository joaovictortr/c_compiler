CC  = gcc
CXX = g++
FC  = gfortran
LINKER = $(CXX)

ANSI_CFLAGS  = -ansi
ANSI_CFLAGS += -std=c++0x
ANSI_CFLAGS += -pedantic
ANSI_CFLAGS += -Wextra

CFLAGS   = -O2 -Wno-format -Wall $(ANSI_CFLAGS)
CXXFLAGS = $(CFLAGS)
FCFLAGS  = 
CPPFLAGS = -std=c++0x
LFLAGS   = -lboost_regex
DEFINES  = -D_GNU_SOURCE -g
INCLUDES =
LIBS     = -lboost_regex
