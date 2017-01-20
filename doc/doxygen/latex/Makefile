all: refman.pdf

pdf: refman.pdf

refman.pdf: clean refman.tex
	pdflatex refman
	makeindex refman.size
	pdflatex refman
	latex_count=8 ; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' refman.log && [ $$latex_count -gt 0 ] ;\
	    do \
	      echo "Rerunning latex...." ;\
	      pdflatex refman ;\
	      latex_count=`expr $$latex_count - 1` ;\
	    done
	makeindex refman.size
	pdflatex refman


clean:
	rm -f *.ps *.dvi *.aux *.toc *.size *.ind *.ilg *.log *.out *.brf *.blg *.bbl refman.pdf
