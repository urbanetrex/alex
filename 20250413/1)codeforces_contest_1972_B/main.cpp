#include <iostream>

using namespace std;

void solve() {
    int n;
    cin>>n;
    bool good=false;
    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        if(c=='U')good=!good;
    }
    if(good){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    cout<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}