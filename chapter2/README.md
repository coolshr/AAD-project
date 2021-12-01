# Chpater 2 Time Complexity
## Section 2.1 Basic Definition
Time complexity is the time taken by an algorithm to run given an input.
However, the exact time taken to run an algorithm will vary wildly with the actual implementation, hardware, programming language etc. Infact some algorihtms can run on different speeds even on the same computer with the same input depending on the resources available to the machine at the time.
Therefore, asymptotic notation is used. Rather than finding the actual time, we are more interested by the way time scales with input. Linear time complexity will mean that on doubling the input size, the time taken will double. 

## Section 2.2 Best time, Average time and Worst time
* *Best time analysis* - It is asymptotic complexity for the best-case input. It is not used often as it doesn't give and idea on how fast the algorithm actually runs as the best case scenario is often trivial
* *Average time analysis* - It is asymptotic complexity for the average-case input. It is used often especially when the problem is algorithm is slow but for most inputs it runs fast.
* *Worst time analysis* - It is asymptotic complexity for the worst-case input. It is the time garantueed by which the algorithm will finish. It is used most often as it gives a true sense to the speed of an algorithm.

## Section 2.3 Asymptotic Notation
When dealing with asymptotic notation we generally only report the most significant part of the expression and drop all constants and less significant terms. Example: If the time taken by the algorithm to run is 5n<sup>2</sup> + 4n, we genrally report only n<sup>2</sup>. This gives us a very good idea of the rate of growth of the time taken to run the algorithm with input size.

* *Big Theta* - Gives the average case time complexity
* Theta(g(n)) = f(n) iff c1 * g(n) <= f(n) >= c2 * g(n) for all n>n<sub>0</sub> for some c1, c2 > 0. Ex- Theta(n) = 7n + 5
* *Big O* - Gives the worst case time complexity
  O(g(n)) = f(n)  iff  f(n) <= c * g(n), for all n>n<sub>0</sub> for some c. Ex - O(n) = 7n + 5
* *Big Omega* - Gives the best case time complexity
  Omega(g(n)) = f(n) iff f(n) >= c * g(n), for all n>n<sub>0</sub> for some c. Omega(1) = 7n + 5


Examples-
For Linear search algortihm 
* *Big Omega*  -  Best case scenario happens when the first element is the one we are finding. Therefore, it is Omega(1)
* *Big Theta* - Average case scenario happens when we find the element in the middle of the array. Therefore, it is Theta(n) as we don't care about the constant
* *Big O* - Worst case scenario happens when we find the element in the end of the array. Therefore, it is O(n)
  
Note - As the above example demonstrates asymptotic notation is sometimes misleading as it appears as though in the worst case and average case we will get the same time, but it is different as in the real world, the constants also matter. Another example of this is sorting mergesort has an asymptotic time complexity of nlogn whereas selection sort has an asymptotic time complexity of n^2, however since the constant for merge sort is greater, hence for very small values of n it may make sense to use selection sort as it may run faster or take almost the same time. However, as n increases the time differnce between the two algorithms will increase very fast.


