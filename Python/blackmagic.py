import sys

def is_vowel(c):
    return c in b"aeiouAEIOU"

s = bytearray(sys.stdin.buffer.readline().strip())
left = 0
right = len(s) - 1

while left < right:
    while left < right and not is_vowel(s[left:left + 1]):
        left += 1
    while left < right and not is_vowel(s[right:right + 1]):
        right -= 1
    if left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1

sys.stdout.buffer.write(s + b"\n")
