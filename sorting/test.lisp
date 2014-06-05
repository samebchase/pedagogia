(in-package :pedagogia.sort.test)

(def-suite all-tests)

(in-suite all-tests)

(test sanity
  (is (= 2 2)))

(test sortedp
  (is-true  (pedagogia.sort::sortedp #(1 2 3 4 5 8 10) #'<))
  (is-false (pedagogia.sort::sortedp #(1 2 2 3)        #'<))
  (is-true  (pedagogia.sort::sortedp #(5 4 3 2 -1)     #'>))
  (is-true  (pedagogia.sort::sortedp #(1 2 2 3)        #'<=))
  (is-false (pedagogia.sort::sortedp #(1 2 3 4 2 5)    #'<=)))

(test insertion-sort
  (is-true  (pedagogia.sort::sortedp (insertion-sort #(5 7 2 4 7 5 54 786 323 54 7623 124 561 5 76 1 5) #'<) #'<=))
  (is-false (pedagogia.sort::sortedp (insertion-sort #(5 7 2 4 7 5 54 786 323 54 7623 124 561 5 76 1 5) #'>) #'>))
  (is-true  (pedagogia.sort::sortedp (insertion-sort (pedagogia.sort::random-vector 1000) #'<) #'<=)))
