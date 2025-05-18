#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    reverse(a, a+n);
    int min=1e9, len=0, cnt=0;
    for(int i=0;i<n;i++){
        if (min>a[i]){
            min=a[i];
        }
        len++;
        if (min*len>=x){
            min=1e9;
            len=0;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}