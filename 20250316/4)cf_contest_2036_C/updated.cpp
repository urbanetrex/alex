#include <iostream>
#include <vector>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    while(q--){
        int _i;
        char v;
        cin>>_i>>v;
        _i--;
        s[_i] = v;
        bool valid = false;
        if(s.find("1100")!=string::npos){
            valid = true;
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