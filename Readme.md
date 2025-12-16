IMPLEMENTATION TASKS (BONUS POINTS)
========================================

### Problem A: Dynamic Array

time limit per test 1 second
memory limit per test 256 megabytes

Given an empty dynamic array and q queries of the following types:

1. Add the value v to the end / at an arbitrary position of the array.

2. Remove the value from the end / an arbitrary position of the array and output it. If the array is empty, output −1.

3. Find the minimum position of the value v. If there is no such value, output −1.

4. Output the element at position i.

- **Input**

>The first line contains an integer q (1≤q≤2⋅10⁵) — the number of queries.

Let n be the number of elements in the array at the time of the query.
The next q lines contain descriptions of the queries:

* 1 v (1≤v≤10⁹) — add the value v to the end of the array.

* 2 — remove the value from the end of the array.

* 3 p v (1≤p≤n;1≤v≤10⁹) — insert the value v before the element at position p.

* 4 p (1≤p≤n) — remove the value at position p.

* 5 v (1≤v≤10⁹) — find the minimum position of the value v.

* 6 p (1≤p≤n) — output the value at position p.

It is guaranteed that there is at least one query of type 2, 4, 5 or 6.
It is guaranteed that the number of queries of types 3, 4, and 5 does not exceed 100 (i.e., no more than 300 in total for all listed query types).
- **Output**

Let m be the number of queries of types 2, 4, 5 and 6.
In a single line, output m integers separated by a space — the results of the corresponding queries. If there is no answer to the query, output −1.

### Example
```
Input
14
2
1 5
1 7
3 2 3
6 1
6 2
6 3
5 3
5 4
4 2
2
1 6
3 1 8
4 2

Output
-1 5 3 7 2 -1 3 7 5 
```
### Problem B: Linked List

time limit per test 1 second
memory limit per test 256 megabytes

Given an empty linked list and q queries of the following types:

1. Add the value v to the end / beginning / arbitrary position of the list.
2. Remove the value from the end / beginning / arbitrary position of the list and output it. If the list is empty, output −1.
3. Find the minimum position of the value v. If the value does not exist, output −1.
4. Output the element at position i

- **Input**
>The first line contains an integer q (1≤q≤2⋅105) — the number of queries.

Let n be the number of elements in the list at the time of the query.
The next q lines contain descriptions of the queries:

* 1 s v(1≤v≤109) — add the value v to the end / beginning of the list.
* 2 s — remove the value from the end / beginning of the list.
* 3 p v(1≤p≤n;1≤v≤109) — insert the value v before the element at position p.
* 4 p(1≤p≤n−1) - remove the value at position p.
* 5 v(1≤v≤109) — find the minimum position of the value v.
* 6 p(1≤p≤n) — output the value at position p.

s can take two values:
- f — the operation is applied to the beginning of the list;
- b — the operation is applied to the end of the list.

It is guaranteed that there is at least one query of type 2, 4, 5, or 6.

It is guaranteed that the number of queries of types 3, 4, 5, and 6 does not exceed 100 (i.e., a total of no more than 400
for all listed query types).

- **Output**

Let m be the number of queries of types 2, 4, 5, and 6.

### Example
```
Input
14
2 b
1 b 5
1 f 7
3 2 3
6 1
6 2
6 3
5 3
5 4
4 2
2 f
1 f 6
3 1 8
4 2

Output
-1 7 3 5 2 -1 3 7 6 
```

### Problem C: Dictionary (Hash Table)

time limit per test 1 second
memory limit per test 256 megabytes

An empty dictionary (associative array) is given, and there are q queries of several types:

* 1. Set the association k v. Output the previous value associated with k, or −1 if no value was associated before.
* 2. Remove the association with key k, if it exists. Output the last value associated with k, if it existed; otherwise, −1.
* 3. Output the value associated with k. If there is no such key in the dictionary, output −1.

- **Input**

> The first line contains an integer q (1≤q≤8⋅105) — the number of queries.

The following q lines contain descriptions of the queries:

* 1 k v (1≤k,v≤109) — add the association k v.
* 2 k (1≤k≤109) — remove the association with key k.
* 3 k (1≤k≤109) — output the value associated with k.

- **Output**

  Output a single line containing q integers separated by a space — the answers to the corresponding queries in the order of their execution.

### Example
```
Input
10
1 2 3
1 5 6
2 3
1 2 4
3 5
2 5
3 5
1 5 3
2 2
3 2

Output
-1 -1 -1 3 6 6 -1 -1 4 -1 

```
### Problem D: Stack with Maximum

time limit per test 1 second
memory limit per test 256 megabytes

You are given an empty priority queue and q requests of several types:

1. Add the value v to the queue.
2. Remove the minimum value from the queue.

After each operation, you need to output the minimum value in the queue. If the queue is empty, output −1.

- **Input**
> The first line contains an integer q (1≤q≤2⋅106) — the number of requests.

The next q lines contain descriptions of the requests:

* 1 v (1≤v≤10⁹) — add the value v to the queue.
* 2 — remove the minimum value from the queue.

- **Output**

  Output a single line containing q integers separated by a space — the minimum values in the queue after each operation. If the queue is empty, output −1.

### Example
```
Input
9
2
1 5
1 2
1 2
2
1 6
2
2
1 3

Output
-1 5 2 2 2 2 5 6 3
```