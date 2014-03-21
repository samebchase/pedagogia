(in-package :graphs)

(defclass directed-edge ()
  ((start-node :accessor start-node :initarg :start-node)
   (end-node :accessor end-node :initarg :end-node))
  (:documentation "A basic edge from two nodes."))

(defmethod print-object ((edge directed-edge) stream)
  (print-unreadable-object (edge stream :type t :identity t)
    (format stream "Start: ~a, End: ~a"
            (start-node edge) (end-node edge))))            

(defclass weighted-directed-edge (directed-edge)
  ((weight :accessor weight :initarg :weight))
  (:documentation "A weighted edge."))

(defclass labeled-edge (directed-edge)
  ((label :accessor label :initarg :label))
  (:documentation "A labeled edge."))
