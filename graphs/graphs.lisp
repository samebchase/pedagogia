(in-package :graphs)

(defclass directed-graph ()
  ((nodes :accessor nodes
          :initform (make-instance 'hash-set)
          :initarg :nodes)
   (edges :accessor edges
          :initform (make-instance 'hash-set)
          :initarg :edges))
  (:documentation "Basic directed graph."))

(defmethod print-object ((graph directed-graph) stream)
  (print-unreadable-object (graph stream :type t :identity t)))

(defun add-node-to-graph (graph node)
  (hs-insert (nodes graph) node))

(defun add-edge-to-graph (graph edge)
  (hs-insert (edges graph) edge))

(defun make-directed-graph (node-list edge-list)
  (let ((graph (make-instance 'directed-graph)))
    (dolist (node node-list)
      (add-node-to-graph graph node))
    (dolist (edge edge-list)
      (add-node-to-graph graph edge))))

;;; (defmethod pprint-graph ((graph directed-graph))

