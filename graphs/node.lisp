(in-package :graphs)

(defclass basic-node ()
  ((label :accessor label :initarg :label))
  (:documentation "A basic node."))

(defmethod print-object ((node basic-node) stream)
  (print-unreadable-object (node stream :type t :identity t)
    (format stream "Label: ~a" (label node))))

(defclass coloured-node (basic-node)
  ((colour :accessor colour :initarg :colour))
  (:documentation "A coloured node."))

(defmethod print-object ((node coloured-node) stream)
  (print-unreadable-object (node stream :type t :identity t)
    (format stream "Label: ~a, Colour: ~a" (label node) (colour node))))

(defclass directed-edge ()
  ((start-node :accessor start-node :initarg :start-node)
   (end-node :accessor end-node :initarg :end-node))
  (:documentation "A basic edge from two nodes."))
