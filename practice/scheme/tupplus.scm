(define tup+
  (lambda (tup1 tup2)
    (cond
      ((null? tup1) (quote ()))
      (else (cons
        (+ (car tup1) (car tup2))
        (tup+ (cdr tup1) (cdr tup2))))
    )))

(print (tup+ (list 3 7) (list 4 6)))

; タプルの長さが違う場合も許容する
(define tup2+
  (lambda (tup1 tup2)
    (cond
      ((null? tup1) tup2)
      ((null? tup2) tup1)
      (else (cons
        (+ (car tup1) (car tup2))
        (tup2+ (cdr tup1) (cdr tup2))))
    )))

(print (tup2+ (list 3 7) (list 4 6 8 1)))
(print (tup2+ (list 3 7 8 1) (list 4 6)))
