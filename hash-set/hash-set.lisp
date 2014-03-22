(in-package :hash-set)

#|

Engineering guidance taken from the map-set library installable by
Quicklisp.

|#

(defclass hash-set ()
  ((table :accessor table :initform (make-hash-table))
   (size  :accessor size :initform 0))
  (:documentation "A hashset."))

(defun list-to-hs (list)
  (let ((hash-set (make-instance 'hash-set)))
    (loop for elt in list do
         (hs-insert hash-set elt))
    hash-set))

(defun hs-equal (hs-a hs-b)
  nil)

(defun hs-memberp (hash-set item)
  (gethash item (table hash-set)))

(defun hs-insert (hash-set item)
  (unless (hs-memberp hash-set item)
    (push item (gethash item (table hash-set)))
    (incf (size hash-set))))

(defun hs-delete (hash-set item)
  (unless (hs-memberp hash-set item)
    (push item (gethash item (table hash-set)))
    (incf (size hash-set))))

(defun hs-count (hash-set)
  (size hash-set))  


(defun hs-map (hash-set function)
nil)

(defun hs-union (hs-a hs-b)
nil)

(defun hs-intersection (hs-a hs-b)
nil)

(defun hs-cartesian-product (hs-a hs-b)
nil)

(defun hs-symmetric-difference (hs-a hs-b)
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
   
