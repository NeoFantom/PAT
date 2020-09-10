#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <utility>

int N;
double P, r;
int *supplier;
int *level;

int locateLevel(int id) {
    if (supplier[id] == -1) return 0;
    if (level[id] == -1) level[id] = locateLevel(supplier[id]) + 1;
    return level[id];
}

int main(int argc, char const *argv[]) {
    scanf("%d %lf %lf", &N, &P, &r);
    r = r / 100 + 1;

    supplier = new int[N];
    for (int i = 0; i < N; ++i) scanf("%d", supplier + i);

    level = new int[N];
    std::fill(level, level + N, -1);

    for (int id = 0; id < N; ++id) {
        if (level[id] == -1) {
            locateLevel(id);
        }
    }
    int maxLevel = 0;
    int count = 1;
    for (int i = 0; i < N; ++i) {
        if (level[i] > maxLevel) {
            maxLevel = level[i];
            count = 1;
        } else if (level[i] == maxLevel) {
            ++count;
        }
    }
    printf("%.2lf %d", P * pow(r, maxLevel), count);
    return 0;
}