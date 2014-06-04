(asdf:defsystem #:pedagogia.search
  :serial t
  :description "Search algorithms."
  :author "Samuel Chase"
  :license "Unknown"
  :depends-on (#:fiveam)
  :components ((:file "package")
               (:file "search")
               (:file "test")))

