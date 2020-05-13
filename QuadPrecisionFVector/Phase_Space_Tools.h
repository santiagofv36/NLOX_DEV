#ifndef _Phase_Spaces_Real_H
#define _Phase_Spaces_Real_H
#include <stdlib.h>
#include "FVector.h"
#include <cstring>
#include <string>

#define ZERO_SPEED 1E-38

const __float128 PSSR_PI = strtoflt128 ("3.14159265358979323846264338327950288420", NULL);

template <class T>
T lambda(T x, T y, T z){
  return x*x + y*y + z*z - 2*x*y - 2*y*z - 2*z*x;  
}

__float128 sqrt(__float128 x){
    return sqrtq(x);
}

__float128 sin(__float128 x){
    return sinq(x);
}

__float128 cos(__float128 x){
    return cosq(x);
}

template <class T>
Matrix<T> Boost(T v_x, T v_y, T v_z){
  Matrix<T> out;
  T v = sqrt( v_x*v_x + v_y*v_y + v_z*v_z );
  Matrix<T> keta;
    if(v < ZERO_SPEED){
    keta.M[0][1] = 0 ;
    keta.M[0][2] = 0 ;
    keta.M[0][3] = 0 ;
    keta.M[1][0] = 0 ;
    keta.M[2][0] = 0 ;
    keta.M[3][0] = 0 ;
    }
      
    else{
    keta.M[0][1] = v_x / v ;
    keta.M[0][2] = v_y / v ;
    keta.M[0][3] = v_z / v ;
    keta.M[1][0] = v_x / v ;
    keta.M[2][0] = v_y / v ;
    keta.M[3][0] = v_z / v ;
    }
  
  T gamma = v*v;
    gamma = 1-gamma;
    gamma = sqrt(gamma);
    gamma = 1/gamma;
  
  out = 1 + gamma*v*keta + (gamma - 1)*keta*keta;
    
  return out;
    
}

template <class T>
void Phase_Space_Point_Generator_2_Particle(FVector<T> P, FVector<T>& p1, T m1, FVector<T>& p2, T m2, T* r, T& J){
  
    
  T s = P*P;
  T E = P.get_t();
  
//   std::cout << "sqrt(s) = "<<sqrt(s)<<"\nm1 = "<<m1<<"\nm2 = "<<m2<<std::endl; 
  
  T E1 = ( s + m1*m1 - m2*m2 ) / ( 2*sqrt(s) );
  T E2 = ( s + m2*m2 - m1*m1 ) / ( 2*sqrt(s) );
  T p  = sqrt(lambda(s,m1*m1,m2*m2)/s)/2;  
  
  T cos_th = 2 * r[0] - 1 ;
  T ph = 2*PSSR_PI*r[1];
  T sin_th = sqrt(1 - cos_th*cos_th);
  
  p1.set_t( E1 );
  p1.set_x( -p*cos(ph)*sin_th );
  p1.set_y( -p*sin(ph)*sin_th );
  p1.set_z( -p*cos_th );
  
  p2.set_t( E2 );
  p2.set_x( p*cos(ph)*sin_th );
  p2.set_y( p*sin(ph)*sin_th );
  p2.set_z( p*cos_th );
  
  ////////////////////////////////
 ////  Boosting if needed   ///// 
////////////////////////////////
//   std::cout << "Parameters:\nP_Left ="<<P<<"\ncos(Theta) = "<<cos_th<<std::endl;
//   std::cout << "Pre-Boost momenta:\np1 = "<<p1<<"\np2 = "<<p2<<std::endl;
  
  
  T vx = P.get_x() / E;
  T vy = P.get_y() / E;
  T vz = P.get_z() / E;
  
  
//   if ( ABS(E*E - s)/(E*E) > ZERO_SPEED )
//   {
        
    Matrix<T> B = Boost(vx,vy,vz);
//     std::cout << "Boost = \n"<<B<<std::endl;
    p1 = B * p1;
    p2 = B * p2;
    
//   }
  
  J = J*p;
  J = J/(4*PSSR_PI*sqrt(s));

}

