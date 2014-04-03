;;;; graphs.asd

(defpackage :graphs-system
  (:use :cl :asdf))

(in-package :graphs-system)

(defsystem #:graphs
  :serial t
  :description "Explorations in graph theory."
  :author "Samuel Chase <samebchase@gmail.com>"
  :license "Unknown"
  :depends-on (#:alexandria
               #:optima
               #:fiveam
               #:hash-set)
  :components ((:file "package")
               (:file "node")
               (:file "edge")
               (:file "graphs")))

