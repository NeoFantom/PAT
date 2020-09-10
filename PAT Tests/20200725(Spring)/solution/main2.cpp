#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;

int a, b, N, M;
vector<vector<int>> number;
set<pair<int, int>> round_loser;
set<int> loser;
bool has[100002];
bool diff[100002];

void kick(int r, int p) {
    round_loser.insert(pair<int, int>(r, p));
    loser.insert(p);
    number.erase(number.begin() + p);
}

int main(int argc, char const *argv[]) {
    scanf("%d %d", &a, &b);
    scanf("%d %d", &N, &M);
    number = vector<vector<int>>(N, vector<int>(M));
    for (int p = 0; p < N; ++p) {
        for (int r = 0; r < M; ++r) {
            scanf("%d", &(number[r][p]));
        }
    }
    has[a] = true;
    has[b] = true;
    diff[abs(a - b)] = true;

    for (int r = 0; r < M; ++r) {
        for (int p = 0; p < number.size(); ++p) {
            int n = number[r][p];
            if (has[n] || diff[n]) {
                kick(r, p);
            } else {
                has[n] = true;
                for (int rr = 0; rr <= r; ++rr) {
                    for (int pp = 0; pp <= p; ++pp) {
                        has[abs(n - number[rr][pp])] = true;
                    }
                }
            }
        }
    }

    return 0;
}