template <class T>
void Recursive_PSP(FVector<T> P, int NPar, FVector<T>* PList, T* MList, T* r, T& J){
    
    Matrix<T> Boosts[NPar];
    for(int i=0;i<NPar;i++){Boosts[i] = 1;}
    
    int count = NPar;
    FVector<T> P_Left = P;
    while (count > 2){
        
//     std::cout << "Generating a particle with mass = "<<MList[count-1]<<std::endl;
//     cout << "Entering recursive generation cycle, "<< count << " particles remaining" <<endl;
    T s = P_Left*P_Left;
    T E = P_Left.get_t();
    
//     cout << "Momemtum left = " << P_Left << endl;
    
    T s_min = 0;
    for(int i=0;i<(count-1);i++){ s_min += MList[i]; }
    s_min = s_min*s_min;
    T s_max = (sqrt(s) - MList[count-1])*(sqrt(s) - MList[count-1]);
    
    T s_now = (s_max-s_min)*r[3*(NPar-count)] + s_min;
    
    T E_now = (s - s_now + MList[count-1]*MList[count-1]) / (2*sqrt(s)) ;
    T pp_now = sqrt( E_now*E_now - MList[count-1]*MList[count-1] );
    T cos_th_now = 2 * r[3*(NPar-count)+1] - 1  ;
    T sin_th_now = sqrt( 1 - cos_th_now*cos_th_now );
    T ph_now = 2*PSSR_PI*r[3*(NPar-count)+2] ;
    
    J = J*pp_now;
    J = J*(s_max-s_min);
    J = J/(8*PSSR_PI*PSSR_PI*sqrt(s));
    
    PList[count-1].set_t( E_now );
    PList[count-1].set_x( pp_now*cos(ph_now)*sin_th_now );
    PList[count-1].set_y( pp_now*sin(ph_now)*sin_th_now );
    PList[count-1].set_z( pp_now*cos_th_now );
    
//     std::cout << "p" << count << " generated!" << std::endl;
//     std::cout << "p" << 2*NPar-count << " =" << PList[2*NPar-count-1] << std::endl;
    
    Matrix<T> Boost_now;
    Boost_now = 1;
    
    
//     if ( ABS(E*E - s) > 0.000000000001 ){
    
    T vx = P_Left.get_x() / E;
    T vy = P_Left.get_y() / E;
    T vz = P_Left.get_z() / E;  
//     cout << "v =("<<vx<<","<<vy<<","<<vz<<")"<<endl;
    Boost_now = Boost(vx,vy,vz);
    
//     }
    
//     cout << "Cumulative Boosts" <<endl;
    for(int i=0;i<=(count-1);i++){
//         cout << "Boost[" << i << "] =" << endl << Boosts[i] << endl;
//         cout << "Boost_now =" << endl << Boost_now << endl;
        Boosts[i] = Boosts[i]*Boost_now;
//         cout << "Boost[" << i << "] =" << endl << Boosts[i] << endl;
    }
    
    FVector<T> P0(1,0,0,0);
    P_Left = sqrt(s)*P0 - PList[count-1]; 
    
    count = count - 1;
    }
    
    
    T ran[2] = {r[3*NPar-6],r[3*NPar-5]};
    Phase_Space_Point_Generator_2_Particle(P_Left,PList[0],MList[0],PList[1],MList[1],ran,J);
    
    for(int i=0;i<NPar;i++){PList[i] = Boosts[i]*PList[i];}
    /*
    /// Corrector for more stable PSP ///
    for (int i=0;i<NPar;i++){
        FVector<T> PBar = !PList[i];
//         std::cout << "Before P = "<< PList[i] << " Diff = " << (MList[i]*MList[i]-PList[i]*PList[i])/(MList[i]*MList[i]) << std::endl;
        PList[i] = PList[i] + PBar*((MList[i]*MList[i]-PList[i]*PList[i])/(2*(PBar*PList[i])));
//         std::cout << "After  P = "<< PList[i] << " Diff = " << (MList[i]*MList[i]-PList[i]*PList[i])/(MList[i]*MList[i]) << std::endl;
        }
    */
    
    
}

