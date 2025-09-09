#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& visited, set<int>& arti, int& time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;
    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            dfs(v, u, adj, disc, low, visited, arti, time);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u])
                arti.insert(u);
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (parent == -1 && children > 1)
        arti.insert(u);
}

int findTunn(int **arr,int n, int cost[]){
    int res=0;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            int x= arr[i][j];
            if (x && i != j) adj[i].push_back(j);
        }
    }

    vector<int> costvec(n);
    for (int i = 0; i < n; ++i){
        costvec[i]=cost[i];
    }

    vector<int> disc(n, -1), low(n, -1);
    vector<bool> visited(n, false);
    set<int> arti;

    int time = 0;
    for (int i = 0; i < n; ++i){
        if (!visited[i]){
            dfs(i, -1, adj, disc, low, visited, arti, time);
        }
    }


    for (int idx : arti){
         res+=cost[idx];
    }

    return res;
}



int main() {
    int n;
    cin >> n;
    int **arr;

    arr = new int*[n];
    
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int cost[n];

    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    cout<<findTunn(arr,n,cost);
    return 0;
}
