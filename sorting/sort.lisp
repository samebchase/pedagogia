(in-package #:pedagogia.sort)

(defun random-vector (size)
  (let ((vector (make-array size)))
    (loop for idx below size
       do (setf (aref vector idx) (random size)))
    vector))

(defun sortedp (vector ordering-fn)
  (let ((result t))
    (loop for idx below (1- (length vector))
       do (when (not (funcall ordering-fn
                              (aref vector idx)
                              (aref vector (1+ idx))))
            (setf result nil)
            (return)))
    result))

(defun insertion-sort (vector ordering-fn)
  (loop for idx from 1 below (length vector)
     do (loop for jdx from idx above 0
           when (funcall ordering-fn
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

(defun selection-sort (vector ordering-fn)
  (loop for idx below (1- (length vector))
     for idx-lower-bound = (index-of-lower-bound-in-range
                            vector ordering-fn
                            :start idx :end (1- (length vector)))
     do (rotatef (aref vector idx-lower-bound)
                 (aref vector idx)))
  vector)

(defun bubble-sort (vector ordering-fn)
  (let ((swaps-have-occured t))
    (loop while swaps-have-occured
       do (setf swaps-have-occured nil)
         (loop for idx below (1- (length vector))
            when (not (funcall ordering-fn
                               (aref vector idx)
                               (aref vector (1+ idx))))
            do (rotatef (aref vector idx)
                        (aref vector (1+ idx)))
              (setf swaps-have-occured t))))
  vector)

(defun merge-sort (vector ordering-fn)
  (labels ((merge-sort-aux (vector-aux)
             (if (<= (length vector-aux) 1)
                 vector-aux
                 (let* ((start-idx 0)
                        (end-idx (1- (length vector-aux)))
                        (mid-idx (truncate (/ (- end-idx (1+ start-idx)) 2)))
                        (left-subvector   (subseq vector-aux   start-idx  (1+ mid-idx)))
                        (right-subvector  (subseq vector-aux (1+ mid-idx) (1+ end-idx))))
                   (merge 'vector
                          (merge-sort-aux left-subvector)
                          (merge-sort-aux right-subvector) ordering-fn)))))
    (merge-sort-aux vector)))