template <class T>
void Repair_PSP(FVector<T>* PIn, T* MIn, int NPar, FVector<T>* POut, T* MOut){
    
    #define U T
    #define WP 1E-5 
    
    bool LIMIT = false;
    
    FVector<U> PTot(0,0,0,0);
    for(int i=0;i<2;i++){
        U mass = sqrt(PIn[i]*PIn[i]);
        std::cout << "p"<<i+1<<" = "<<PIn[i]<<" m"<<i+1<<" = "<<mass<<std::endl;
        PTot = PTot + PIn[i];
    }
    for(int i=0;i<NPar;i++){
        U mass = sqrt(POut[i]*POut[i]);
        std::cout << "p"<<i+3<<" = "<<POut[i]<<" m"<<i+3<<" = "<<mass<<std::endl;
        PTot = PTot - POut[i];
    }
    std::cout << "PTot = " <<PTot<<std::endl;
    PTot = 0*PTot;
    
    const char* TYPE = typeid(T).name();
    if (TYPE == typeid(double).name()){ 
        
        ////////////////////////////////////////
        ///
        ///  Step #0: Boost into the CM of 
        ///  the initials to ensure the mappings 
        ///  are done correctly.
        ///
        ///////////////////////////////////////
        
        
        FVector<U> P = PIn[0]+PIn[1];
        Matrix<U> BCM = Boost(-P.get_x()/P.get_t(),-P.get_y()/P.get_t(),-P.get_z()/P.get_t());
        for(int i=0;i<2;i++)PIn[i]=BCM*PIn[i];
        for(int i=0; i<NPar;i++)POut[i] = BCM*POut[i]; 
        BCM = Boost(P.get_x()/P.get_t(),P.get_y()/P.get_t(),P.get_z()/P.get_t());
        
        std::cout << "Correcting at "<<typeid(U).name()<<" precision"<<std::endl;
        
        ////////////////////////////////////////
        ///
        ///   Finals-Square Correction 
        ///   Here we correct the value of m^2
        ///   for the final particles only
        ///
        /////////////////////////////////////////
        
        FVector<U> TP(0,0,0,0);
        for (int i=0;i<NPar;i++){
            FVector<U> PBar = !POut[i];
            POut[i] = POut[i] + PBar*((MOut[i]*MOut[i]-POut[i]*POut[i])/(2*(PBar*POut[i])));
            TP = TP - POut[i];
        }
        ////////////////////////////////////////
        ///
        ///   Final Sum Correction
        ///   After correcting the squares the 
        ///   total 3-momentum might not be zero 
        ///   hence we boost back into the frame 
        ///   where it is zero.
        ///
        /////////////////////////////////////////
        
        Matrix<U> B = Boost(-TP.get_x()/TP.get_t(),-TP.get_y()/TP.get_t(),-TP.get_z()/TP.get_t());
        FVector<U> TPP(0,0,0,0);
        for (int i=0;i<NPar;i++){
            POut[i] = B*POut[i];
            TPP = TPP + POut[i];
        }
        
        
        ////////////////////////////////////////
        ///    
        ///   After correcting for the squares 
        ///   of the finals the total center of
        ///   mass energy might not match the 
        ///   initial center of mass energy.
        ///   We rescale the initials to this new Ecm.
        ///   Fisrt we pretend the initial masses 
        ///
        //////////////////////////////////////////////
        
        U a = (TPP*TPP)/(P*P);
        for(int i=0;i<2;i++){
            FVector<U> PBar= !PIn[i];
            PIn[i] = PIn[i] + PBar*(((MIn[i]*MIn[i])/a-(PIn[i]*PIn[i]))/(2*(PBar*PIn[i])));
            PIn[i] = sqrt(a)*PIn[i];
        }
        
        P = PIn[0]+PIn[1];
        B = Boost(-P.get_x()/P.get_t(),-P.get_y()/P.get_t(),-P.get_z()/P.get_t());
        PIn[0] = B*PIn[0];
        PIn[1] = B*PIn[1];
        
        
        // Quality assesment
        U Delta2 = 0;
        for(int k=0;k<3;k++){
            U mass2= POut[k]*POut[k];
            if (mass2>MOut[k]*MOut[k]) Delta2 += (mass2 - MOut[k]*MOut[k])/(MOut[k]*MOut[k]);
            else Delta2 += -(mass2 - MOut[k]*MOut[k])/(MOut[k]*MOut[k]);
        }
        
//         std::cout << "The new Q2-value is = " << Delta2 <<std::endl;
        
//         if(Delta2>WP&&!RAHP){
//             std::cout << "NLOX was not able to fix this PSP at this precision, going into higher precision"<<std::endl;
//             RAHP = true;
//             #undef U
//             #define U double
//         }
        
            
        }
    

    
}

#endif
