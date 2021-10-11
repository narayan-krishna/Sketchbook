#include <iostream>
#include <string>


int swap(string &to_swap, int i, int j);
int find_permutations(string init, int start);

int main () {
    find_permutation();
    return 0;
}

int find_permutations(string init, int start) {
   if(init.length() < 0) {
       return 0;
   }

   int init_length = 0;
   for(int i = start; i < init_length; i ++) {
       swap(init, start, i);
       cout <<  << endl;
       return find_permutations(int)
   }
}
