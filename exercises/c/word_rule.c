#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

struct Node {
    char key[MAX_LEN];
    char value;
};

int wordPattern(char *pattern, char *str) {
    struct Node str2ch[MAX_LEN];
    struct Node ch2str[MAX_LEN];
    int m = strlen(str);
    int i = 0;
    int index = 0;
    while (pattern[index] != '\0') {
        if (i >= m) {
            return 0;
        }
        int j = i;
        while (j < m && str[j] != ' ') j++;
        strncpy(str2ch[index].key, &str[i], j - i);
        str2ch[index].key[j - i] = '\0';
        str2ch[index].value = pattern[index];

        strncpy(ch2str[index].key, &pattern[index], 1);
        ch2str[index].key[1] = '\0';
        strcpy(ch2str[index].value, &str[i]);
        i = j + 1;
        index++;
    }
    return i >= m;
}

int main() {
    char pattern[] = "abba";
    char str[] = "dog cat cat dog";
    int result = wordPattern(pattern, str);
    printf("%d\n", result);
    return 0;
}
