# include <iostream>
# include <cmath>
# include <algorithm>
# include <random>
using namespace std;

class Simulation{
    public:
    struct Particle{
        double x;
        Particle(std::mt19937 gen){double x = U(gen);}
    };

    std::random_seed rd;
    std::mt19937 gen;
    Simulation()

};

int main()
{
    Simulation sim;
    sim.run();
    return 0;
}