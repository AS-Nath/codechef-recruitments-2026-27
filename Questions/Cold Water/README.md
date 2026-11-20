# Cold Water

## Problem Statement

We have a lot of fun here at CodeChef-VIT flinging our man the Chef into the weirdest of places, and though we said "Patient Zero" would be the last, we've changed our minds!

Chef woke up today in 2271 BCE somewhere in Ancient Egypt. We've given him a time machine to get home, but for a bit of an extra laugh, we've made it so that the first Q - 1 times out of Q times that he finds it, he'll be teleported to a random location somewhere else, and so will the time machine. So he'll have to find the machine Q times in total before he can get home.

Additionally, our choice of day for Chef to show up ensured that the Nile flooded just yesterday. As such, large swathes of the area he's in are soaking wet.

The area can be represented as an undirected graph of N vertices and M edges. A vertex is either dry or wet. Vertex i is wet when `wet[i] = 1` and dry when `wet[i] = 0.`

The **wetness** of a path is the number of wet vertices encountered along it, including its starting and ending vertices.

You are given N, M, Q, the values `wet[i]` for all vertices, and the graph as M edges. For each of the Q queries, find the wetness of the driest path from the start vertex to the machine's vertex. If no such path exists, output -1 for that query.

## Input Format

- The first line contains three space-separated integers N, M, and Q: the number of vertices, the number of edges, and the number of queries.
- The second line contains N space-separated binary integers, where the i-th integer is `wet[i]`. A value of 1 means vertex i is wet, and 0 means it is dry.
- The next M lines each contain two space-separated integers u and v, representing an undirected edge between vertices u and v.
- The next Q lines each contain two space-separated integers s and t, representing a query for the minimum wetness of a path from vertex s to vertex t.

## Constraints

- 1 <= N <= 10^4
- N - 1 <= M <= 3N
- 1 <= Q <= 140
- 0 <= wet[i] <= 1 for all 1 <= i <= N
- 1 <= u, v, s, t <= N
- u != v for every edge
- There are no multiple edges between any pair of vertices.
- The graph is undirected.

## Output Format

For each of the Q queries, output a single integer on a separate line: the minimum possible wetness of a path between the given pair of vertices.

If no path exists between the two vertices, output -1.

## Sample 0

**Input**

```
6 7 6
0 1 0 1 0 1
1 2
2 3
3 6
1 4
4 5
5 6
2 5
1 6
2 3
1 5
6 6
3 4
4 2
```

**Output**

```
2
1
1
1
2
2
```

**Explanation**

Vertices 2, 4 and 6 are wet; vertices 1, 3 and 5 are dry.

- Query (1, 6): The path 1 → 2 → 3 → 6 has two wet vertices, namely 2 and 6. The alternative path 1 → 4 → 5 → 6 also has two wet vertices, namely 4 and 6. Both endpoints-inclusive routes cost 2, and vertex 6 is wet, so no path can do better. The answer is 2.
- Query (2, 3): The path 2 → 3 contains only vertex 2 as a wet vertex. The answer is 1.
- Query (1, 5): The path 1 → 2 → 5 passes only through wet vertex 2. The answer is 1.
- Query (6, 6): The path consists only of vertex 6, which is wet. The answer is 1.
- Query (3, 4): Every path from 3 to 4 must leave 3 via vertex 2 or vertex 6 (both wet) and end at the wet vertex 4. The answer is 2.
- Query (4, 2): Both endpoints are wet, so the answer is at least 2, and the path 4 → 1 → 2 achieves it.

## Sample 1

**Input**

```
7 6 7
0 1 0 1 0 1 0
1 2
2 3
3 1
4 5
5 6
6 4
1 3
1 4
4 6
5 5
7 7
2 3
6 2
```

**Output**

```
0
-1
2
0
0
1
-1
```

**Explanation**

The graph has three components: the triangle {1, 2, 3}, the triangle {4, 5, 6}, and the isolated vertex {7}.

- Query (1, 3): The direct edge 1 → 3 visits only dry vertices. The answer is 0.
- Query (1, 4): Vertices 1 and 4 lie in different components, so no path exists. The answer is -1.
- Query (4, 6): Both endpoints are wet, so the answer is at least 2, and the direct edge achieves it. The answer is 2.
- Query (5, 5): The path is only vertex 5, which is dry. The answer is 0.
- Query (7, 7): The path is only vertex 7, which is dry. The answer is 0.
- Query (2, 3): The path 2 → 3 contains only the wet vertex 2. The answer is 1.
- Query (6, 2): Vertices 6 and 2 lie in different components, so no path exists. The answer is -1.