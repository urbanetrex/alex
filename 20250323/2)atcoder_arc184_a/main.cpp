#include <iostream>
using namespace std;
int N, M, Q;
vector<bool> coins;
vector<bool> known;
void ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    if(res==-1) exit(0);
    known.push_back(res);
}
int main(){
    cin >> N >> M >> Q;
    coins.resize(N);
    
}