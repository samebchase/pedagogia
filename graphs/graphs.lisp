(in-package :graphs)

(defclass directed-graph ()
  ((nodes :accessor nodes :initarg :nodes)
   (edges :accessor edges :initarg :edges))
   (:documentation "Basic directed graph."))
