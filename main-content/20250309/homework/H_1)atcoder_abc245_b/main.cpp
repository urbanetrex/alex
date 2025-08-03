#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, min=0;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(a[i] == min){
            min++;
        }
    }
    cout << min << endl;          
    return 0;
}