from decimal import Decimal

a, b, c = input().split()
print("YES" if Decimal(a) + Decimal(b) == Decimal(c) else "NO")
