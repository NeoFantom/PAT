#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

vector<int> primes;
vector<bool> isPrime;

void primesEratosthenesUpTo(int n) {
    isPrime = vector<bool>(n + 1, true);

    int upperBound = sqrt(n) + 1;
    int i;
    for (i = 2; i <= upperBound; ++i) {
        if (isPrime[i]) {
            // primes.push_back(i);
            for (int multi = i + i; multi <= n; multi += i)
                isPrime[multi] = false;
        }
    }
    for (i; i <= n; ++i)
        if (isPrime[i]) primes.push_back(i);
}

bool checkPrime(int n) {
    if (n == 0 || n == 1) return false;
    if (n == 2) return true;
    int size = primes.size();
    int root = sqrt(n);
    for (int i = 0; i < size; ++i) {
        if (primes[i] > root) break;

        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    clock_t t = clock();
    int digits[8];
    for (int i = 0; i < 8; ++i) digits[i] = s[i] - '0';

    int nums[8];
    fill(nums, nums + 8, 0);
    string ss[8];
    for (int i = 0; i < 8; ++i) {
        int base = 1;
        ss[i] = s.substr(i, 8 - i);
        for (int j = 7; j >= i; --j) {
            nums[i] += digits[j] * base;
            base *= 10;
        }
    }
    primesEratosthenesUpTo(10000);

    bool allPrime = true;
    for (int i = 0; i < 8; ++i) {
        bool thisPrime = checkPrime(nums[i]);
        allPrime = allPrime && thisPrime;
        if (thisPrime) {
            cout << ss[i] << " Yes" << endl;
        } else {
            cout << ss[i] << " No" << endl;
        }
    }
    if (allPrime) cout << "All Prime!" << endl;

    t = clock() - t;
    cout << t << endl;

    return 0;
}