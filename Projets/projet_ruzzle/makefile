# Definiton des alias
SRCDIR=src
LIBDIR=lib
BINDIR=bin
DOCDIR=doc
INCLUDEDIR=include
TESTDIR=test
CC = gcc
CFLAGS = -Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)
TFLAGS = -lcunit
DOX = projetconfig


# La commande make les.o permet de génerer tout les .o associé au .c du dossier src
lesO:
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/ArbreBinaireDeLettres.o $(SRCDIR)/ArbreBinaireDeLettres.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/Case.o $(SRCDIR)/Case.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/CasesContigues.o $(SRCDIR)/CasesContigues.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/Dictionnaire.o $(SRCDIR)/Dictionnaire.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/Grille.o $(SRCDIR)/Grille.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/ListeOrdonnee.o $(SRCDIR)/ListeOrdonnee.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/mot.o $(SRCDIR)/mot.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/serialiserDico.o $(SRCDIR)/serialiserDico.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testArbreBinaireDeLettres.o $(SRCDIR)/testArbreBinaireDeLettres.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testListeOrdonnee.o $(SRCDIR)/testListeOrdonnee.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testCase.o $(SRCDIR)/testCase.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testCasesContigues.o $(SRCDIR)/testCasesContigues.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testDictionnaire.o $(SRCDIR)/testDictionnaire.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testGrille.o $(SRCDIR)/testGrille.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testMot.o $(SRCDIR)/testMot.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/FonctionsPrincipales.o $(SRCDIR)/FonctionsPrincipales.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/testFonctionsPrincipales.o $(SRCDIR)/testFonctionsPrincipales.c
	$(CC) $(CFLAGS)   -c -o $(SRCDIR)/main.o $(SRCDIR)/main.c


# la commande make serialiser permet de sérialiser le Dictionnaire
serialiser:

	$(CC) -o $(BINDIR)/serialiserDico $(SRCDIR)/serialiserDico.o $(SRCDIR)/Dictionnaire.o $(SRCDIR)/ArbreBinaireDeLettres.o $(SRCDIR)/mot.o -lc
	./$(BINDIR)/serialiserDico

exe:
	$(CC) -o $(BINDIR)/exec $(SRCDIR)/ArbreBinaireDeLettres.o $(SRCDIR)/Case.o $(SRCDIR)/CasesContigues.o $(SRCDIR)/Dictionnaire.o $(SRCDIR)/FonctionsPrincipales.o $(SRCDIR)/Grille.o $(SRCDIR)/ListeOrdonnee.o $(SRCDIR)/main.o $(SRCDIR)/mot.o

# La commande make doc permet de génerer la documentation à l'aide de doxygen

rmdoc:
	rm -rf $(DOCDIR)

doc: rmdoc
		doxygen "projetconfig"

# La commande make test permet de génerer tout les tests unitaires
tests:

	$(CC) -o $(TESTDIR)/testArbreBinaireDeLettres $(SRCDIR)/ArbreBinaireDeLettres.o $(SRCDIR)/testArbreBinaireDeLettres.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testCase $(SRCDIR)/Case.o $(SRCDIR)/testCase.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testListeOrdonnee $(SRCDIR)/ListeOrdonnee.o $(SRCDIR)/testListeOrdonnee.o $(SRCDIR)/mot.o $(SRCDIR)/Case.o $(SRCDIR)/CasesContigues.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testCasesContigues $(SRCDIR)/CasesContigues.o $(SRCDIR)/testCasesContigues.o $(SRCDIR)/Case.o $(SRCDIR)/mot.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testDictionnaire $(SRCDIR)/Dictionnaire.o $(SRCDIR)/testDictionnaire.o $(SRCDIR)/mot.o $(SRCDIR)/ArbreBinaireDeLettres.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testGrille $(SRCDIR)/Grille.o $(SRCDIR)/testGrille.o $(SRCDIR)/Case.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testMot $(SRCDIR)/mot.o $(SRCDIR)/testMot.o $(TFLAGS)
	$(CC) -o $(TESTDIR)/testFonctionsPrincipales $(SRCDIR)/ArbreBinaireDeLettres.o $(SRCDIR)/Case.o $(SRCDIR)/CasesContigues.o $(SRCDIR)/Dictionnaire.o $(SRCDIR)/Grille.o $(SRCDIR)/ListeOrdonnee.o  $(SRCDIR)/mot.o  $(SRCDIR)/FonctionsPrincipales.o $(SRCDIR)/testFonctionsPrincipales.o $(TFLAGS)

# La commande make all permet de "tout" faire
all : lesO tests serialiser doc exe

# La commande make clean permet de nettoyer les fichiers ne contenant pas du code.
clean : rmdoc
	rm $(INCLUDEDIR)/dico-serialise.txt
	rm -rf $(BINDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
