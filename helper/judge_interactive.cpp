#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
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
    for(int i=0; i<n; i++){
        cout<<a[i];
    }
    cout<<endl;
    for(int i=0; i<=q; i++){
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
            set<int> s;
            int prev=0;
            while(s.size()<m){
                int b;
                cin>>b;
                b--;
                if(!a[b]){
                    cout<<-1<<endl;
                    return 0;
                }
                s.insert(b);
                if(s.size()==prev){
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