;;;; graphs.asd

(defpackage :edit-distance-system
  (:use :cl :asdf))

(in-package :edit-distance-system)

(defsystem #:graphs
  :serial t
  :description "Explorations in graph theory."
  :author "Samuel Chase <samebchase@gmail.com>"
  :license "Unknown"
  :depends-on (#:alexandria
               #:optima
               #:fiveam)
  :components ((:file "package")
               (:file "node")
               (:file "edge")
               (:file "graphs")))

