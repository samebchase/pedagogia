(defpackage #:pedagogia.sort
  (:nicknames :sort)
  (:use #:cl)
  (:export #:insertion-sort
           #:selection-sort
           #:bubble-sort
           #:merge-sort
           #:quicksort
           #:counting-sort
           #:heap-sort
           #:bucket-sort))

(defpackage #:pedagogia.sort.test
  (:nicknames :sort-test)
  (:use #:cl
        #:fiveam
        #:pedagogia.sort))


