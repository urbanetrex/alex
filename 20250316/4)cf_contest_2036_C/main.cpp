#include <iostream>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int q;
    cin>>q;
    while(q--){
        int i,v;
        cin>>i>>v;
        i--;
        s[i] = v;
        int n = s.size();
        bool valid = false;
        for(int i = 0; i<n-3; i++){
            if(s[i]==1 && s[i+1]==1 && s[i+2]==0 && s[i+3]==0){
                valid = true;
                break;
            }
        }
        cout<<(valid?"YES":"NO")<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}