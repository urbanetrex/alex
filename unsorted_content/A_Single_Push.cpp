#include <iostream>

using namespace std;

#define uint unsigned int

void solve() {
    uint n;
    cin>>n;
    uint a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        uint k; cin>>k;
        if (k < a[i]) {
            cout<<"NO\n";
            return;
        }
        a[i]=k-a[i];
    }

    int prev=0, area_passed=0;
    for(int i=0; i<n; i++){
        if ((area_passed==2) && a[i]!=0) {
            cout<<"NO\n";
            return;
        }
        if ((area_passed==1) && (prev != a[i]) && a[i]){
            cout<<"NO\n";
            return;
        }
        if ((area_passed==1) && (a[i]==0)) {
            area_passed=2;
        }
        if (prev==0 && a[i]!=0 && area_passed == 0) {
            area_passed = 1;
        }
        prev = a[i];
    }
    cout<<"YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}