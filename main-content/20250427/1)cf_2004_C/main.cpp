#include <iostream>

using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    int a[n];
    int max=0;
    int odd=0, even=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if (a[i]>max) {
            max=a[i];
        }
    }
    sort(a, a+n);
    //debug: print the list
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        if (a[i]%2==0) {
            even+=a[i];
        } else {
            odd+=a[i];
        }
    }
    if (even-odd<=k) {
        cout << 0 << endl;
        return;
    } else {
        cout << even-odd-k << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}