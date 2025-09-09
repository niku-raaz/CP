#include <bits/stdc++.h>
using namespace std;

int getMaximumCount(vector<int>& arr, int k) {
    int n = arr.size();

    int baseK = 0;
    unordered_map<int, int> freq;

    for (int val : arr) {
        if (val == k) baseK++;
    }

    unordered_map<int, int> delta;
    int maxExtra = 0;

    unordered_map<int, int> windowCount;

    int left = 0;
    for (int right = 0; right < n; ++right) {
        int diff = k - arr[right];
        windowCount[diff]++;     ;;;;;
        maxExtra = max(maxExtra, windowCount[diff]);
    }

    return max(baseK, maxExtra + (baseK - windowCount[k - k])); 

}

int main() {
    vector<int> arr = {6,4,4,6,4,4};
    int k = 6;
    cout << getMaximumCount(arr, k) << endl;
}
   
   
