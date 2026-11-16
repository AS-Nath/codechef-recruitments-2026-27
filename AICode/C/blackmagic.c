#include <stdio.h>
#include <string.h>

char s[200010];

int isV(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    scanf("%200005s", s);
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        while (i < j && !isV(s[i])) i++;
        while (i < j && !isV(s[j])) j--;
        if (i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
    }
    puts(s);
    return 0;
}
