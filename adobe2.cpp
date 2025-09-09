#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n;
unordered_map<long long, int> dp;

int countWays(int maskA, int maskB, int maskC) {
    int pos = __builtin_popcount(maskA);

    if (pos == n) return 1;

    long long key = (1LL * maskA << 20) | (1LL * maskB << 10) | maskC;
    if (dp.count(key)) return dp[key];

    int res = 0;
    for (int a = 0; a < n; ++a) {
        if (maskA & (1 << a)) continue;
        for (int b = 0; b < n; ++b) {
            if (maskB & (1 << b)) continue;
            int c = (a + b) % n;
            if (maskC & (1 << c)) continue;

            res = (res + countWays(maskA | (1 << a), maskB | (1 << b), maskC | (1 << c))) % MOD;
        }
    }

    return dp[key] = res;
}

int main() {
   // cin >> n;
    n=11;
    int ans = countWays(0, 0, 0);
    cout << ans << "\n";
    return 0;
    // 
}