#include <iostream>
#include <vector>
using namespace std;
bool is_1100(int i, string &s){
    if(i+3>=s.size()) return false;
    return s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0';
}
void solve(){
    string s;
    cin>>s;
    int q, cnt=0;
    for(int i = 0; i<s.size()-3; i++){
        if(is_1100(i, s)){
            cnt++;
        }
    }
    cin>>q;
    while(q--){
        int _i;
        char v;
        cin>>_i>>v;
        _i--;
        if(is_1100(_i, s))cnt--;
        s[_i] = v;
        if(is_1100(_i, s))cnt++;
        cout<<(cnt?"YES":"NO")<<endl;
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