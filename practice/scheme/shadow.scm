(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))

(define numbered?
  (lambda (aexp)
    (print "aexp=" aexp)
    (cond
      ((atom? aexp) (number? aexp))
      ((eq? (car (cdr aexp)) (quote +)) (and
        (numbered? (car aexp))
        (numbered? (car (cdr (cdr aexp))))))
      ((eq? (car (cdr aexp)) (quote *)) (and
        (numbered? (car aexp))
        (numbered? (car (cdr (cdr aexp))))))
      (else #f)
    )))

(define aexp (list 1 '+ 3))
(print (numbered? aexp))
(define aexp2 (list 1 '+ (list 3 '+ 2)))
(print (numbered? aexp2))

; (print (number? 1))
; (print (numbered? 1))
(define value
  (lambda (nexp)
    (print "nexp=" nexp)
    (cond
      ((number? nexp) nexp)
      ((eq? (car (cdr nexp)) '+) (+ (value (car nexp)) (value (car (cdr (cdr nexp))))))
      ((eq? (car (cdr nexp)) '*) (* (value (car nexp)) (value (car (cdr (cdr nexp))))))
  )))

(define 1st-sub-exp
  (lambda (aexp)
    (car (cdr aexp))))

(define 2nd-sub-exp
  (lambda (aexp)
    (car (cdr (cdr aexp)))))

(define operator
  (lambda (aexp)
    (car aexp)))

; Schemeと同じような、逆ポーランド記法の式を評価する
(define value2
  (lambda (nexp)
    (print "nexp=" nexp)
    (cond
      ((number? nexp) nexp)
      ((eq? (operator nexp) '+) (+ (value2 (1st-sub-exp nexp)) (value2 (2nd-sub-exp nexp))))
      ((eq? (operator nexp) '*) (* (value2 (1st-sub-exp nexp)) (value2 (2nd-sub-exp nexp))))
  )))

(print '===普通の式の評価)
(define nexp (list 1 '+ (list 3 '* 4)))
(print (value nexp))

(print '===逆ポーランド記法の式の評価)
(define nexp2 (list '+ 1 (list '* 3 4)))
(print (value2 nexp2))
