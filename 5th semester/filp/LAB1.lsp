; Program name: LAB1.lsp
; Author: lazzi
; Creation date: 07.09.2020
; Description:


(defun UF1(x)

    (
        +
        (* 2 (sin x))
        (cos (* 2 x))
    )

)

(defun UF2(x)

    (
        expt
        (cos (+ x (/ 3.14 4)))
        2
    )
)

(SETQ UFR (LIST (UF1 0.5) (UF2 1)))

(SETQ X1 (REVERSE UFR))

(SETQ X2 (LIST-LENGTH UFR))

(SETQ X3 (EVAL (CONS `+ UFR)))
