; Program name: LAB3.lsp
; Author: lazzi
; Creation date: 05.10.2020
; Description:
(defun UF1(a b)
    (let  ( (count b) (total 0) )
    (loop
        (cond ((= count 0) (return total)))
        (print (list 'sum total))
        (setq count (- count 1))
        (setq total (+ total a)))
    )
)


(defun length(x1 y1 x2 y2)
    (sqrt
        (+
            (expt (- x1 x2) 2)
            (expt (- y1 y2) 2)
        )
    )
)



(defun UF2()
    (print (list 'set 'x 'for 'first))
    (setf (get 'First 'x) (read))
    (print (list 'set 'y 'for 'first))
    (setf (get 'First 'y) (read))
    (print (list 'set 'x 'for 'Second))
    (setf (get 'Second 'x) (read))
    (print (list 'set 'y 'for 'Second))
    (setf (get 'Second 'y) (read))
    (print (list 'set 'x 'for 'Third))
    (setf (get 'Third 'x) (read))
    (print (list 'set 'y 'for 'Third))
    (setf (get 'Third 'y) (read))


    (setq x (list (get 'First 'x)
                    (get 'Second 'x)
                    (get 'Third 'x)))
    (setq y (list  (get 'First 'y)
                    (get 'Second 'y)      
                    (get 'Third 'y)))
    (let ((min 9999) (i 0) (j 0) (k 0) (len 0)
                (r1 0) (r2 0))
        (do ((i 0 (1+ i)))
            ((= i 2))
            (do ((j (+ i 1) (1+ j)))
                ((= j 3))
                (setq len (length (nth i x) (nth i y) (nth j x) (nth j y)))
                (when (< len min)
                    (case i
                        ((0) (setq r1 1))
                        ((1) (setq r1 2))
                        ((2) (setq r1 3))
                    )
                    (case j
                        (( 1) (setq r2 2))
                        (( 2) (setq r2 3))
                    )
                    (setq min len)
                )
            )
        )
        (print (list 'between 'cities 'with 'numbers r1 'and r2
        'is 'the 'smallest 'distance 'that 'is min))
        T
    )
)

