#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int>& vec) {
    for(int i : vec) {
        cout << i << " ";
    } cout << endl;
}


vector<vector<int>> generate_powerset(vector<int>& states) {
    vector<vector<int>>power_set;
    for(int i = 0; i < states.size(); i++) {
        vector<int> single_set;
        for(int j = i; j < states.size(); j ++) {
            single_set.push_back(states[j]);
            // print_vec(single_set); 
            vector<int> copied(single_set);
            power_set.push_back(copied);
        }
    }

    return power_set;
}

int main () {
    vector<int> states{1,2,3};
    vector<vector<int>>power_set = generate_powerset(states); 

    for(auto i : power_set) {
        print_vec(i);
    }

    return 0;
}