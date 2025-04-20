//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int ans = n;

    ll tot = 0;
    int i = 0;
    while (i < n && tot <= x) {
        tot += a[i++];
    }
    ans = min(ans, i);

    tot = 0, i = 0;
    while (i < n && tot <= y) {
        tot += b[i++];
    }
    ans = min(ans, i);

    cout << ans << '\n';
}