(define add1 (lambda (n) (+ n 1)))
(define sub1 (lambda (n) (- n 1)))

(define length
  (lambda (lat)
    (cond
      ((null? lat) 0)
      (else (add1 (length (cdr lat))))
    )
  ))

(print (length (list 'hotdogs 'with 'mustard 'sauerkraut 'and 'pickles)))

(define pick
  (lambda (n lat)
    (cond
      ((= n 1) (car lat))
      (else (pick (sub1 n) (cdr lat)))
    )
  ))

(print (pick 4 (list 'lasagna 'spaghetti 'ravioli 'macaroni 'meatball)))

(define rempick
  (lambda (n lat)
    (cond
      ((= n 1) (cdr lat))
      (else (cons (car lat) (rempick (sub1 n) (cdr lat))))
    )
  ))

(print (rempick 3 (list 'hotdogs 'with 'hot 'mustard)))
