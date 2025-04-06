#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, k;
        cin>>x>>y>>k;
        x=(x+k-1)/k;
        y=(y+k-1)/k;
        if(x<=y){
            cout<<y*2<<'\n';
        }
        else {
            cout<<x*2-1<<'\n';
        }
    }
    return 0;
}