#include <iostream>
#include <vector>
using namespace std;
void solve (){
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int> > cnt1(26, vector<int>(n+1, 0)), cnt2(26, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++){
        cnt1[a[i] - 'a'][i + 1]++;
        cnt2[b[i] - 'a'][i + 1]++;
    }
    for(int i=0; i < 26; i++){
        for (int j = 1; j <= n; j++){
            cnt1[i][j] += cnt1[i][j - 1];
            cnt2[i][j] += cnt2[i][j - 1];
        }
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        l--; r--;

        int ans=0;
        for (int i = 0; i < 26; i++){
            int x = cnt1[i][r + 1] - cnt1[i][l];
            int y = cnt2[i][r + 1] - cnt2[i][l];
            ans += min(x, y);
        }
        cout << ans/2 << endl;
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