(in-package #:pedagogia.sort)

(defun random-vector (size)
  (let ((vector (make-array size)))
    (loop for idx below size
       do (setf (aref vector idx) (random size)))
    vector))

(defun sortedp (vector comparison-function)
  (let ((result t))
    (loop for idx below (1- (length vector))
       do (when (not (funcall comparison-function
                              (aref vector idx)
                              (aref vector (1+ idx))))
            (setf result nil)
            (return)))
    result))

(defun insertion-sort (vector comparison-function)
  (loop for idx from 1 below (length vector)
     do (loop for jdx from idx above 0
           when (funcall comparison-function
                         (aref vector jdx)
                         (aref vector (1- jdx)))
           do (rotatef (aref vector jdx)
                       (aref vector (1- jdx)))))
  vector)
