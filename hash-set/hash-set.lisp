(in-package :hash-set)

#|

Engineering guidance taken from the map-set library installable by
Quicklisp.

|#

(defclass hash-set ()
  ((table :accessor table :initform (make-hash-table))
   (size  :accessor size :initform 0))
  (:documentation "A hashset."))

(defun hs-memberp (hash-set item)
  (gethash item (table hash-set)))

(defun hs-insert (hash-set item)
  (unless (hs-memberp hash-set item)
    (push item (gethash item (table hash-set)))
    (incf (size hash-set))))
    
(defun hs-count (hash-set)
  (size hash-set))  

(defun hs-union (hash-set)
nil)

(defun hs-intersection (hash-set)
nil)

(defun hs-cartesian-product (hash-set)
nil)

(defun hs-symmetric-difference (hash-set)
nil)

(defmethod print-object ((hash-set hash-set) stream)
  (print-unreadable-object (hash-set stream :identity t :type t)
    (format stream "of count: ~a" (hs-count hash-set))))

(defun hs-pretty-print (hash-set)
  (let ((count (hs-count hash-set)))
    (with-hash-table-iterator (iterator (table hash-set))
      (format t "{")
      (loop for i from 1 to count do
           (let ((key (nth-value 1 (iterator))))
             (if (< i count)
                 (format t "~a, " key)
                 (format t "~a}" key)))))))
   
