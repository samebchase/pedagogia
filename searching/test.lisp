(in-package :pedagogia.search.test)

(def-suite all-tests)

(in-suite all-tests)

(test sanity
  (is (= 2 2)))

(test linear-search
  (is (= 3 (linear-search #(0 1 2 3 4 5 6) 3)))
  (is (eql nil (linear-search #(1 2 3 4 5) 34))))

(test binary-search
  (is (= 3 (binary-search #(0 1 2 3 4 5 6) 3)))
  (is (eql nil (binary-search #(1 2 3 4 5) 34)))
  (is (= 6 (binary-search #(-23 432 324 32 -5 6 2 34 5) 2))))
