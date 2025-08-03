#include <iostream>
//#include <queue>
/* MY EDITS
using namespace std;
void solve(){
    priority_queue<int> nums;
    int n, k;
    cin>>n>>k;
    if(k<2){
        int start, end;
        cin>>start;
        for(int i=2; i<n; i++){
            int temp;
            cin>>temp;
            nums.push(temp);
        }
        cin>>end;
        cout<<(max(start, end) + nums.top())<<endl;
    } else {
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            nums.push(temp);
        }
        int sum=0;
        for(int i=0; i<=k; i++){
            sum+=nums.top();
            nums.pop();
        }
        cout<<sum<<endl;
    }
}*/
//EDIT CHANGES
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    if (k > 1) {
        // we have a method of always getting these numbers
        sort(a.rbegin(), a.rend());
        ll tot = 0;
        for (int i = 0; i <= k; i++) {
            tot += a[i];
        }
        cout << tot << '\n';
    } else {
        // we need to end with a number either at the start or the end
        // if this is true, we always have a method
        ll case_first = 0, case_last = 0;
        for (int i = 1; i < n; i++) {
            case_first = max(case_first, a[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            case_last = max(case_last, a[i]);
        }
        cout << max(case_first + a[0], case_last + a[n - 1]) << '\n';
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