(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))

(define rember*
  (lambda (a l)
    (cond
      ((null? l) (quote ()))
      ((atom? (car l))
        (cond
          ((eq? (car l) a) (rember* a (cdr l)))
          (else (cons (car l) (rember* a (cdr l))))))
      (else
        (cons
          (rember* a (car l))
          (rember* a (cdr l)))))))

(define l (list (list 'coffee) 'cup (list (list 'tea) 'cup) (list 'and (list 'hick)) 'cup))
(print l)
(print (rember* 'cup l))

(define insertR*
  (lambda (new old l)
    (cond
      ((null? l) (quote ()))
      ((atom? (car l))
        (cond
          ((eq? (car l) old) (cons old (cons new (insertR* new old (cdr l)))))
          (else (cons (car l) (insertR* new old (cdr l))))))
    (else
      (cons (insertR* new old (car l)) (insertR* new old (cdr l)))))))

(define l2 (list (list 'how 'much (list 'wood)) 'could (list (list 'a (list 'wood) 'chuck)) (list (list (list 'chuck))) (list 'if (list 'a) (list (list 'wood 'chuck))) 'could 'chuck 'wood))
(print l2)
(print (insertR* 'roast 'chuck l2))
