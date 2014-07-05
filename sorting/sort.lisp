(in-package #:pedagogia.sort)

(defun random-array (size)
  (let ((array (make-array size)))
    (loop for idx below size
       do (setf (aref array idx) (random size)))
    array))

(defun sortedp (array ordering-fn)
  (let ((result t))
    (loop for idx below (1- (length array))
       do (when (not (funcall ordering-fn
                              (aref array idx)
                              (aref array (1+ idx))))
            (setf result nil)
            (return)))
    result))

(defun insertion-sort (array ordering-fn)
  (loop for idx from 1 below (length array)
     do (loop for jdx from idx above 0
           when (funcall ordering-fn
                         (aref array jdx)
                         (aref array (1- jdx)))
           do (rotatef (aref array jdx)
                       (aref array (1- jdx)))))
  array)

(defun index-of-lower-bound-in-range (array ordering-fn
                                      &key start end)
  (let ((idx-lower-bound start)
        (current-lower-bound (aref array start)))
    (loop for idx from start upto end
       do (let ((current-elt (aref array idx)))
            (when (funcall ordering-fn
                           current-elt
                           current-lower-bound)
              (setf current-lower-bound current-elt)
              (setf idx-lower-bound idx))))
    idx-lower-bound))

(defun selection-sort (array ordering-fn)
  (loop for idx below (1- (length array))
     for idx-lower-bound = (index-of-lower-bound-in-range
                            array ordering-fn
                            :start idx :end (1- (length array)))
     do (rotatef (aref array idx-lower-bound)
                 (aref array idx)))
  array)

(defun bubble-sort (array ordering-fn)
  (let ((swaps-have-occured t))
    (loop while swaps-have-occured
       do (setf swaps-have-occured nil)
         (loop for idx below (1- (length array))
            when (not (funcall ordering-fn
                               (aref array idx)
                               (aref array (1+ idx))))
            do (rotatef (aref array idx)
                        (aref array (1+ idx)))
              (setf swaps-have-occured t))))
  array)

(defun merge-sort (array ordering-fn)
  (labels ((merge-sort-aux (array-aux)
             (if (<= (length array-aux) 1)
                 array-aux
                 (let* ((start-idx 0)
                        (end-idx (1- (length array-aux)))
                        (mid-idx (truncate (/ (- end-idx (1+ start-idx)) 2)))
                        (left-subarray   (subseq array-aux   start-idx  (1+ mid-idx)))
                        (right-subarray  (subseq array-aux (1+ mid-idx) (1+ end-idx))))
                   (merge 'vector
                          (merge-sort-aux left-subarray)
                          (merge-sort-aux right-subarray) ordering-fn)))))
    (merge-sort-aux array)))

(defun extremal-elements (array ordering-fn)
  (let ((current-lower-bound (aref array 0))
        (current-upper-bound (aref array 0)))
    (loop for elt across array
       for idx below (length array)
       when (funcall ordering-fn elt current-lower-bound)
            do (setf current-lower-bound elt)
       when (funcall ordering-fn current-upper-bound elt)
            do (setf current-upper-bound elt))
    (values current-lower-bound current-upper-bound)))

(defun number-in-range-to-idx (number lower-bound upper-bound)
  (assert (<= number upper-bound))
  (- number lower-bound))

(defun idx-to-number-in-range (idx lower-bound upper-bound)
  (let ((number (+ lower-bound idx)))
    (assert (and (>= number lower-bound)
                 (<= number upper-bound)))
    number))

(defun counting-sort (array ordering-fn)
  (declare (ignore ordering-fn))
  (multiple-value-bind (lower-bound upper-bound)
      (extremal-elements array #'<=)
    (let* ((array-length (length array))
           (counting-array-length (1+ (- upper-bound lower-bound)))
           (counting-array (make-array counting-array-length :initial-element 0)))
      (loop for elt across array do
           (incf (aref counting-array
                       (number-in-range-to-idx elt
                                               lower-bound
                                               upper-bound))))
      (let ((array-idx 0))
        (loop
           for counting-array-idx below counting-array-length
           while (< array-idx array-length)
           for n = (aref counting-array counting-array-idx)
           do (loop repeat n do
                   (setf (aref array array-idx)
                         (idx-to-number-in-range counting-array-idx
                                                 lower-bound
                                                 upper-bound))
                   (incf array-idx))))))
  array)

(defun %parent-idx (idx)
  (truncate (floor (1- idx) 2)))

(defun %left-child-idx (idx)
  (1+ (* 2 idx)))

(defun %right-child-idx (idx)
  (* 2 (1+ idx)))

(defun %heapify (array idx max-idx)
  (let* ((left-child-idx (%left-child-idx idx))
        (right-child-idx (%right-child-idx idx))
        (idx-largest (if (and (< left-child-idx max-idx)
                          (> (aref array left-child-idx)
                             (aref array idx)))
                     left-child-idx
                     idx)))

    (when (and (< right-child-idx max-idx)
               (> (aref array right-child-idx)
                  (aref array idx-largest)))
      (setf idx-largest right-child-idx))

    (when (/= idx-largest idx)
      (rotatef (aref array idx) (aref array idx-largest))
      (%heapify array idx-largest max-idx))))
