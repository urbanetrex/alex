#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=1;
    while(count){
        count=0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='W' && s[i+1]=='A'){
                s[i]='A';
                s[i+1]='C';
                count++;
            }
        }
    }
    cout << s << endl;
    return 0;
}