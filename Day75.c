#include <stdio.h>

int main() {
    int arr[10000], n = 0;
    while (scanf("%d", &arr[n]) == 1) n++;
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + arr[i];
    int maxLen = 0;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (prefix[j] == prefix[i] && j - i > maxLen)
                maxLen = j - i;
    printf("%d\n", maxLen);
    return 0;
}