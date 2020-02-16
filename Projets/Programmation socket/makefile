JFLAGS = -g
SRCDIR=src
BINDIR =bin
JC = javac
JVM=	java
FILE=
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES =	\
		$(SRCDIR)/Serveur.java

MAIN	=	$(SRCDIR)/Serveur

default:classes

classes: $(CLASSES:.java=.class)

run:	$(BINDIR)/$(MAIN).class
			$(JVM)$(MAIN)

clean:
	$(RM) *.class
