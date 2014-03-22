;;;; package.lisp

(in-package :cl-user)

(defpackage #:hash-set
  (:use #:cl)
  (:export #:hash-set
           #:list-to-hs
           #:hs-equal
           #:hs-memberp
           #:hs-insert
           #:hs-delete
           #:hs-map
           #:hs-count
           #:hs-union
           #:hs-intersection
           #:hs-cartesian-product
           #:hs-symmetric-difference
           #:hs-pretty-print))

(defpackage #:hash-set-test
  (:use #:cl
        #:fiveam
        #:hash-set))
