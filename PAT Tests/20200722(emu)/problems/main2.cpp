#include <algorithm>
#include <cmath>
#include <cstdio>

int *a;  // array
int *s;  // sorted array
int N;   // length of array

int isInsertion() {
    int nextInsertion = 0;
    int i = 1;
    while (s[i - 1] <= s[i]) ++i;
    nextInsertion = i;
    while (i < N) {
        if (a[i] != s[i]) {
            return 0;
        }
        ++i;
    }
    return nextInsertion;
}

void insert(int nextInsertion) {
    int hold = s[nextInsertion];
    int i = -1;
    while (s[++i] < hold)
        ;
    while (i < nextInsertion) {
        std::swap(s[i], hold);
        ++i;
    }
}

int mergeLength() {
    int len = 2;
    while (len < N) {
        int check = len / 2;
        while (check < N) {
            if (s[check - 1] > s[check]) return len;
            check += len;
        }
        len *= 2;
    }
    return len;
}

void merge(int *mergeResult) {
    int len = mergeLength() / 2;
    int start = 0;
    int mid;
    int ires = 0;
    while (start + len * 2 < N) {
        mid = start + len;
        int mergingLen = 2 * len;
        while (start < len && mid < len) {
            if (s[start] < s[mid])
                mergeResult[ires++] = s[start++];
            else
                mergeResult[ires++] = s[mid++];
        }
        while (start < len) mergeResult[ires++] = s[start++];
        while (mid < len) mergeResult[ires++] = s[mid++];
    }
    if (start + len + 1 < N) {
        mid = start + len;
        int rlen = len;
        int llen = N - start;
        while (start < rlen && mid < llen) {
            if (s[start] < s[mid])
                mergeResult[ires++] = s[start++];
            else
                mergeResult[ires++] = s[mid++];
        }
        while (start < rlen) mergeResult[ires++] = s[start++];
        while (mid < llen) mergeResult[ires++] = s[mid++];
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d", &N);
    a = new int[N];
    s = new int[N];
    for (int i = 0; i < N; ++i) scanf("%d", a + i);
    for (int i = 0; i < N; ++i) scanf("%d", s + i);

    if (int k = isInsertion()) {
        insert(k);
        printf("Insertion Sort");
        for (int i = 0; i < N; ++i) printf("%d", s[i]);
    } else {
        merge(a);
        printf("Merge Sort");
        for (int i = 0; i < N; ++i) printf("%d", a[i]);
    }

    delete[] a;
    delete[] s;
    return 0;
}
