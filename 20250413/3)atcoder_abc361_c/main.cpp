#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    k = n - k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1e9;
    for(int i = 0; i + k - 1 < n; i++) {
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}