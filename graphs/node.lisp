(in-package :graphs)

(defclass basic-node ()
  ((label :accessor label :initarg :label))
  (:documentation "A basic node."))

(defmethod print-object ((node basic-node) stream)
  (print-unreadable-object (node stream :type t)
    (format stream "(~a)" (label node))))

(defclass coloured-node (basic-node)
  ((colour :accessor colour :initarg :colour))
  (:documentation "A coloured node."))

(defmethod print-object ((node coloured-node) stream)
  (print-unreadable-object (node stream :type t :identity t)
    (format stream "(~a : ~a)" (label node) (colour node))))
