
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>
#include <algorithm>

class Simulation {
public:
    struct Particle {
        double x,y,u,v;
        bool cex;
        Particle(std::mt19937 &gen,double rT){
            std::uniform_real_distribution<double> U(0.0,1.0);
            x=0;
            y=rT*(-1+2*U(gen));
            u=29000;
            v=-2000+4000*U(gen);
            cex=false;
        }
    };

    static constexpr double dt=1e-7;
    static constexpr double rT=0.15;
    static constexpr double m_XE=2.18e-25;
    static constexpr double q_m=1.602e-19/m_XE;
    const double neut_vth=std::sqrt(2*1.38e-23/m_XE);

    std::vector<Particle> particles;
    std::mt19937 gen;
    std::uniform_real_distribution<double> U;

    Simulation():gen(std::random_device{}()),U(0.0,1.0){}

    double fmaxw(){return 2.0*(U(gen)+U(gen)+U(gen)-1.5);}

    double NeutralDensity(double z,double r){
        const double n0=1e18;
        const double a=1.0/(1.0-1.0/std::sqrt(2.0));
        double R=std::sqrt(r*r+(z+rT)*(z+rT));
        double theta=std::atan2(r,z+rT);
        return n0*a*(1-1/std::sqrt(1+(rT/R)*(rT/R)))*std::cos(theta);
    }

    void accelerate(Particle &p){
        double Ex=0,Ey=0;
        if(p.x<4*rT){
            double E0=50;
            double theta=5.0*M_PI/180.0;
            Ex=-std::sin(theta)*E0;
            Ey=std::cos(theta)*E0;
            if(p.y<0) Ey=-Ey;
        }
        p.u+=q_m*Ex*dt;
        p.v+=q_m*Ey*dt;
    }

    void move(Particle &p){ p.x+=p.u*dt; p.y+=p.v*dt; }

    void collide(Particle &p){
        double nn=NeutralDensity(p.x,p.y);
        double g=std::sqrt(p.u*p.u+p.v*p.v);
        double a=-0.8821*std::log(g)+15.1262;
        double sigma=a*a*1e-20;
        double P=1-std::exp(-nn*sigma*g*dt);
        if(U(gen)<P){
            p.u=neut_vth*fmaxw();
            p.v=neut_vth*fmaxw();
            p.cex=true;
        }
    }

    bool inDomain(const Particle &p){
        return !(p.x<-0.5||p.x>2||p.y<-1||p.y>1);
    }

    void inject(){ for(int i=0;i<25;i++) particles.emplace_back(gen,rT); }

    void output(std::ofstream &f,int it){
        f<<"ZONE I="<<particles.size()<<" T=IT_"<<it<<"\n";
        for(auto &p:particles)
            f<<p.x<<" "<<p.y<<" "<<p.u<<" "<<p.v<<" "<<p.cex<<"\n";
    }

    void run(){
        std::ofstream f("particles.dat");
        f<<"VARIABLES = x y u v cex\n";
        for(int it=1;it<=5000;it++){
            inject();
            for(auto &p:particles){ collide(p); accelerate(p); move(p); }
            particles.erase(std::remove_if(particles.begin(),particles.end(),
                [&](const Particle &p){return !inDomain(p);}),particles.end());
            if(it%50==0) output(f,it);
            std::cout<<"it: "<<it<<"\tnp: "<<particles.size()<<"\n";
        }
    }
};

int main(){
    Simulation sim;
    sim.run();
    return 0;
}
