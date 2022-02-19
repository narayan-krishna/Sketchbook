#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>

using namespace std;

#define DIM 2
#define GRAV 6.673*pow(10, -11)

// struct position{
//     float x;
//     float y;
// }; 

// struct velocity{
//     float x;
//     float y;
// };

// struct particle {
//     position s;
//     velocity v;
//     float mass;
// };

// typedef int simple_particle;

// for each timestep
//     if this is the final timestep: print the positions/velocities
//     for each particle
//         compute force onto the particles
//     for each particle
//         compute new position and velocity
//     print updates position velocity

// inline double distance(float x_dist, float y_dist) {
//     return sqrtf(x_dist*x_dist + y_dist*y_dist);
// }

// void compute_forces(const vector<particle> &reference_particles,
//                     vector<particle> &working_particles) {

//     int vec_size = reference_particles.size();

//     for(int i = 0; i < vec_size; i ++) {
//         particle curr = reference_particles[i];

//         for(int j = 0; j < vec_size; j ++) {
//             particle aux = reference_particles[j];
//             if (reference_particles[i] != reference_particles[j]) { 
//                 //compute force  
//                 float x_diff = curr.s.x - aux.s.x;
//                 float y_diff = curr.s.y - aux.s.y;
//                 float dist = distance(x_diff, y_diff);
//                 float dist_cubed = dist*dist*dist;
//                 curr_
//             }
//         }
//     }
// }



int main (int argc, char **argv) {
    if(argc != 2) {
        cerr << "requires timestep count" << endl;
        return 0;
    }

    vector<int> particles(3) = {0};
    for(int v : particles) {
        cout << v << endl;
    }

    
    int time_steps = atoi(argv[1]);
            
    cout << "timesteps: " << time_steps << endl;
}