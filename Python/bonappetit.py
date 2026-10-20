n, k = map(int, input().split())
a = list(map(int, input().split()))

prefix_sums = {0}
total = 0

for x in a:
    total += x
    if total - k in prefix_sums:
        print("YES")
        break
    prefix_sums.add(total)
else:
    print("NO")
