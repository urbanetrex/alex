#include <iostream>
#include <vector>
using namespace std; 

using ll = long long;              

ll dist(ll x1, ll x2, ll y1, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1-y2) * (y1-y2);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    bool good=true;
    ll min_dist = dist(sx, sy, ex, ey);
    for (int i = 0; i < n; i++) {
        if (dist(x[i], y[i], ex, ey) <= min_dist) {
            good=false;
        }
    }
    if(good) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}