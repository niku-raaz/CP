#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string old, modern;
    cin >> old >> modern;

    int n = old.length();
    int m = modern.length();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0 && j > 0 && old[i - 1] == modern[j - 1]) {
                if (dp[i - 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
            if (i >= 2) {
                string sub = old.substr(i - 2, 2);
                if (sub == "XX" || sub == "YY" || sub == "ZZ") {
                    if (dp[i - 2][j]) {
                        dp[i][j] = true;
                    }
                }
            }
            if (i >= 4) {
                string sub = old.substr(i - 4, 4);
                if (sub == "XYXY" || sub == "YZYZ") {
                    if (dp[i - 4][j]) {
                        dp[i][j] = true;
                    }
                }
            }
            if (j >= 2) {
                string sub = modern.substr(j - 2, 2);
                if (sub == "XX" || sub == "YY" || sub == "ZZ") {
                    if (dp[i][j - 2]) {
                        dp[i][j] = true;
                    }
                }
            }
            if (j >= 4) {
                string sub = modern.substr(j - 4, 4);
                if (sub == "XYXY" || sub == "YZYZ") {
                    if (dp[i][j - 4]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
    }

    if (dp[n][m]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
