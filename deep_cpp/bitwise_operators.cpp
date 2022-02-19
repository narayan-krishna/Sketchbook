#include <iostream>
#include <string>

using namespace std;

string print_binary(int x) {
    int n = sizeof(x)*8;
    string s = "";
    for(int i = n - 1; i >= 0; i --) {
        s += (x & (1 << i)) ? "1" : "0";
    }
    return s;
}

int convert_binary_int(string s) {
    int value = 0;
    for(int i = 0; i < s.length(); i --) {
        value += (1 << s.length() - 1 - i);
    }

    return value;
}

//set kth bit to 1
int set_kth_bit(int x, int k) {
    return x | (1 << k);
}

//set kth bit to 0
int clear_kth_bit(int x, int k) {
    return x & ~(1 << k);
}

int toggle_kth_bit(int x, int k) {
    return x ^ (1 << k);
}

int extract_mask (int x, int mask, int shift) {
   return (x & mask) >> shift; 
}

int sum(int x, int y) {
    int xor = x ^ y;
    int and = x & y;
}

string add_binary(string a, string b) {
    for
}

int main () {
    cout << convert_binary_int("1000") << endl;
    cout << (0b1000 << 3) << endl;
    return 0;
}


