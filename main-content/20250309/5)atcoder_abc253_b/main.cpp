#include <iostream>
using namespace std;
int main(){
    int h, w;
    cin>>h>>w;
    int ax, ay, bx, by;
    bool b=false;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin>>c;
            if(c=='o'){
                if(b){
                    bx=j;
                    by=i;
                }else{
                    ax=j;
                    ay=i;
                    b=true;
                }
            }
        }
    }
    cout<<abs(ax-bx)+abs(ay-by)<<endl;
    return 0;
}