#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int freq[26] = {0};
    int secondOcc[26];
    memset(secondOcc, -1, sizeof(secondOcc));
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        freq[c]++;
        if (freq[c] == 2) secondOcc[c] = i;
    }
    int minIdx = n, ans = -1;
    for (int c = 0; c < 26; c++)
        if (secondOcc[c] != -1 && secondOcc[c] < minIdx) {
            minIdx = secondOcc[c];
            ans = c;
        }
    if (ans == -1) printf("-1\n");
    else printf("%c\n", 'a' + ans);
    return 0;
}