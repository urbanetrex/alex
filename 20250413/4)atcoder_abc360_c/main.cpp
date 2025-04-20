#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<long long> pos(n), max_weight(n, 0), sum_weight(n, 0);
    for(int i=0; i<n; i++){
        cin>>pos[i];
        pos[i]--;
    }
    for(int i=0; i<n; i++){
        long long weight;
        cin>>weight;

        sum_weight[pos[i]]+=weight;
        if(weight>max_weight[pos[i]]){
            max_weight[pos[i]]=weight;
        }

    }
    long long tot = 0;
    for(int i=0; i<n; i++){
        tot+=sum_weight[i]-max_weight[i];
    }
    cout<<tot<<endl;
    return 0;
}