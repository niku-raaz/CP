#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void sieve(int n, vector<bool>& prime) {
    if (n < 2) return;
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    int m, x, y;
    cin >> m >> x >> y;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    vector<bool> prime;
    sieve(m, prime);

    long long credits = x;
    int scheduledExperiments = 0;

    for (int month = 1; month <= m; ++month) {
        if (month > 1) {
            credits += x;
        }
        
        if (credits >= c[month - 1]) {
            credits -= c[month - 1];
            scheduledExperiments++;
        }
        
        if (prime[month]) {
            credits += y;
        }
    }

    cout << scheduledExperiments << endl;

    return 0;
}