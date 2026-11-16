import sys

def main():
    data = sys.stdin.read().split()
    n, k = int(data[0]), int(data[1])
    seen = {0}
    s = 0
    for i in range(n):
        s += int(data[2 + i])
        if s - k in seen:
            print("YES")
            return
        seen.add(s)
    print("NO")

main()
