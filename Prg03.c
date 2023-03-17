#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0;

    printf("Enter the string: ");
    scanf("%s", str);

    int len = strlen(str);

    while(1) {
        int i, j;
        for(i = 0, j = 1; j < len;) {
            if(str[i] == str[j]) {
                count++;
                while(str[i] == str[j]) {
                    j++;
                }
                for(int k = j; k < len; k++) {
                    str[k - (j - i)] = str[k];
                }
                len -= (j - i);
            }
            else {
                i = j;
                j++;
            }
        }
        if(count == 0) {
            break;
        }
        printf("%s count = %d\n", str, count);
        count = 0;
    }
    return 0;
}
