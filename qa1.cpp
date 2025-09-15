#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> marbles(n);
    for (int i = 0; i < n; ++i) {
        cin >> marbles[i];
    }

    
    sort(marbles.begin(), marbles.end());

    int max_count = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        // Shrink the window if the size difference is greater than 1
        while (marbles[right] > 2 * marbles[left]) {
            left++;
        }
        // Update the maximum count of marbles in a valid window
        max_count = max(max_count, right - left + 1);
    }

    // The number of marbles to remove is the total minus the max valid count
    cout << n - max_count << endl;

    return 0;
}