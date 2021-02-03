; Program name: LAB2.lsp
; Author: lazzi
; Creation date: 20.09.2020
; Description:
(defun UFunc(a b)
    (if (> b 0)
        (if (< b 2)
            a
            (+ a (UFunc a (- b 1)))
        )
        0
    )
)

(defun save()
    (setq outs(open:
        "\Users\lazzi\Desktop\filp\LABS\outdata.txt"
        :direction :output))
    (setq in(read))
    (print (UFunc in) outs)
    (terpri outs)
    (close outs)
)

(trace UFunc)
