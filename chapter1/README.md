# Chapter 1 - Basic Constructs

## Section 1.1 - Introduction
We will be using C++ predominatly (and some python if necessary) throughout this resource. We will be taking heavy use of the C++ STL to help us as it contains a lot of useful functions and data structures.

We will start with arrays and vectors. 

## Section 1.2 - Arrays 
Arrays are basically a collection of data that is stored in contiguous memory. This means that the data is stored in a single block of memory. This is the most common way to store data in computer programms.
An element (that is a data object in an array) can be accessed by using its index, which is like the roll number of a student in a class. An array access is random. That is the time taken to get an element is not dependent on the index (on average).

###  Declaring an array
```
int arr[10];            // An array of 10 integers 
```
An array contains elements of a single type (like intger or char).
Arrays can also be multidiemensional. 
For example a 2-D array can be imagined as a matrix of elements where each element is indexed by its row and coloumn number.

### Initializing an array 
```
int arr[5] = {1, 2, 3, 4, 5};
```

The array contains 1, 2, 3, 4, 5 in that order.

### Accessing array elements
```
cout << arr[1] ;        // Prints 2 
```

Array indexing starts from 0.

Arrays can also be manipulated later on.

### Manipulating array elements
```
arr[1] = 10;
cout << arr[1] ;         // Prints 10
``` 

### Initializing a 2-D array
```
int arr[10][10];        // An matrix of 10 rows and 10 coloumns of integers
```

We can initialise arrays of 3 and 4 dimensions as well but they are seldom used.

## Section 1.3 - Vectors

Vectors are an extension of arrays which have a lot of built in funcitons to make our lives easier. One big difference is that while arrays are static that is they can only have as many elements as they are initialised with, vectors can have more less elements and are cleed dynamic.

Some of the functions that are available in vectors are:

```
Initialization
vector<int> v;          // A vector of integers

push_back
v.push_back(1);         // Add 1 to the end of the vector
v.push_back(2);         // Add 2 to the end of the vector
v.push_back(3);         // Add 3 to the end of the vector
v.push_back(4);         // Add 4 to the end of the vector
v.push_back(5);         // Add 5 to the end of the vector

// The vector now contains 1, 2, 3, 4, 5

accessing elements like array
cout << v[0];           // prints 1

size 
// Returns the size of the vector 
cout << v.size()        // prints the size of the vector 5

back
// Returns the last element of the vector
cout << v.back()        // prints 5

```

Another intresting thing with vectors are iterators and ranges 

Iteratos are variables that point to an element in a vector.
The *begin* iterator points at the first element of the vector and *end* point at the position after the last element.

These can be given as arguments to other useful functions.

```
sort(v.begin(),v.end());    // sorts the vector
reverse(v.begin(),v.end()); // reverses the vector
lower_bound(v.begin(),v.end(), 2) // returns an iterator to the first element in the vector that is greater than or equal to the value given number as argument
upper_bound(v.begin(),v.end(), 3) // returns an iterator to the first element in the vector that is greater than the value given number as argument

// Note that these functions only work with sorted vectors. 
// These functions can also return v.end if no such value is found. So use them with caution
```

Note - Even though vectors provide a lot of flexibility and it may look like they take more time than arrays, it is generally not the case. On average, vectors perform almost as fast as arrays.

### Questions on the topic
* https://codeforces.com/problemset/problem/118/A
* https://codeforces.com/problemset/problem/706/B
* https://codeforces.com/problemset/problem/1471/B