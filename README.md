
# DSBA Introduction to Programming // Workshops 12+
Spring semester 2022/23

Dealing with maps, sets and their variations.

https://en.cppreference.com/w/cpp/container/map

https://en.cppreference.com/w/cpp/container/set

Apply proper decomposition. Try to use a function for each of the steps specified in the exercises.


## Exercise 1. `std::map`

Develop the following program:

1. Ask the user to input three integers n, r, q: `n>=0`, `r<=q`.
2. Generate a random sequence of `n` integers from the range `[r, q)` with a uniform distribution. Store the numbers in a vector.
3. Print the vector.

> While testing the program, consider a narrow range r<=q such that it's likely to get duplicates.

4. Put the vector's elements in a `std::map<int, size_t>` object where the *key* is an element `x` of the vector of random numbers, and the *value* is how many times `x` appears in the sequence.

> Try different approaches for how to fill the map with the vector's elements. Use operator[], the method insert() with different argument types. https://en.cppreference.com/w/cpp/container/map/insert


5. Provide the following functionality as separate functions:




*  Print the elements of the map (both keys and values as pairs).
*  The function takes an input argument `t` and prints each `t`-th element of the map.
> consider the difference between range-based for loops and iterators. How to access elements of a const map reference with iterators?  https://en.cppreference.com/w/cpp/container/map/at
* A function with the prototype  
`bool query(const std::map<int, size_t>& m, int k, size_t& element);`  
If the key `k` exists, the function returns `true` by value and outputs the corresponding *value* by changing the reference variable `element`.  
If the key `k` does not exist, the function returns `false` and doesn't change the variable `element`.
    * Modify this function to return `std::pair<bool, int>` instead.
* A function that modifies the map by adding a given number to all *values* of the map.
  * Is this possible for *keys*?
* A function that removes all negative *keys* from the map. Consider the example here - https://en.cppreference.com/w/cpp/container/map/erase


## Exercise 2. `std::set`

Consider a second map `std::map<int, bool>`. The map consists of *keys* in range `r<=q`. The corresponding *values* are `true` if the *key* appears in the initial vector/map from **Exercise 1**. Otherwise, the values are `false`.

* Create a function that fills up such a map using the map from **Exercise 1**. Use the *query function from Ex1* to check whether a *key* is present in the first map or not.
  *  What is the time complexity of the function that fills the new map?
* Create a function that queries the *second* map for presence of an element with the given key `k`. It should work similarly to the query function from Ex1, but only return `bool` (true/false if element is present/not).

A key in the second map being `true` means it belongs to a set of keys of the first map. The following collections are equivalent in this.

```
std::map<T, bool> ←→ std::set<T>
```

> The only difference is that the map allows for three values - "true / false / not present" and the set allows only two values - "present / not present".

Create a set of integers `std::set<int>`. The set consists of the keys from the first map from **Exercise 1**.

* Create a function that takes the first map as an input argument and creates the set.
* Create a function that prints the set.
* Create a function that queries the set for presence of an element with the given key `k`. It should work similarly to the previous query functions.

> Usually `map<T, bool>` is a sign of an *anti-pattern*. In practice use `set<T>` unless you're extremely sure you need the map.

## Exercise 3. `std::multimap`

Consider a multimap `std::multimap<int, size_t>` which contains pairs "number from the original vector - index (position) of the number in the vector.

Write functions that create and print this multimap.

-----

Exercises are adapted from the original document by Sergey Shershakov.
