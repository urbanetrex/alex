#include <iostream>

using namespace std;

int main() {
    int h1, h2, h3, w1, w2, w3, count=0;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    if(h1+h2+h3!=w1+w2+w3){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1; i<=30; i++){
        for(int j=1; j<=30; j++){
            for(int k=1; k<=30; k++){
                for(int l=1; l<=30; l++){
                    if( (h1-i-j>0) && (h2-k-l>0)
                         && (w1-i-k>0) && (w2-j-l>0)
                          && (w3-h1-h2+i+j+k+l>0)){
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}