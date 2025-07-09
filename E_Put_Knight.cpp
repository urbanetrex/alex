#include <iostream>
#include <fstream>

using namespace std;

void solve(ifstream &fin, ofstream &fout) {
    int n;
    fin >> n;
    fout << (n + 1) % 2 << '\n';
}

int main() {
    // Open input and output files
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    // Check if files are successfully opened
    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int t;
    fin >> t;
    while (t--) solve(fin, fout);

    // Close files
    fin.close();
    fout.close();

    return 0;
}