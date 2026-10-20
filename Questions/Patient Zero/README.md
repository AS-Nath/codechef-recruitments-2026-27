# Patient Zero

## Problem Statement

You can take the Chef out of CookOff, but never the CookOff out of Chef! And so for one last time, we fling him through time and space, into the year 2202, where he finds a planet on the brink of disaster.

An alien pathogen is spreading rapidly through the planet, which recently fell victim to a Klingon invasion. Hospitals are overwhelmed, the local populace is helpless and the Klingons, despite being honourable warriors with no equal when faced with Bat'leths, Mek'leths, or disruptor rifles, are equally defenceless. Chef steps up to save the day and creates an emergency response team, determined to trace the spread of the disease and save as many lives as possible.

There are N individuals in the affected region of the planet. Initially, no contact relationships have been recorded. As the investigation progresses, the medical team identifies M pairs of individuals who have been in direct contact. Each discovery establishes an undirected link between the two individuals in the contact network.

The pathogen spreads through every recorded contact. If an infected individual has been in contact with another individual, the pathogen can spread to them as well. Consequently, every individual connected to an infected person through a chain of recorded contacts is eventually at risk of infection.

After each newly discovered contact, Chef wants to determine how many unordered pairs of individuals are connected through the contact network. Two individuals are considered connected if there exists a chain of recorded contacts between them.

Help Chef save the planet! Given the order in which the M contact links are discovered, determine the number of connected pairs of individuals after each discovery.

## Input Format

The first line contains an integer T, the number of test cases.

The first line of each test case contains two integers, N and M, representing the number of individuals and the number of contact links discovered, respectively.

The following M lines each contain two integers, u and v, indicating that a direct contact between individuals u and v has been discovered.

## Constraints

- 1 <= T <= 10^4
- 1 <= N <= 2 x 10^5
- 1 <= M <= 2 x 10^5
- 1 <= u, v <= N
- u != v
- No pair of individuals appears more than once among the contact links.
- The sum of N over all test cases does not exceed 2 x 10^5.
- The sum of M over all test cases does not exceed 2 x 10^5.

## Output Format

For each test case, output M integers, where the i-th integer represents the number of unordered pairs of individuals connected through the contact network after the first i contact links have been discovered.

(The statement does not specify the layout. The reference solutions print the M integers space-separated on one line per test case.)

## Sample

**Input**

```
1
6 5
1 2
3 4
2 3
5 6
4 5
```

**Output**

```
1 2 6 7 15
```

**Explanation**

A component of size s contributes s(s-1)/2 pairs.

- After (1, 2): components {1,2}, {3}, {4}, {5}, {6}. Answer 1.
- After (3, 4): components {1,2}, {3,4}, {5}, {6}. Answer 1 + 1 = 2.
- After (2, 3): components {1,2,3,4}, {5}, {6}. Answer C(4,2) = 6.
- After (5, 6): components {1,2,3,4}, {5,6}. Answer 6 + 1 = 7.
- After (4, 5): one component of size 6. Answer C(6,2) = 15.

