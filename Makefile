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
	

extractor: driver.o FrameSequence.o
	$(CC) driver.o FrameSequence.o -o extractor $(LIBS)

driver.o: $(SRCDIR)/driver.cpp 
	$(CC) -c $(SRCDIR)/driver.cpp

FrameSequence.o: $(SRCDIR)/FrameSequence.cpp
	$(CC) -c $(SRCDIR)/FrameSequence.cpp

clean:
	@rm -f *.o 
	@rm frames
	@rm -f ./img/*.pgm

install: 
	@mv $(BINDIR)/extractor ~/bin