#include<bits/stdc++.h>
using namespace std;

vector<int> g[200005];
bool vis[200005];
int dp[200005][2];
vector<int> path[200005][2];
vector<int> ans;

void dfs(int u, int p) {
    vis[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;
    path[u][1].push_back(u);

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        path[u][0].insert(path[u][0].end(), path[v][1].begin(), path[v][1].end());

        if (dp[v][0] < dp[v][1]) {
            dp[u][1] += dp[v][0];
            path[u][1].insert(path[u][1].end(), path[v][0].begin(), path[v][0].end());
        } else {
            dp[u][1] += dp[v][1];
            path[u][1].insert(path[u][1].end(), path[v][1].begin(), path[v][1].end());
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            vis[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ans.clear();
        int total_min_cover_size = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i, 0);
                if (dp[i][0] < dp[i][1]) {
                    total_min_cover_size += dp[i][0];
                    ans.insert(ans.end(), path[i][0].begin(), path[i][0].end());
                } else {
                    total_min_cover_size += dp[i][1];
                    ans.insert(ans.end(), path[i][1].begin(), path[i][1].end());
                }
            }
        }
        
        sort(ans.begin(), ans.end());

        cout << total_min_cover_size << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}