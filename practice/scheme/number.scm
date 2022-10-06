(define sub1
  (lambda (n)
    (- n 1)
  ))

(define t
  (lambda (n m)
    (cond
      ((zero? m) 1)
      (else (* n (t n (sub1 m))))
    )
  )
)

(print (t 1 1))
(print (t 2 3))
(print (t 5 3))

(define add1
  (lambda (n)
    (+ n 1)
  ))

(define div
  (lambda (n m)
    (cond
      ((< n m) 0)
      (else (add1 (div (- n m) m)))
    )
  ))

(print (div 15 4))
(print (div 16 4))
