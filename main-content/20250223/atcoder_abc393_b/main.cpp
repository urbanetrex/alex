#include <iostream>
using namespace std;
int main(){
    int count = 0;
    string s;
    cin >> s;
    for(int i=0; 2*i<s.size(); i++){
        for(int j=0; j+2*i<s.size(); j++){
            if(s[j] == 'A' && s[j+i]=='B' && s[j+2*i]=='C'){
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}