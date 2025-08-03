#include <iostream>

using namespace std;
bool is_1100(int i, string &s){
    if(i<0 || i+3>s.size()) return false;
    return s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0';
}
void solve(){
    string s;
    cin>>s;
    int q, cnt=0;
    for(int i = 0; i+3<s.size(); i++){
        if(is_1100(i, s)){
            cnt++;
        }
    }
    cin>>q;
    while(q--){
        int i;
        char v;
        
        cin>>i>>v;
        i--;

        for(int j=i-3; j<=i; j++)if(is_1100(i, s))cnt--;
        s[i] = v;
        for(int j=i-3; j<=i; j++)if(is_1100(i, s))cnt++;
        cout<<(cnt>0?"YES":"NO")<<endl;
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