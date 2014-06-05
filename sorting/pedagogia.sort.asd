(asdf:defsystem #:pedagogia.sort
  :serial t
  :description "Sorting algorithms."
  :author "Samuel Chase"
  :license "Unknown"
  :depends-on (#:fiveam)
  :components ((:file "package")
               (:file "sort")
               (:file "test")))

