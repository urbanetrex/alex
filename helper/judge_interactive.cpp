#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int n, m, q;
    cin>>n>>m>>q;
    bool a[n];
    for(int i = 0; i<n; i++){
        a[i] = false;
    }
    srand(time(0));
    for(int i = 0; i<m; i++){
        int x;
        do
        {
            x=rand()%n;
        } while (a[x]);
        a[x] = true;
    }
    for(int i=0; i<950; i++){
        char c;
        cin>>c;
        if(c=='?'){
            int x, y;
            cin>>x>>y;
            x--;
            y--;
            if(a[x]==a[y]){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
        }else{
            for(int j = 0; j<n; j++){
                bool b;
                cin>>b;
                if(b!=a[j]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}