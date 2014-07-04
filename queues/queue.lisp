(in-package :pedagogia.queue)

(defclass simple-queue ()
  ((front :accessor front :initform ())
   (rear  :accessor rear  :initform ())
   (queue-length :accessor qlength :initform 0)))

(defun make-queue ()
  (make-instance 'simple-queue))

(defmethod print-object ((queue simple-queue) stream)
  (print-unreadable-object (queue stream :type t :identity t)
    (format stream "Size: ~D" (qlength queue))))

(defun empty-queue-p (queue)
  (check-type queue simple-queue)
  (= 0 (qlength queue)))

(defun to-list (queue)
  (check-type queue simple-queue)
  (front queue))

(defun dequeue (queue)
  (check-type queue simple-queue)
  (let ((value (first (front queue))))
    (setf (front queue) (rest (front queue)))
    (unless (empty-queue-p queue)
      (decf (qlength queue)))
    (values value queue)))

(defun enqueue (queue value)
  (check-type queue simple-queue)
  (let ((queue-node (list value)))
    (if (or (null (front queue)) (null (rear queue)))
        (setf (rear queue) queue-node
              (front queue) queue-node)
        (setf (rest (rear queue)) queue-node
              (rear queue) queue-node))
    (incf (qlength queue)))
  queue)
