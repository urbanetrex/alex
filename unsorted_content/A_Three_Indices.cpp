#include <iostream>

using namespace std;

void solve() {
    int n;
    cin>>n;

    int mode = 0, prev = 2147483647, a[n], p, q, r;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if (mode == 1) {
            if (prev > a[i]) {
                r = i;
                mode = 2;
            }
        } else if (mode == 0){
            if (prev < a[i]) {
                p = i-1;
                q = i;
                mode = 1;
            }
        }
        prev = a[i];
    }
    if (mode == 2){
        cout<<"YES\n"<<p+1<<' '<<q+1<<' '<<r+1<<'\n';
    } else {
        cout<<"NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}