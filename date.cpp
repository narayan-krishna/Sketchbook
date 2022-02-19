#include <iostream>
#include <string>

using namespace std;

int main (int argc, char **argv) {
    if(argc != 3) {
        cout << "needs more args" << endl;
    }

    string month = argv[1];
    string day = argv[2]; 

    string comb = (month + " " + day);
    cout << comb << " ";
    for(int i = comb.length() - 1; i >= 0; i --) {
        cout << comb[i];
    }
    cout << endl;

    return 0;
}
