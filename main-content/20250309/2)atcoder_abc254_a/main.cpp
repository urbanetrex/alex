#include <iostream>
using namespace std;
int main() {
    //input n, output last two digits of n
    int n;
    cin>>n;
    if(n%100<10){
        cout<<"0";
    }
    cout<<n%100<<endl;
    return 0;
}