MAIN=report

SRCTEX=$(wildcard *.tex)

all: $(MAIN).pdf

$(MAIN).pdf: $(SRCTEX)
	rubber --pdf $(MAIN);
	@rm -f *~ *.aux	*.log *.bbl *.blg *.vrb \
	       *.toc *.nav *.out *.snm *.idx *.ilg *.ind	

clean:
	rubber --pdf --clean
	@rm -f *~ *.aux *.log *.bbl *.blg *.vrb \
	       *.toc *.nav *.out *.snm *.idx *.ilg *.ind

distclean: clean
	@rm -fr $(MAIN).pdf

help:
	@echo -e "Makefile usage :\n\
		  - make [all]\t\tbuild the report\n\
		  - make clean\t\terase unuseful files\n\
		  - make distclean\terase all produced files\n\
		  - make help\t\tdisplay this help"
