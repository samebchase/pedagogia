(in-package :hash-set-test)

(def-suite all-tests)

(in-suite all-tests)

(test sanity
  (is (= 2 2)))

(test hs-memberp
  (let ((hash-set (make-instance 'hash-set)))
    (hs-insert hash-set 42)
    (is (hs-memberp hash-set 42))))

(test hs-count
  (let ((hash-set (make-instance 'hash-set)))
    (dotimes (i 10)
      (hs-insert hash-set i))
    (is (= 10 (hs-count hash-set)))))
      

