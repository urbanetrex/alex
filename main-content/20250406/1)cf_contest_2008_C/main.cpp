#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long l, r; // Use long long for large values
    cin >> l >> r;
    long long k = r - l;
    long long discriminant = 1 + 8 * k; // Calculate discriminant safely

    cout << floor((-1 + sqrt(discriminant)) / 2) + 1 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}