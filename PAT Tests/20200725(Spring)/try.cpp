#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<string> v;
    v.push_back("haha");
    v.push_back("ho");
    v.push_back("wea");
    v.push_back("awef23");
    v.erase(v.begin() + 1);
    for (string &s: v) printf("%s\n", s.c_str());
    return 0;
}
