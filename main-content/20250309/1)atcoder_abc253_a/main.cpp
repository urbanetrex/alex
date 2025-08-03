#include <iostream> 
using namespace std;
int main() {
    //input a b c then return if b is median of a b c
    int a, b, c;
    cin>>a>>b>>c;
    if((a<=b && b<=c) || (c<=b && b<=a)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}