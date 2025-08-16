#include <iostream>

using namespace std;

void solve() {
    int x, y;
    cin>>x>>y;
    if ((x<3&&y<3)||x==1||y==1){
        cout<<"NO";
    } else {
        cout<<"YES";
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