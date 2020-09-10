#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> primes;

bool isPrime(int n) {
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

void calculatePrimes() {
    primes.push_back(2);
    for (int n = 0; n < 10000; ++n) {
        if (isPrime(n)) {
            primes.push_back(n);
        }
    }
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

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
    calculatePrimes();

    bool allPrime = true;
    for (int i = 0; i < 8; ++i) {
        bool thisPrime = isPrime(nums[i]);
        allPrime = allPrime && thisPrime;
        if (thisPrime) {
            cout << ss[i] << " Yes" << endl;
        } else {
            cout << ss[i] << " No" << endl;
        }
    }
    if (allPrime) cout << "All Prime!" << endl;

    return 0;
}