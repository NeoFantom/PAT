#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct item {
    string s;
    int n;
};

bool cmpstu(item &i, item &j) { return i.n != j.n ? i.n > j.n : i.s < j.s; }

int N, M;
vector<item> students;
vector<item> queries;

int main(int argc, char const *argv[]) {
    printf("ooooooooooooooooo");
    scanf("%d %d", &N, &M);
    students = vector<item>(N);
    queries = vector<item>(M);
    char s[100];
    int n;
    for (int i = 0; i < N; ++i) {
        scanf("%s %d", s, &n);
        students[i].s = s;
        students[i].n = n;
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d %s", &n, s);
        queries[i].s = s;
        queries[i].n = n;
    }
    for (int i = 1; i <= queries.size(); ++i) {
        auto q = queries[i - 1];
        printf("Case %d: %d %s\n", i, q.n, q.s.c_str());
        vector<item> ans;
        if (q.n == 1) {
            for (auto &stu : students)
                if (stu.s[0] == q.s[0]) ans.push_back(stu);
        } else if (q.n == 2) {
            int Nt = 0, Ns = 0;
            for (auto &stu : students)
                if (stu.s.substr(1, 3) == q.s) {
                    Nt += 1;
                    Ns += stu.n;
                }
            if (Nt == 0)
                printf("NA\n");
            else
                printf("%d %d\n", Nt, Ns);
        } else if (q.n == 3) {
            unordered_map<string, int> site2count;
            for (auto &stu : students) {
                if (stu.s.substr(4, 6) == q.s) {
                    string site = stu.s.substr(1, 3);
                    site2count[site] += 1;
                }
            }
            int i = 0;
            for (auto &it : site2count) ans.push_back({it.first, it.second});
        }
        
        if (q.n == 1 || q.n == 3) {
            sort(ans.begin(), ans.end(), cmpstu);
            for (auto &a : ans) printf("%s %d\n", a.s.c_str(), a.n);
            if (ans.empty()) printf("NA\n");
        }
    }

    return 0;
}
