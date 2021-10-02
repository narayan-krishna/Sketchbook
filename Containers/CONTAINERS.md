# C++ Standard Library Containers

## Categorization

A container is sequence of objects:

- _Sequence containers_ provide access to (half-open) sequences of elements
- _Associative containers_ provide associative lookup based on a key

Categories of containers which hold elements but do not provide same amount of functionality as sequences or associative containers:

- _Container adaptors_ provide specialized access to underlying containers
- _Almost containers_ are sequences of elements that provide most, but not all, the facilities of a container.

## Sequence Containers

```C++
vector<T,A> /*a contiguously allocated sequence of T's*/

list<T,A> /*A doubly-linked list of T; use when you ned to insert and delete elements witout moving existing items*/

forward_list<T,A> /*A singly-linked list of T; ideal for empty and very short seuqences*/

deque<T,A> /*A double-ended queue of T; a cross between a vector and a list; slower than one or the other for most uses*/
```

Sequences containers are defined in `<vector>`, `<list>`, and `<deque>`. Vectors are continously allocated, lists are linked through memory by pointers, and deques ("decks") are a mixture.

Use a vector unless a solid reason not too. Vectors provide operations for insert and erasing (removing) elements, allowing them to grow and shhrink as need. For sequences of small elements (that can be stored contiguously), vectors can work as data structures.

Inserting and deletion can move elements of a vector in memory. Elements of lists or associative containers do not move whith insertion and deletion.
