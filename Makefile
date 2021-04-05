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
	
$(OBJDIR)/driver.o: $(SRCDIR)/driver.cpp
	$(CC) -c $(SRCDIR)/driver.cpp

$(BINDIR)/frames: $(OBJDIR)/driver.o
	$(CC) $(OBJDIR)/driver.o  -o $(BINDIR)/frames $(LIBS)



#$(OBJDIR)/FrameSequence.o: $(SRCDIR)/FrameSequence.cpp
#	$(CC) -c $(SRCDIR)/FrameSequence.cpp

clean:
	rm $(OBJDIR)/*.o $(BINDIR)/frames

install: 
	@mv $(BINDIR)/frames ~/bin