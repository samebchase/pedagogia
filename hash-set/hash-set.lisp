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

(defun hs-memberp (hash-set item)
  (gethash item (table hash-set)))

(defun hs-insert (hash-set item)
  (unless (hs-memberp hash-set item)
    (push item (gethash item (table hash-set)))
    (incf (size hash-set))))

(defun hs-delete (hash-set item)
  (when (hs-memberp hash-set item)
    (remhash item (table hash-set))
    (decf (size hash-set))))

(defun hs-count (hash-set)
  (size hash-set))  

(defun hs-map (hash-set fn)
  (let ((result (make-instance 'hash-set)))
    (with-hash-table-iterator (iterator (table hash-set))
      (loop for i from 1 to (hs-count hash-set) do
           (let ((value (nth-value 1 (iterator))))
             (hs-insert result (funcall fn value)))))
    result))

(defun hs-union (hs-a hs-b)
  (let ((count-a (hs-count hs-a))
        (count-b (hs-count hs-b))
        (result (make-instance 'hash-set)))
    (with-hash-table-iterator (iterator (table hs-a))
      (loop for i from 1 to count-a do
           (hs-insert result (nth-value 1 (iterator)))))
    (with-hash-table-iterator (iterator (table hs-b))
      (loop for i from 1 to count-b do
           (hs-insert result (nth-value 1 (iterator)))))
    result))
    
(defun hs-intersection (hs-a hs-b)
  (let ((result (make-instance 'hash-set)))
    (with-hash-table-iterator (iterator (table hs-a))
      (loop for i from 1 to (hs-count hs-a) do
           (let ((value (nth-value 1 (iterator))))
             (when (hs-memberp hs-b value)
               (hs-insert result value)))))
    result))

(defun hs-equal (hs-a hs-b)
  (if (/= (hs-count hs-a) (hs-count hs-b))
      nil
      (with-hash-table-iterator (iterator (table hs-a))
        (loop for i from 1 to (hs-count hs-a) do
             (let ((value (nth-value 1 (iterator))))
               (unless (hs-memberp hs-b value)
                 (return nil))))
        t)))

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
      (loop for i from 1 to (1- count) do
           (let ((value (nth-value 1 (iterator))))
             (format t "~a, " value)))
      (format t "~a}" (nth-value 1 (iterator))))))
   
