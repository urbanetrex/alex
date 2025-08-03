#include <iostream>

using namespace std;

void solve() {
    int n; cin>>n; cout<<(n+1)%2<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}