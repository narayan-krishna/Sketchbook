#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void print_vector(vector<int> &v) {
    for(auto &n : v) {
        cout << n << endl;
    }
}

void vector_test() {
    /*the default container. use unless a good reason not too*/
    /* good for data structures that need list treatment
     and hold small values */
    vector<int> v = {3, 4, 5};
    // vector<int> v(, 0);
    swap(v[1], v.back());
    print_vector(v);
    // v.push_back(6);
    // print_vector(v);
    // cout << "max size: " << v.max_size() << endl;
    // v.shrink_to_fit();
    // cout << "max size: " << v.max_size() << endl;
}

class Entry{
public:
    string name;
    int number;

    Entry(string n, int x) :name{n}, number{x} {
        name = n;
        number = x;
    }
};

void vector_test_2() {
    vector<Entry> phone_book = {
        {"john", 3},
        {"mary", 4},
        {"chris", 5}
    };
    
    for(Entry &e : phone_book) {
        cout << e.name << endl;
    }
}

int removeDuplicates(vector<int>& nums) {
    int current = 0; 
    int count = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if(i == 0) {
            current = nums[i];
        } else {
            //if current i = the current state number, put swap
            if (current == nums[i]) {
                swap(nums[i], nums.back());
            } else {
                current = nums[i];
                count ++;
            }
        }
    }
    return count;
}

    // vector<int> v = {1, 1, 2};
    // // removeDuplicates(v);
    // print_vector(v);
    // v.push_back(v[1]);
    // v.erase(v.begin() + 1);
    // // v.erase(v[1]);
    // print_vector(v);


int two_sum(vector<int> &nums, int target, vector<int> &ans) {
    map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        //value      //key
        m[nums[i]] = i;
    }

    for(int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if(m[comp]) {
            ans[0] = nums[i];
            ans[1] = comp;
            return 1;
        }
    }
    return 0;
}

int rotate_array(vector<int> &arr) {
    return 0;
}


int main() {
    vector<int> nums = {1, 2, 3, 5, 7};
    vector<int> ans(2);
    two_sum(nums, 12, ans);
    print_vector(ans);
    return 0;
}