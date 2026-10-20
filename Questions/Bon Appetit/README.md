# Bon Appétit

## Problem Statement

Chef has recently acquired a mysterious magic cabinet that contains chillies of varying spice levels.

Every time Chef opens the cabinet, it presents him with an arrangement of N chillies, each having a certain spice value. The arrangement is fixed for that opening, and Chef cannot rearrange the chillies.

Chef wants to prepare a dish with an exact spice value of K. To do so, he must select a non-empty set of consecutive chillies from the arrangement. The total spice value of the selected chillies is the sum of their individual spice values. Some chillies may be magic, and being magic, they don't behave like usual chillies but instead reduce the overall spice values.

Given the arrangement produced by the magic cabinet, help Chef determine whether he can prepare a dish with spice value exactly K.

## Input Format

The first line contains two space-separated integers `N` and `K`, denoting the number of chillies in the cabinet's arrangement and the target spice value.

The second line contains `N` space-separated integers `A_1, A_2, ..., A_N`, where `A_i` denotes the spice value of the i-th chilli.

## Constraints

- 1 <= N <= 2 x 10^5
- -10^9 <= A_i <= 10^9
- -10^14 <= K <= 10^14

## Output Format

Print `YES` if Chef can prepare a dish with spice value exactly K. Otherwise, print `NO`.

