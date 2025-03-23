#include <iostream>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int q;
    cin>>q;
    while(q--){
        int _i;
        char v;
        cin>>_i>>v;
        _i--;
        s[_i] = v;
        int n = s.size();
        bool valid = false;
        for(int i = 0; i<n-3; i++){
            cout<<s[i]<<s[i+1]<<s[i+2]<<s[i+3]<<endl;
            cout<<(s[i]==1 && s[i+1]==1 && s[i+2]==0 && s[i+3]==0)<<endl;
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