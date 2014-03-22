(defclass hash-set ()
  ((table :accessor table :initform (make-hash-table))
   (size  :accessor size :initform 0))
  (:documentation "A hashset."))

(defun memberp (hash-set item)
  (nth-value 1 (gethash item (table hash-set))))

(defun insert (hash-set item)
  (unless (memberp hash-set item)
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

(defmethod print-object ((set hash-set) stream)
  (print-unreadable-object (set stream :identity t :type t)
    (format stream "of count: ~a" (size set))))

(defun hs-pretty-print (hash-set)
  (let ((count (hs-count hash-set)))
    (with-hash-table-iterator (iterator (table set))
      (format t "{")
      (loop for i from 1 to count do
           (let ((key (nth-value 1 (iterator))))
             (if (< i count)
                 (format t "~a, " key)
                 (format t "~a}" key)))))))
   
