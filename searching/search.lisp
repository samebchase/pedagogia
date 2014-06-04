(in-package #:pedagogia.search)

(defun linear-search (vector search-elt)
  (loop for idx from 0
     for elt across vector
     when (= search-elt elt) return idx))

(defun binary-search (vector search-elt)
  (labels ((binary-search-aux (start-idx end-idx)
             (let* ((middle-idx (+ (truncate (/ (- end-idx start-idx) 2)) start-idx))
                    (middle-elt (aref vector middle-idx)))
               (cond ((= search-elt middle-elt) middle-idx)
                     ((or (= start-idx middle-idx) (= end-idx middle-idx)) nil)
                     ((< search-elt middle-elt) (binary-search-aux      start-idx (1- middle-idx)))
                     ((> search-elt middle-elt) (binary-search-aux (1+ middle-idx)       end-idx))))))
    (binary-search-aux 0 (1- (length vector)))))
