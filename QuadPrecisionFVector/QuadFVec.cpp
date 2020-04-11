#include <iostream>
#include <sched.h>
#include <pthread.h>
#include <thread>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <random> 
#include "Phase_Space_Tools.h"
#include <quadmath.h>
#include <string.h>


// __float128 sqrt(__float128 x){
//     return sqrtq(x);
// }


/*
class quad{
    
    __float128 val;
    friend std::ostream &operator<<(std::ostream &, const quad&);
    
    public:
        quad(const __float128& c);
        
        quad& operator=(const quad&);
        quad& operator=(const __float128&);
        __float128 get_v() const;
    
    
};

quad::quad(const __float128& c){
    val = c;
}

quad& quad::operator=(const quad& c){
    val = c.val;
    return *this;
}

quad& quad::operator=(const __float128& c){
    val = c;
    return *this;
}

__float128 quad::get_v() const {return val;}

quad sqrt(const quad q){
    quad out(sqrtq(q.get_v()));
    return out;
}

std::ostream &operator<<(std::ostream &output, const quad& c){
    int prec = 100;
    char o[prec];
    size_t length = sizeof o;
    quadmath_snprintf(o,length,"%+-#*.38Qe",prec,c);
    for (int i=0;i<prec;i++) output << o[i];
    return output;  
}

*/


template <class T>
void TEST_MY_PSP_GENERATOR(T x,bool REPAIR){

        
    std::cout <<typeid(T).name()<<"-precision test: " << std::endl;
    
    FVector<T> P(1000,0,0,0);
    
//     std::cout<<"P = " <<P*P<<std::endl;
    
    FVector<T> PIn[2];
    T MIn[2] = {0,0};
    T RIn[2] = {0,0};
    T JIn=1;
    Recursive_PSP(P,2,PIn,MIn,RIn,JIn);
    
    FVector<T> POut[3];
    T MOut[3] = {4,171,171};
    T ROut[5] = {0.0213241541541,0.4324135413,0.32143145425,0.932184541543,0.5768573234567};
    T JOut=1;
    Recursive_PSP(P,3,POut,MOut,ROut,JOut);
    
    POut[2].set_t(POut[2].get_t()+1E-5);
    /*
    for(int k=0;k<2;k++){
            T mass = sqrt(PIn[k]*PIn[k]);
            std::cout << "p"<<k+1<<" = "<<PIn[k]<<std::endl<<"m"<<k+1<<" = "<<mass <<" <--> "<<MIn[k]<<std::endl;
            }
    
    for(int k=0;k<3;k++){
            T mass = sqrt(POut[k]*POut[k]);
            std::cout << "p"<<k+3<<" = "<<POut[k]<<std::endl<<"m"<<k+3<<" = "<<mass <<" <--> "<<MOut[k]<<std::endl;
            }
    std::cout << "JOut = " << JOut <<std::endl;
    
    
    T Delta2 = 0;
    for(int k=0;k<3;k++){
        T mass2= POut[k]*POut[k];
        if (mass2>MOut[k]*MOut[k]) Delta2 += (mass2 - MOut[k]*MOut[k])/(MOut[k]*MOut[k]);
        else Delta2 += -(mass2 - MOut[k]*MOut[k])/(MOut[k]*MOut[k]);
        
    }
    
    std::cout << "This PSP has a Q2-value = "<< Delta2 <<std::endl; 
    */

    if(REPAIR){ 
        Repair_PSP(PIn,MIn,3,POut,MOut);
    }
    
    /*
    for(int k=0;k<2;k++){
            T mass = sqrt(PIn[k]*PIn[k]);
            std::cout << "p"<<k+1<<" = "<<PIn[k]<<std::endl<<"m"<<k+1<<" = "<<mass <<" <--> "<<MIn[k]<<std::endl;
            }
    
    for(int k=0;k<3;k++){
            T mass = sqrt(POut[k]*POut[k]);
            std::cout << "p"<<k+3<<" = "<<POut[k]<<std::endl<<"m"<<k+3<<" = "<<mass <<" <--> "<<MOut[k]<<std::endl;
            }
    std::cout << "JOut = " << JOut <<std::endl;
    */
    
    
    
    
    
}

