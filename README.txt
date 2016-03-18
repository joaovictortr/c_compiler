Makefile compreende dois modos:

GCC: desabilita flags de debug
    Flags podem ser modificadas em include_GCC.mk
GCCdebug: habilita flags de debug
    Flags podem ser modificadas em include_GCCdebug.mk

Como usar: make
           make TAG=GCCdebug (modo de debug)
