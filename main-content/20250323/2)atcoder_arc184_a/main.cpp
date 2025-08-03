#include <iostream>
using namespace std;
int N, M, Q;
vector<bool> coins;
vector< int[3] > known;
int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    if(res==-1) exit(0);
    known.push_back({a,b,res});
    return res;
}
int main(){
    cin >> N >> M >> Q;
    coins.resize(N);
    for(int i=0; i*2<N; i+=2){
        if(ask(i, i+1)==1){
            
        }
        
    }
    
}