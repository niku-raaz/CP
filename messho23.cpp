#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n + 1, 0);
    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            ans = max(ans, dp[i]);
            for (long long j = 2; j <= n; ++j) {
                if (j % 1 == 0) {
                    dp[j] = max(dp[j], dp[i] + a[j]);
                }
            }
        } else {
            ans = max(ans, dp[i]);
            for (long long j = 2 * i; j <= n; j += i) {
                dp[j] = max(dp[j], dp[i] + a[j]);
            }
        }
    }
    
    ans = *max_element(dp.begin() + 1, dp.end());

    cout << ans << endl;

    return 0;
}