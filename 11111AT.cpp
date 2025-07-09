#include <iostream>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, q;
    cin>>n>>q;

    bool a[n];
    for(int i=0; i<n; i++) a[i]=0;

    for(int i=0; i<q; i++) {
        int plc;
        a[plc-1] = !a[plc-1];
    }

    return 0;
}