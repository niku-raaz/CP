#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

struct FenwickTree {
    vector<int> bit;
    int size;
    FenwickTree(int sz) {
        size = sz;
        bit.assign(sz + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx) {
            bit[idx] = (bit[idx] + delta) % MOD;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum = (sum + bit[idx]) % MOD;
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    set<int> unique_vals_set;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        unique_vals_set.insert(a[i]);
    }

    vector<int> unique_vals(unique_vals_set.begin(), unique_vals_set.end());
    int m = unique_vals.size();
    FenwickTree ft(m);

    for (int i = 0; i < n; ++i) {
        // Find the rank of the current element a[i].
        // lower_bound returns an iterator to the first element not less than a[i].
        // The distance from the beginning gives us the 0-based index. We add 1 for 1-based rank.
        int rank = lower_bound(unique_vals.begin(), unique_vals.end(), a[i]) - unique_vals.begin() + 1;

        // Query for the sum of subsequences ending with a value smaller than a[i].
        // This corresponds to querying the sum of ranks up to 'rank - 1'.
        int sum_smaller = ft.query(rank - 1);

        // The number of new subsequences ending with the current a[i] is 1 (for the element itself)
        // plus the sum of all subsequences ending with smaller elements.
        int count = (1 + sum_smaller) % MOD;

        // The total number of IS ending with value unique_vals[rank-1] was `ft.query(rank) - ft.query(rank-1)`.
        // We need to add `count` new ones, but we also must remove the old ones to avoid double-counting
        // when we update.
        int old_count = (ft.query(rank) - ft.query(rank - 1) + MOD) % MOD;
        ft.update(rank, (count - old_count + MOD) % MOD);
    }

   
    cout << ft.query(m) << endl;

    return 0;
}