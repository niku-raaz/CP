#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cake {
    long long x, y, z;
};
long long get_price(const Cake& a, const Cake& b) {
    return max({a.x + b.x, a.y + b.y, a.z + b.z});
}

long long solve(int start_index, int pairs_to_form, int n, const vector<Cake>& cakes) {
    if (pairs_to_form == 0) {
        return 0;
    }


    if (start_index >= n) {
        return -1e18; 
    }

    long long max_price = -1e18;

    
    max_price = max(max_price, solve(start_index + 1, pairs_to_form, n, cakes));

    for (int j = start_index + 1; j < n; ++j) {
        long long price_of_pair = get_price(cakes[start_index], cakes[j]);
        long long remaining_price = solve(j + 1, pairs_to_form - 1, n, cakes);

        if (remaining_price > -1e17) {
            max_price = max(max_price, price_of_pair + remaining_price);
        }
    }

    return max_price;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Cake> cakes(n);
    for (int i = 0; i < n; ++i) {
       int x,y,z;
       cin>>x>>y>>z;
       cakes[i].x=x;
       cakes[i].y=y;
       cakes[z].z=z;
    }


    cout << solve(0, k, n, cakes) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}