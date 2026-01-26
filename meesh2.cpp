#include <bits/stdc++.h>
using namespace std;
#define int long long

long long countEqualAverageSubsets(vector<int>& nums) {
    int n=nums.size();
    int maxSum=0;
    for(auto x: nums){
        maxSum+=x;
    }
    // dp[k][sum] = # of ways pick k elements having sum = sum
    vector<vector<int>> dp(n+1,vector<int>(maxSum+1,0));
    dp[0][0]=1;

    for(auto x: nums){
        for(int k=n;k>=1;k--){
            for(int sum=maxSum-x;sum>=0;sum--){
                dp[k][sum+x]+=dp[k-1][sum];
            }
        }
    }
    int ans=0;
    for(int k=1;k<n;k++){
        if((maxSum*k)%n==0){
            // if 
            int target=(maxSum*k)/n;
            ans+=dp[k][target];
        }
    }
    return ans;

}

int32_t main() {
  
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << countEqualAverageSubsets(nums) << "\n";
    return 0;
}