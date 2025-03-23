#include <iostream>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int clocks[n];
    for(int i=0; i<n; i++){
        cin>>clocks[i];
    }
    for(int i=0; i<n; i++){
        if(clocks[i]<=(max(i,n-i-1)*2)){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
Monitoring...

Inputting...
Input values:
1
2
2 2

Calculating...
in main while, t=1
in solve, n=2
in solve for, i=0
in solve for, time=2
in solve for if arguement compare, max(i,n-i-1)=1
in solve for if arguement compare, 1*2=2
in solve for if arguement, 2<=2
in solve for if, output NO
in solve for if, exit solve
in main while, t=0
in main, exit while
in main, exit main with 0
*/