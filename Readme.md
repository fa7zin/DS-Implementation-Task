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