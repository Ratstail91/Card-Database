SRCDIR=source
SCRDIR=scripts
BINDIR=bin

all: debug

clean:
	$(MAKE) -C $(SRCDIR) clean
	$(RM) $(BINDIR)

release:
	$(MAKE) -C $(SRCDIR) release
	-mkdir $(BINDIR)
	$(MV) $(SRCDIR)\*.exe $(BINDIR)

debug:
	$(MAKE) -C $(SRCDIR) debug
	-mkdir $(BINDIR)
	$(MV) $(SRCDIR)\*.exe $(BINDIR)

shell:
	$(MAKE) -C $(SRCDIR) shell
	-mkdir $(BINDIR)
	$(MV) $(SRCDIR)\*.exe $(BINDIR)
	$(MV) $(SCRDIR) $(BINDIR)
