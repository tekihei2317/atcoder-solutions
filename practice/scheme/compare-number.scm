(define sub1
  (lambda (n)
    (- n 1)
  ))

(define >
  (lambda (n m)
    (cond
      ((zero? n) #f)
      ((zero? m) #t)
      (else (> (sub1 n) (sub1 m)))
    )))

(print (> 12 133))
(print (> 120 11))
(print (> 10 10))

(define <
  (lambda (n m)
    (cond
      ((zero? m) #f)
      ((zero? n) #t)
      (else (< (sub1 n) (sub1 m)))
    )
  ))

(print (< 12 133))
(print (< 120 11))
(print (< 10 10))

(define =
  (lambda (n m)
    (cond
      ((> n m) #f)
      ((< n m) #f)
      (else #t)
    )
  )
)

(print (= 12 133))
(print (= 120 11))
(print (= 10 10))
