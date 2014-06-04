(defpackage #:pedagogia.search
  (:nicknames :search)
  (:use #:cl)
  (:export #:linear-search
           #:binary-search))

(defpackage #:pedagogia.search.test
  (:nicknames :search-test)
  (:use #:cl
        #:fiveam
        #:pedagogia.search))


