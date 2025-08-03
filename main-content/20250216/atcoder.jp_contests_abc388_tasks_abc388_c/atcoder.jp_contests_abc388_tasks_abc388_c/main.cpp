#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> mochis;
    for(int i=0; i<n; i++){
        int mochi_size; cin>>mochi_size;
        mochis.push_back(mochi_size);
    }
    long long k=0, s=0;
    for(int i=0; i<n; i++){
        while(mochis[k]*2<=mochis[i]){
            k++;
        }
        s+=k;
    }
    cout<<s<<endl;
    return 0;
}
