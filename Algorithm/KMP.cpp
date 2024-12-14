#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char* pat, int M, int* lps) {
    int length = 0; 
    lps[0] = 0; 

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } 
        else { 
            if (length != 0) {
                length = lps[length - 1];
            } else { 
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt, int* positions, int* count) {
    int M = strlen(pat);
    int N = strlen(txt);

    int* lps = (int*)malloc(sizeof(int) * M);

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0; 
    *count = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            positions[*count] = i - j;
            (*count)++;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    free(lps); 
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char txt[100010];
        char pat[100010];
        scanf("%s\n%s", txt, pat);

        
        int positions[100010];
        int count = 0;
        KMPSearch(pat, txt, positions, &count);

        printf("%d", count);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                printf(" %d", 1+positions[i]);
                //下标开始1
            }
        }
        printf("\n");
    }
    return 0;
}