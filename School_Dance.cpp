#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> matchR, vis;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;

        // If girl v is free or we can reassign her previous boy
        if (matchR[v] == -1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    adj.assign(n + 1, {});
    matchR.assign(m + 1, -1);

    for (int i = 0; i < k; i++) {
        int b, g;
        cin >> b >> g;
        adj[b].push_back(g);
    }

    int match_count = 0;


    for (int boy = 1; boy <= n; boy++) {
        vis.assign(m + 1, 0);
        if (dfs(boy))
            match_count++;
    }

    cout << match_count << "\n";

    // (boy, girl)
    for (int girl = 1; girl <= m; girl++) {
        if (matchR[girl] != -1) {
            cout << matchR[girl] << " " << girl << "\n";
        }
    }

    return 0;
}
