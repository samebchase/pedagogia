(in-package :graphs)

(defclass directed-edge ()
  ((start-node :accessor start-node :initarg :start-node)
   (end-node :accessor end-node :initarg :end-node))
  (:documentation "A basic edge from two nodes."))

(defmethod print-object ((edge directed-edge) stream)
  (print-unreadable-object (edge stream :type t)
    (format stream "(~a) --> (~a)"
            (start-node edge)
            (end-node edge))))

(defclass weighted-directed-edge (directed-edge)
  ((weight :accessor weight :initarg :weight))
  (:documentation "A weighted edge."))

(defmethod print-object ((edge weighted-directed-edge) stream)
  (print-unreadable-object (edge stream :type t)
    (format stream "(~a) --/~a/--> (~a)"
            (label (start-node edge))
            (weight edge)
            (label (end-node edge)))))
