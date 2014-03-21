(in-package :graphs)

(defclass basic-node ()
  ((label :accessor label :initarg :label))
  (:documentation "A basic node."))

(defclass coloured-node ()
  ((colour :accessor colour :initarg :colour))
  (:documentation "A coloured node."))

(defclass directed-edge ()
  ((start-node :accessor start-node :initarg :start-node)
   (end-node :accessor end-node :initarg :end-node))
  (:documentation "A basic edge from two nodes."))

(defclass weighted-directed-edge (directed-edge)
  ((weight :accessor weight :initarg :weight))
  (:documentation "A weighted edge."))

(defclass labeled-edge (directed-edge)
  ((label :accessor label :initarg :label))
  (:documentation "A labeled edge."))

(defclass directed-graph ()
  ((nodes :accessor nodes :initarg :nodes)
   (edges :accessor edges :initarg :edges))
   (:documentation "Basic directed graph."))
