(asdf:defsystem #:pedagogia.queue
  :serial t
  :description "An implementation of a queue."
  :author "Samuel Chase"
  :license "Unknown"
  :depends-on (#:fiveam)
  :components ((:file "package")
               (:file "queue")))
