(in-package :graphs)

(defclass directed-edge ()
  ((start-node :accessor start-node :initarg :start-node)
   (end-node :accessor end-node :initarg :end-node))
  (:documentation "A basic edge from two nodes."))

(defmethod print-object ((edge directed-edge) stream)
  (print-unreadable-object (edge stream :type t :identity t)
    (format stream "{~a, ~a}"
            (start-node edge) (end-node edge))))            

(defclass labeled-directed-edge (directed-edge)
  ((label :accessor label :initarg :label))
  (:documentation "A labeled edge."))

(defmethod print-object ((edge labeled-directed-edge) stream)
  (print-unreadable-object (edge stream :type t :identity t)
    (format stream "{~a -(~a)-> ~a}"
            (label (start-node edge))
            (label edge)
            (label (end-node edge)))))
