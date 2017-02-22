## C++ Resources 

Developing a library of container classes in C++.

### Folders and Files

----

1. **DefaultDynamicList**
  1.`vectorTemplate.hpp`
  1. A template that mimics the behavoir and functionality of a vector with the use of dynamic arrays
  
2. **IntegerDynamicList**
  1. `List.cpp`
  2. `List.hpp`
    1. Same functionality as the vector template, but integer specific
    
3. **PairTemplate**
  1. `pairing.cpp`
    1. A template that allows the storage of two different data types
    
4. **operatorOverloads**
  1. `IntItem.hpp`
  2. `IntItem.cpp`
    1. Overloads operators used in arithmetic operations and comparisons to mimic the standard functionality with integers
    
5. ***pointers***
 1. `linkedLists.cpp`
   1. A singly-linked list that allows addition of new integers and sorts them in ascending order
 2. `pointerTypes.cpp`
   1. Examples of const pointers and const data
    
6. **SortingAlgorithms**
  1. `bubble.cpp`
  2. `insertionSort.cpp`
  3. `selectionSort.cpp`
  
----

## Further Development

This will be developed into a large library of vector-style container classes with a high degree of functionality including the following public functions: 

Function       | Description
-------------  | -------------
makeContainer  |
addToAll       | add a specified value to entire container
push_back      | 
pop_back       | 
sortAscending  | 
sortDescending | 
getIndexOf     | returns the index of specified content
removeAll      | removes all data
removeAt       | removes at an index
removeItem     | removes reocurring items
swap           |
getCapacity    | 
getSize        | 
operator+      |
operator-      |
operator[]     |
