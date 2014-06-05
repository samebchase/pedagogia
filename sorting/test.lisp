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

(test index-of-lower-bound-in-range
  (is (= 3
         (pedagogia.sort::index-of-lower-bound-in-range
          #(5 7 9 4 10) #'<
          :start 1 :end 4)))
  (is (= 5
         (pedagogia.sort::index-of-lower-bound-in-range
          #(84 2 1 3 4 -100 5 921 4 5 -40) #'<
          :start 0 :end 10)))
  (is (= 7
         (pedagogia.sort::index-of-lower-bound-in-range
          #(84 2 1 3 4 -100 5 921 4 5 -40) #'>
          :start 0 :end 10)))
  (is (= 4
         (pedagogia.sort::index-of-lower-bound-in-range
          #(4 21 4 123 1984 5 6) #'>
          :start 0 :end 6))))

(test insertion-sort
  (is-true  (pedagogia.sort::sortedp
             (insertion-sort
              #(5 7 2 4 7 5 54 786 323 54 7623 124 561 5 76 1 5) #'<) #'<=))
  (is-false (pedagogia.sort::sortedp
             (insertion-sort
              #(5 7 2 4 7 5 54 786 323 54 7623 124 561 5 76 1 5) #'>) #'>))
  (is-true  (pedagogia.sort::sortedp
             (insertion-sort (pedagogia.sort::random-vector 1000) #'<) #'<=)))

(test selection-sort
  (is-true  (pedagogia.sort::sortedp
             (selection-sort
              #(5 7 2 4 7 5 54 786 323 54 7623 124 561 5 76 1 5) #'<) #'<=))
  (is-false (pedagogia.sort::sortedp
             (selection-sort
              #(5 7 2 4 7 5 54 786 323 54 7623 124 561 5 76 1 5) #'>) #'>))
  (is-true  (pedagogia.sort::sortedp
             (selection-sort
              (pedagogia.sort::random-vector 1000) #'<) #'<=)))

