# ------------------------------------------
# Makefile
# Shingirai Denver Maburutse
# Date: 05/04/2021
# ------------------------------------------

CC = g++
LIBS = -lm
SRCDIR = src
BINDIR = bin
OBJDIR = obj

#$(BINDIR)/frames: $(OBJDIR)/driver.o $(OBJDIR)/FrameSequence.o
	

frames: driver.o
	$(CC) driver.o  -o frames $(LIBS)

driver.o: $(SRCDIR)/driver.cpp
	$(CC) -c $(SRCDIR)/driver.cpp

#$(OBJDIR)/FrameSequence.o: $(SRCDIR)/FrameSequence.cpp
#	$(CC) -c $(SRCDIR)/FrameSequence.cpp

clean:
	@rm -f *.o 
	@rm frames

install: 
	@mv $(BINDIR)/frames ~/bin