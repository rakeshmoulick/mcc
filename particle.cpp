# include <iostream>
# include <cmath>
# include <algorithm>
# include <random>
# include <fstream>
using namespace std;

class Simulation{
    public:
    
        struct Particle{
            double x;
            Particle(std::mt19937 &gen){
                std::uniform_real_distribution<double> U(0.0,10.0);
                x = U(gen);
            }
        };

        std::vector<Particle> particles;
        /*Define the random seed generator engine*/
        std::random_device rd;
        /*Define the random generator engine*/
        std::mt19937 gen;
        /*Initiate the random number generator engine via the random seed engine*/
        Simulation():gen(rd()){}

        void init(){
            for(int i=0; i<40; i++)
                particles.emplace_back(gen);
        }
        bool inDomain(const Particle &p){
            return !(p.x<2.0||p.x>8.0);
        }
        void output(std::ofstream &f){
            for(auto &p:particles)
                f<<p.x<<" "<<inDomain(p)<<endl;
        }
        void run(){
            std::ofstream fi("part_ini.dat");
            init();
            output(fi);
            std::ofstream ff("part_final.dat");
            particles.erase(std::remove_if(particles.begin(),particles.end(),
            [&](const Particle &p){return !inDomain(p);}),particles.end());
            output(ff);
        }

};

int main()
{
    Simulation sim;
    sim.run();
    return 0;
}