#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    n--;
    vector<int> a[2];
    bool index=false;
    a[0].push_back(1);
    cout<<1<<endl;
    for(int i=0; i<n; i++){
        a[!index].clear();
        a[!index].push_back(1);
        for(int j=1; j<a[index].size(); j++){
            a[!index].push_back(a[index][j-1]+a[index][j]);
        }
        a[!index].push_back(1);
        for(int j=0; j<a[!index].size(); j++){
            cout<<a[!index][j];
            if(j<a[!index].size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
        index=!index;
    }
    return 0;
}