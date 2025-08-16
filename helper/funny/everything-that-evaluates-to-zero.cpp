#include <iostream>
#include <string>

using namespace std;

string generate_row(int line, int indentation) {
    string row(indentation*4, ' ');
    if (line==1){
        for(int i=0; i<=9; i++){
            row+=to_string(i);
            if (i<9)row+="*";
        }
    } else {
        row+="+"+to_string(line-1)+"*0";
        for(int i=1; i<=9; i++){
            row+="*"+to_string(line-1)+to_string(i);
        }
    }
    return row;
}

void solve() {
    int indentation, rows;
    cout<<"input the indentation number -- must be ≥0: ";
    cin>>indentation;
    cout<<"how many rows? (>0) ";
    cin>>rows;

    for(int i=1; i<=rows; i++){
        cout<<generate_row(i, indentation)<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while (true) {
        solve();
        bool ifbreak=0;
        char choice;
        while (true) {
            cout << "\nrun again if you dare? (y/n)  ";
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                cout<<"bye-";
                ifbreak=1;
                break;
            }
            if (choice == 'y' || choice == 'Y') {
                cout<<"okay... \ncan you ";
                break;
            }
            cout<<"please enter y or n.\n";
        }    
        if (ifbreak) break;
    }

    return 0;
}