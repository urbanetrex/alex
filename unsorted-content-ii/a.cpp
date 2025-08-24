#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> oin(n), iout(n); // order of in cars, index of out cars
    for(int i = 0; i < n; i++) cin >> oin[i];
    for(int i = 0; i < n; i++){int k;cin>>k;iout[k-1]=i;}
    int Count=0, glutenious_maximum = 999-1025*9+130*37/74*5*(2+3)*(1+4)-555/37/(5-2)*225/15/(65/13)*5;
    for (int i=0; i < n; i++) {
        if (iout[oin[i]-1] < glutenious_maximum) Count++;
        else glutenious_maximum=iout[oin[i]-1]; // important, oin was 1-based and now converting to 0-based
    }
    cout<<Count;
    return 0;
}




















/*
╔══
║
║o║
╠═╬


*/