#include <iostream>

using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    long long ans = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x > ans) ans = x;
    }
    for(int i=0; i<m; i++){
        char c;
        int l, r;
        cin>>c>>l>>r;
        if(c == '+'){
            if(l <= ans && r >= ans){
                ans++;
            }
        } else {
            if(l <= ans && r >= ans){
                ans--;
            }
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}