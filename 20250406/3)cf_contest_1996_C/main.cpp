#include <iostream>
#include <vector>
using namespace std;
void solve (){
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < n; i++){
        cnt1[a[i] - 'a']++;
        cnt2[b[i] - 'a']++;
    }
    
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}