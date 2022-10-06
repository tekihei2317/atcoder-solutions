(define addtup
  (lambda (tup)
    (cond
      ((null? tup) 0)
      (else (+ (car tup) (addtup (cdr tup))))
    )))

(print (addtup (list 3 5 2 8)))
