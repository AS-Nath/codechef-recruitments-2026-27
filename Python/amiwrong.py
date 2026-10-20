a, b, c = map(float, input().split())

if round((a + b) * 1000) / 1000.0 == c:
    print("YES")
else:
    print("NO")