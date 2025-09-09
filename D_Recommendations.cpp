#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct User {
    int l, r, index;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<User> users(n);
        for (int i = 0; i < n; ++i) {
            cin >> users[i].l >> users[i].r;
            users[i].index = i;
        }

        // Sort users by their left endpoint, and by right endpoint in descending order
        sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return (a.l < b.l) || (a.l == b.l && a.r > b.r);
        });

        // Result array
        vector<int> result(n, 0);

        // Minimum right endpoint for predictors
        int minRight = 1e9 + 1;

        // Iterate through users in reverse order
        for (int i = n - 1; i >= 0; --i) {
            int l = users[i].l;
            int r = users[i].r;
            int index = users[i].index;

            // Update minimum right endpoint
            if (r < minRight) {
                minRight = r;
            }

            // Calculate strongly recommended tracks
            if (minRight > r) {
                result[index] = minRight - r;
            } else {
                result[index] = 0;
            }
        }

        // Output results
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
