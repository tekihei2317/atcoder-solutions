; Chapter1
(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))

(define l (list 'bacon 'and 'eggs))
(print (atom? (car l)))
(print (atom? (quote ())))

(define lat?
  (lambda (l)
    (cond
      ((null? l) #t)
      ((atom? (car l)) (lat? (cdr l)))
      (else #f))))

(print l)
(print (lat? l))

; Chapter2
(define member?
  (lambda (a lat)
    (cond
      ((null? lat) #f)
      (else (or
        (eq? (car lat) a)
        (member? a (cdr lat)))))))

(print 'bacon_is_a_member_of_list)
(print (member? 'bacon l))
(print 'meat_is_not_a_member_of_list)
(print (member? 'meat l))

; Chapter3
(define rember
  (lambda (a lat)
    (cond
      ((null? lat) (quote ()))
      ((eq? (car lat) a) (cdr lat))
      (else (cons (car lat) (rember a (cdr lat)))))))

(print 'rember_and_from_list)
(print (rember 'and l))
(print 'rember_bacon_from_list)
(print (rember 'bacon l))
(print 'rember_meat_from_list)
(print (rember 'meat l))

(define firsts
  (lambda (l)
    (cond
      ((null? l) (quote ()))
      (else (cons (car (car l)) (firsts (cdr l)))))))

(define l2 (list (list 'five 'plums) (list 'four) (list 'eleven 'green 'oranges)))
(print l2)
(print (firsts l2))

(define insertR
  (lambda (new old lat)
    (cond
      ((null? lat) (quote ()))
      ((eq? (car lat) old) (cons old (cons new (cdr lat))))
      (else (cons (car lat) (insertR new old (cdr lat))))
    )))

(print 'insert_e_into_left_of_d)
(define l3 (list 'a 'b 'c 'd 'f 'g 'd 'h))
(print (insertR 'e 'd l3))

;Chapter4
(define add1
  (lambda (n)
    (+ n 1)
  ))

(define sub1
  (lambda (n)
    (- n 1)
  ))

(print (add1 10))
(print (sub1 10))

(define +
  (lambda (n m)
    (cond
      ((zero? m) n)
      (else (+ (add1 n) (sub1 m)))
    )
  ))

(define -
  (lambda (n m)
    (cond
      ((zero? m) n)
      (else (- (sub1 n) (sub1 m)))
    )
  )
)

(print (zero? 0))
(print (+ 10 20))
(print (- 14 3))
