#include <iostream>

// Define the modulo value
long long MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        // If b is odd, multiply res by a
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        // b = b / 2
        b >>= 1;
        // a = a^2
        a = (a * a) % MOD;
    }
    return res;
}


long long inverse(long long n) {
    return power(n, MOD - 2);
}


long long combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    // Optimization: C(n, k) == C(n, n-k)
    // Choose the smaller k for fewer iterations
    if (k > n / 2) {
        k = n - k;
    }

    long long numerator = 1;
    // Calculate numerator: n * (n-1) * ... * (n-k+1)
    for (int i = 0; i < k; ++i) {
        numerator = (numerator * (n - i)) % MOD;
    }

    long long denominator = 1;
    // Calculate denominator: k!
    for (int i = 1; i <= k; ++i) {
        denominator = (denominator * i) % MOD;
    }

    // Final result is numerator * inverse(denominator)
    return (numerator * inverse(denominator)) % MOD;
}

int main() {
    // Optimize C++ IO operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a >> b;

    long long ans = 0;

    // Case 1: Standard win for A (25:B, B<=23)
    if (a == 25 && b >= 0 && b <= 23) {
        ans = combinations(24 + b, b);
    }
    // Case 2: Standard win for B (A:25, A<=23)
    else if (b == 25 && a >= 0 && a <= 23) {
        ans = combinations(24 + a, a);
    }
    // Case 3: Deuce win for A (A = B+2, B>=24)
    else if (a > 25 && b == a - 2) {
        // We need C(48, 24) * 2^(B-24)
        long long c48_24 = combinations(48, 24);
        long long pow_val = power(2, b - 24);
        ans = (c48_24 * pow_val) % MOD;
    }
    // Case 4: Deuce win for B (B = A+2, A>=24)
    else if (b > 25 && a == b - 2) {
        // We need C(48, 24) * 2^(A-24)
        long long c48_24 = combinations(48, 24);
        long long pow_val = power(2, a - 24);
        ans = (c48_24 * pow_val) % MOD;
    }
    // Case 5: Invalid final score (ans remains 0)

    std::cout << ans << "\n";

    return 0;
}