#include <bits/stdc++.h>

using namespace std;

long toIntWithBase(string s, int base) {
    long val = 0;
    long weight = 1;
    int i = s.length();
    while (--i != -1) {
        if ('0' <= s[i] && s[i] <= '9') {
            val += weight * (s[i] - '0');
        } else if ('a' <= s[i] && s[i] <= 'z') {
            val += weight * (10 + s[i] - 'a');
        }
        weight *= base;
    }
    return val;
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    cout << toIntWithBase(s, 10);
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    if (tag == 2) swap(N1, N2);

    return 0;
}
