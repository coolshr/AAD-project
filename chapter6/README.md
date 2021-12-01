# Chapter 6 - Number Theoretic algorithms

## Section 6.1 - GCD

Caluclationg the gcd of two numbers is an important problem and finds it use in many calculation based problems, 
like adding fractions, finding LCM, encryption schemes like RSA, modular arithmetic etc.

The gcd of two numbers is the largest number that divides both of them. The most used algorithm is the Euclid's 
algorithm which is pretty old and easy. We recursively by using the relation gcd(a,b) = gcd(b, a mod b) 
and gcd(a,b) = 0.

The algorithm is pretty efficient as well with time complexity O(log n) as at each stage we will atleast half 
the numbers as a mod b < a/2. Hence we will have log n depth and hence time complexity of O(log n)

### Extended Euclidean algorithm 

In this case we not only output the gcd(a,b) but also x and y such that gcd(a,b) = ax + by

The idea is similar to euclidean algorithm but we also return x and y. The algorithm won't be discussed here for proof or correctness. 