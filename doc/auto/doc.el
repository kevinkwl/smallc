(TeX-add-style-hook
 "doc"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("helvet" "scaled") ("fontenc" "T1") ("inputenc" "utf8") ("ulem" "normalem")))
   (add-to-list 'LaTeX-verbatim-environments-local "minted")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "helvet"
    "eulervm"
    "fontenc"
    "inputenc"
    "fixltx2e"
    "graphicx"
    "grffile"
    "longtable"
    "wrapfig"
    "rotating"
    "ulem"
    "amsmath"
    "textcomp"
    "amssymb"
    "capt-of"
    "hyperref"
    "minted")
   (LaTeX-add-labels
    "sec:orgheadline5"
    "sec:orgheadline1"
    "sec:orgheadline2"
    "sec:orgheadline3"
    "sec:orgheadline4"
    "sec:orgheadline8"
    "sec:orgheadline6"
    "sec:orgheadline7"
    "sec:orgheadline18"
    "sec:orgheadline9"
    "sec:orgheadline12"
    "sec:orgheadline10"
    "sec:orgheadline11"
    "sec:orgheadline17"
    "sec:orgheadline13"
    "sec:orgheadline14"
    "sec:orgheadline15"
    "sec:orgheadline16"
    "sec:orgheadline27"
    "sec:orgheadline19"
    "sec:orgheadline20"
    "sec:orgheadline21"
    "sec:orgheadline26"
    "sec:orgheadline22"
    "sec:orgheadline23"
    "sec:orgheadline24"
    "sec:orgheadline25"
    "sec:orgheadline30"
    "sec:orgheadline28"
    "orgtarget1"
    "sec:orgheadline29"))
 :latex)