int main(){

    int buffer = 100;
    char o[buffer];
    char output[buffer];
    size_t length = sizeof o;
    
    
    
  __float128 s = 10;
  std::cout.precision(38);
  __float128 sqrts = sqrtq(s);
  FVector <int> PInt(sqrts,0,0,0);
  FVector <float> PFloat(sqrts,0,0,0);
  FVector <double> PDouble(sqrts,0,0,0);
  FVector <long double> PLongDouble(sqrts,0,0,0);
  FVector <__float128> PQuad(1000000000*sqrts,0,0,0);
  FVector <__float128> PAux(sqrts+1,2*sqrts,3*sqrts,0);
  
  __float128 Q = PQuad*PAux;
  quadmath_snprintf(o,length,"%.38Qe",buffer,Q);
  std::cout << "p1.p2 = " << o << std::endl;
  
  
  std::cout<<"sqrt(1000) = 31.622776601683793319988935444327185337195551393252..."<<std::endl;
  
  std::cout << "Now we print the FVectors with various precision!" <<std::endl;
  std::cout << "PInt        = "<<PInt<<std::endl; 
  std::cout << "PFloat      = "<<PFloat<<std::endl; 
  std::cout << "PDouble     = "<<PDouble<<std::endl; 
  std::cout << "PLongDouble = "<<PLongDouble<<std::endl; 
  std::cout << "PQuad       = "<<PQuad<<std::endl; 
  
  
  
  __float128 vx = sqrtq(1./7);
  __float128 vy = sqrtq(2./7);
  __float128 vz = sqrtq(3./7);
  Matrix<__float128> M = Boost(vx,vy,vz);

  std::cout << M << std::endl;

    double x = PSSR_PI;
    long double y = PSSR_PI;
    __float128 z = PSSR_PI; 
    std::cout << "double x       ---> pi = "<<x<<std::endl; 
    std::cout << "long double x  ---> pi = "<<y<<std::endl; 
    std::cout << "float128 x     ---> pi = "<<z<<std::endl;
    std::cout << "Real Pi        ---> pi = 3.14159265358979323846264338327950288420"<<std::endl;

    z = 1;
    z /= sqrtq(7);
    std::cout << "1./sqrtq(7)       = " <<z<<std::endl;
    z = sqrtq(1./7);
    std::cout << "sqrtq(1./7)       = " <<z<<std::endl;
    z = 7;
    z = 1/sqrt(z);
    std::cout << "1/sqrt(7)         = " <<z<<std::endl;
    z = sqrt(7);
    z = powq(z,-1);
    std::cout << "pow(sqrtq(7),-1)  = " <<z<<std::endl;
    std::cout << "Real              = 3.77964473009227227214516536234180060820e-01"<<std::endl;
    
    std::cout << "PSG Multiprecision-Library Tests: "<<std::endl;
    std::cout.precision(16);
    
    float gg;
//     TEST_MY_PSP_GENERATOR(gg,0);
//     TEST_MY_PSP_GENERATOR(gg,1);
    
    double gf;
//     TEST_MY_PSP_GENERATOR(gf,0);
    TEST_MY_PSP_GENERATOR(gf,1);
    
    __float128 gx;
//     TEST_MY_PSP_GENERATOR(gx,0);
//     TEST_MY_PSP_GENERATOR(gx,1);
    /*
    bool t = (typeid(double) == typeid(float));
    std::cout << "double == float ? --> " << ( t ? "true" : "false" )<<std::endl;
    
    
    /// Lets build a loop of precisions! 
    #define W float
    const char* TYPE;
    
    std::cout << "The working precision is "<<typeid(W).name()<<std::endl;
    TYPE = typeid(U).name();
    if (TYPE == typeid(float).name()){
        #undef W
        #define W double
    }
        
    std::cout << "The working precision is "<<typeid(W).name()<<std::endl;
    TYPE = typeid(U).name();
    else if (TYPE == typeid(double).name()){
        #undef W
        #define W long double
    }

    std::cout << "The working precision is "<<typeid(W).name()<<std::endl;
    TYPE = typeid(U).name();
    else if (TYPE == typeid(long double).name()){
        #undef W
        #define W __float128
    }
    else{
    std::cout << "The working precision is "<<typeid(W).name()<<std::endl;
    
        
    }
    */
    
    
    
}    
    
