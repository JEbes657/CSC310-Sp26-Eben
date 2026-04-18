Task 6:
A binary heap handles merging by concatenating two arrays, the performing a “heapify” operation to get an O(n) complexity. A Binomial heap is meant to reduce the time that merging takes. The approach is far more structured than that or the binary heap. It takes a collection of trees, merges the trees of the same order potentially moving it to next highest order.

Time complexity of a binomial heap
-	Insert: O(log n) – O(1) amortized
-	FindMin: O(log n)
-	Union: O(log n)
-	Decrease Key: O(log n)
-	Delete: O(log n)

The LCRS representation is an implementation using two different pointers to keep track of the child and sibling. It helps with space efficiency by making sure that the memory footprint of every node is constant, and it can help with structural flexibility by making the union operation more efficient. 

In regard to the article, I think that this is a fine solution that should be implemented for CFS. He found that the binomial heap was faster overall than the RB tree. With faster insertion time selection time and better scalability. Implementation would take many resources and lots of time but the user benefit of using the heap would be worth it in the long run.
