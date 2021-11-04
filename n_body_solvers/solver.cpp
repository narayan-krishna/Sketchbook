#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>

//due friday, october 5

using namespace std;

// for each timestep
//     if this is the final timestep: print the positions/velocities
//     for each particle
//         compute force onto the particles
//     for each particle
//         compute new position and velocity
//     print updates position velocity

int main (int argc, char **argv) {
    if(argc != 2) {
        cerr << "requires timestep count" << endl;
        return 0;
    }
    
    int time_steps = atoi(argv[1]);
    vector<vector<char>> input = {{'-','-','*','-'},
                                  {'-','-','-','-'},
                                  {'-','*','-','-'},
                                  {'-','-','-','-'}};
    
    vector<vector<int>> forces = 
            

    for(int i = 0; i < input.size(); i ++) {
        for(int j = 0; j < input[i].size(); j ++) {
                        
        }
        cout << endl;
    }

    cout << "timesteps: " << time_steps << endl;
}