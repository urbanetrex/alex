#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    // (m-m/(l+1))*n≥k, binary search for least l (integer)
    ll l=0, r=m;
    while (l<r) {
        ll mid=(l+r)/2;
        if ((m-m/(mid+1))*n>=k) r=mid;
        else l=mid+1;
    }
    // Output the result
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }
    return 0;
}
