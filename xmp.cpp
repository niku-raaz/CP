// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI

#include <bits/stdc++.h>
using namespace std;

// Define int as long long globally to avoid type errors.
#define int long long 

// Helper function to perform one transformation step.
// It takes the current array's multiset and returns the next one.
vector<int> transform(const vector<int>& arr, int n) {
    // 1. Find frequencies of all numbers and the MEX of the current array.
    vector<int> freq(n + 1, 0);
    for (int x : arr) {
        if (x <= n) {
            freq[x]++;
        }
    }

    int mex = 0;
    while (mex <= n && freq[mex] > 0) {
        mex++;
    }

    // 2. Build the next state's multiset.
    vector<int> next_arr;
    for (int x : arr) {
        // A number transforms to the MEX if it's a duplicate OR it's >= the MEX.
        if (freq[x] > 1 || x >= mex) {
            next_arr.push_back(mex);
        } 
        // Otherwise (it's unique and smaller than the MEX), it stays the same.
        else {
            next_arr.push_back(x);
        }
    }
    return next_arr;
}


void solve() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    int initial_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        initial_sum += a[i];
    }
    
    // The state becomes periodic after the first step.
    // The cycle is a_1 -> a_2 -> a_1 -> a_2 -> ...
    
    // Calculate state a_1
    vector<int> a1 = transform(a, n);
    int sum1 = 0;
    for(int x : a1) {
        sum1 += x;
    }

    // If k=1, we are done.
    if (k == 1) {
        cout << sum1 << endl;
        return;
    }

    // Calculate state a_2
    vector<int> a2 = transform(a1, n);
    int sum2 = 0;
    for(int x : a2) {
        sum2 += x;
    }

    // For k >= 1:
    // If k is odd, the final state is a_1.
    // If k is even, the final state is a_2.
    if (k % 2 == 1) {
        cout << sum1 << endl;
    } else {
        cout << sum2 << endl;
    }
}

int32_t main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case = 1;
    cin >> test_case;
    while (test_case--) {
        solve();
    }
    return 0;
}