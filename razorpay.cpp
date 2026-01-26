#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
vector<int> g[N];
int ans;
int a[N];
int dp[N][2]; // dp[i][0] = max path sum with no skip, dp[i][1] = with one skip

void dfs(int node,int par){
    dp[node][0] = a[node];
    dp[node][1] = a[node];

    vector<int> down0, down1;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child, node);

        // store true values (not clipped)
        down0.push_back(dp[child][0]);
        down1.push_back(max(dp[child][0], dp[child][1]));

        // normal case (no skip)
        dp[node][0] = max(dp[node][0], a[node] + max(0LL, dp[child][0]));

        // skip case: either skip below, or skip current
        dp[node][1] = max({
            dp[node][1],
            a[node] + max(0LL, dp[child][1]),  // skip below
            dp[child][0]                       // skip current
        });
    }

    sort(down0.rbegin(), down0.rend());
    sort(down1.rbegin(), down1.rend());

    // merge cases for global answer
    ans = max({ans, dp[node][0], dp[node][1], a[node]});

    // Case 1: no skip
    if(down0.size() >= 2)
        ans = max(ans, a[node] + down0[0] + down0[1]);
    else if(down0.size() == 1)
        ans = max(ans, a[node] + down0[0]);

    // Case 2: skip somewhere below
    if(down1.size() >= 1)
        ans = max(ans, a[node] + down1[0]);

    // Case 3: skip current node
    if(down0.size() >= 2)
        ans = max(ans, down0[0] + down0[1]);
}

int32_t main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans = LLONG_MIN;
    dfs(0, -1);
    cout << ans << "\n";
    return 0;
}
