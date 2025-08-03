#include <iostream>

using namespace std;

void solve() {
    int prev=0, n;
    cin>>n;
    int ans=0;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        if (x<prev) {
            ans+=prev-x;
        } else {
            prev=x;
        }
    }
    if (ans==0) {
        cout << 0 << endl;
        return;
    }
    ans++;
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}