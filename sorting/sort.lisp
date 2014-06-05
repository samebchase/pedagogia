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

(defun index-of-lower-bound-in-range (vector ordering-fn
                                      &key start end)
  (let ((idx-lower-bound start)
        (current-lower-bound (aref vector start)))
    (loop for idx from start upto end
       do (let ((current-elt (aref vector idx)))
            (when (funcall ordering-fn
                           current-elt
                           current-lower-bound)
              (setf current-lower-bound current-elt)
              (setf idx-lower-bound idx))))
    idx-lower-bound))

(defun selection-sort (vector comparison-function)
  (loop for idx below (1- (length vector))
     for idx-lower-bound = (index-of-lower-bound-in-range
                            vector comparison-function
                            :start idx :end (1- (length vector)))
     do (rotatef (aref vector idx-lower-bound)
                 (aref vector idx)))
  vector)
