// https://blog.csdn.net/qq_29989357/article/details/107774317
#include <bits/stdc++.h>
using namespace std;
int hashTable[100010] = {0};
int hashchk[100010] = {0};
int main() {
    cout << "oooooooooooooo";
    int n1, n2, n, m, cnt = 0;
    cin >> n1 >> n2;
    hashTable[n1] = hashTable[n2] = 1;
    hashchk[abs(n1 - n2)] = 1;
    cin >> n >> m;
    vector<int> player[12], win(12, 0), indextemp;
    indextemp.push_back(n1);
    indextemp.push_back(n2);
    for (int i = 1; i <= n; i++) {
        player[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            cin >> player[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (win[j] == 1) continue;
            if (hashTable[player[j][i]] == 1 || hashchk[player[j][i]] == 0) {
                cout << "Round #" << i << ": " << j << " is out." << endl;
                win[j] = 1;
                cnt++;
            } else {
                hashTable[player[j][i]] = 1;
                for (int temp : indextemp) {
                    hashchk[abs(temp - player[j][i])] = 1;
                }
                indextemp.push_back(player[j][i]);
            }
        }
    }
    if (cnt == n) {
        cout << "No winner." << endl;
    } else {
        cout << "Winner(s):";
        for (int i = 1; i <= n; i++) {
            if (win[i] == 0) cout << " " << i;
        }
        cout << endl;
    }

    return 0;
}
