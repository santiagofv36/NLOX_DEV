#ifndef _FVector_Real_H
#define _FVector_Real_H
#include <quadmath.h>

/// Float 128 helper ///
std::ostream& operator << (std::ostream& out,__float128 x){
    int prec = 100;
    char o[prec];
    size_t length = sizeof o;
    quadmath_snprintf(o,length,"%-#*.33Qe",prec,x);
    std::string aux(o);
    aux.erase(aux.find_last_not_of(' ')+1);
    out << aux;
    return out;
}

template <class T>
class FVector{
    /// Components ///
    T t,x,y,z;
    
    public:
        
        /// Constructors ///
        FVector<T>();
        FVector<T>(const T, const T, const T, const T);
        
        /// Assignment Operator /// 
        FVector<T>& operator=(const FVector&);
        
        /// Deconstructor ///
        ~FVector<T>();

        
        /// Member Functions ///
        
        // Cartesian //
        T get_t() const;
        T get_x() const;
        T get_y() const;
        T get_z() const;
        
        void set_t(const T);
        void set_x(const T);
        void set_y(const T);
        void set_z(const T);
        
                
        
        FVector<T> operator + (const FVector<T>&);
        FVector<T> operator - (const FVector<T>&);
        FVector<T> operator!();
        FVector<T> operator-();
};

template <class T>
std::ostream &operator<<(std::ostream &output, const FVector<T>& c){
  T t = c.get_t();
  T x = c.get_x();
  T y = c.get_y();
  T z = c.get_z();
  output << "(" << t << ", " << x << " , " << y << " , " << z << ")";
  return output;  
}

template <class T>
FVector<T>::FVector() {
    T aux=0;
    t = aux;
    x = aux;
    y = aux;
    z = aux;
}

template <class T>
FVector<T>::FVector(const T  tm, const T  xm, const T  ym, const T  zm ) {
    T aux1 = tm;
    T aux2 = xm;
    T aux3 = ym;
    T aux4 = zm;
        
    set_t(aux1);
    set_x(aux2);
    set_y(aux3);
    set_z(aux4);
  
}

template <class T>
FVector<T>::~FVector<T>() {
    double aux = 0;
    
    set_t(aux);
    set_x(aux);
    set_y(aux);
    set_z(aux);
}

template <class T>
FVector<T>& FVector<T>::operator=(const FVector& c) {
  t = c.get_t();
  x = c.get_x();
  y = c.get_y();
  z = c.get_z();
  return *this;
}

template <class T>
void FVector<T>::set_t(const T tm){t = tm;}
    
template <class T>
void FVector<T>::set_x(const T xm){x = xm;}
 
template <class T>   
void FVector<T>::set_y(const T ym){y = ym;}

template <class T>
void FVector<T>::set_z(const T zm){z = zm;}

template <class T>
T FVector<T>::get_t()const {return t;}
    
template <class T>
T FVector<T>::get_x()const {return x;}
 
template <class T>   
T FVector<T>::get_y()const {return y;}

template <class T>
T FVector<T>::get_z()const {return z;}
    
    
template <class T>
FVector<T> FVector<T>::operator+(const FVector<T>& rhs){
    FVector<T> sum;
    sum.set_t(t+rhs.get_t());
    sum.set_x(x+rhs.get_x());
    sum.set_y(y+rhs.get_y());
    sum.set_z(z+rhs.get_z());
    return sum;
}

template <class T>
FVector<T> FVector<T>::operator-(const FVector<T>& rhs){
    FVector<T> sub;
    sub.set_t(t-rhs.get_t());
    sub.set_x(x-rhs.get_x());
    sub.set_y(y-rhs.get_y());
    sub.set_z(z-rhs.get_z());
    return sub;
}


template <class T> 
T operator * (FVector<T>& lhs, FVector<T>& rhs ){
    T prod = (lhs.get_t())*rhs.get_t();
    prod = prod - (lhs.get_x())*rhs.get_x();
    prod = prod - (lhs.get_y())*rhs.get_y();
    prod = prod - (lhs.get_z())*rhs.get_z();
    return prod;
}

template <class T,class U> 
FVector<T> operator * (const U lhs, FVector<T>& rhs){
    FVector<T> prod(lhs*rhs.get_t(),lhs*rhs.get_x(),lhs*rhs.get_y(),lhs*rhs.get_z());
    return prod;  
    
}

template <class T,class U>
FVector<T> operator * (FVector<T>& lhs, U rhs){
    FVector<T> prod(rhs*lhs.get_t(),rhs*lhs.get_x(),rhs*lhs.get_y(),rhs*lhs.get_z());
    return prod;  
    
}

template <class T>
FVector<T> FVector<T>::operator!(){
    FVector<T> cong(t,-x,-y,-z);
    return cong;
}

template <class T>
FVector<T> FVector<T>::operator-(){
  FVector<T> neg(-t,-x,-y,-z);
  return neg;
}


template <class T>
class Matrix{
    
    public:
       /// Components ///
       T M[4][4];
    
       /// Constructors ///
       Matrix<T>();
       Matrix<T>(const Matrix<T>&); /// Copy Constructor ///  

       /// Assignment Operator ///
       Matrix<T>& operator=(const Matrix<T>&);
       Matrix<T>& operator=(const T&);
       
       /// Deconstructor ///
       ~Matrix<T>();       

       /// Overloaded Operators ///
       Matrix<T> operator+(const Matrix<T>&) const;
       Matrix<T> operator-(const Matrix<T>&) const;
       Matrix<T> operator*(const Matrix<T>&);


};

template <class T>
std::ostream &operator<<(std::ostream &output, const Matrix<T>& c){
    for(int j=0; j<4; j++){
        output << "| ";
        for(int i=0; i<4; i++){
            output << c.M[j][i] << " ";
        }
        output << "|\n";
    }
    return output;
}

template <class T>
Matrix<T>::Matrix(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            M[i][j] = 0.;
        }
    } 
}

template <class T>
Matrix<T>::~Matrix(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            M[i][j] = 0.;
        }
    } 
}

template <class T>
Matrix<T>::Matrix(const Matrix& c){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            M[i][j] = c.M[i][j];
        }
    }  
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& c){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            M[i][j] = c.M[i][j];
        }
    }   
  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const T& c) {
    T aux = c;
    for(int i=0; i<4; i++){
        M[i][i] = aux;
    }   
    return *this;
}
 
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& c)const{
    Matrix<T> sum;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            T entry = M[i][j] + c.M[i][j];
            sum.M[i][j] = entry;
        }
    }  
   return sum; 
}

 
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& c)const{
    Matrix<T> sub;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            T entry = M[i][j] - c.M[i][j];
            sub.M[i][j] = entry;
        }
    }  
   return sub; 
}

template <class T> 
Matrix<T> Matrix<T>::operator*(const Matrix<T>& c){
    Matrix<T> prod;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            T entry=0.;
            for(int l=0; l<4; l++){
                T a = c.M[l][j];
                T b = M[i][l]*a;
                entry = entry + b; 
            }  
            prod.M[i][j] = entry;
        }
    }  
   return prod;     
}

template <class T>
FVector<T> operator * (Matrix<T> lhs, FVector<T> rhs){
  FVector<T> aux;
  aux.set_t( lhs.M[0][0]*rhs.get_t()+lhs.M[0][1]*rhs.get_x()+lhs.M[0][2]*rhs.get_y()+lhs.M[0][3]*rhs.get_z() );
  aux.set_x( lhs.M[1][0]*rhs.get_t()+lhs.M[1][1]*rhs.get_x()+lhs.M[1][2]*rhs.get_y()+lhs.M[1][3]*rhs.get_z() );
  aux.set_y( lhs.M[2][0]*rhs.get_t()+lhs.M[2][1]*rhs.get_x()+lhs.M[2][2]*rhs.get_y()+lhs.M[2][3]*rhs.get_z() );
  aux.set_z( lhs.M[3][0]*rhs.get_t()+lhs.M[3][1]*rhs.get_x()+lhs.M[3][2]*rhs.get_y()+lhs.M[3][3]*rhs.get_z() );
  return aux; 
  
}

template <class T,class U>
Matrix<T> operator * (U c, Matrix<T> m){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = c*m.M[i][j];        
        }
    }
   return out;
}

template <class T, class U>
Matrix<T> operator * (Matrix<T> m, U c){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = c*m.M[i][j];        
        }
    }
   return out; 
}

template <class T, class U>
Matrix<T> operator + (U c, Matrix<T> m){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = m.M[i][j];
            if (i == j ) out.M[i][i] = out.M[i][i] + c;
        }
    }
   return out; 
}

template <class T, class U>
Matrix<T> operator + (Matrix<T> m, U c){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = m.M[i][j];
            if (i == j ) out.M[i][i] = out.M[i][i] + c;
        }
    }
   return out; 
}

template <class T, class U>
Matrix<T> operator - (U c, Matrix<T> m){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = -m.M[i][j];
            if (i == j ) out.M[i][i] = out.M[i][i] + c;
        }
    }
   return out; 
}

template <class T, class U>
Matrix<T> operator - (Matrix<T> m, U c){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = m.M[i][j];
            if (i == j ) out.M[i][i] = out.M[i][i] - c;
        }
    }
   return out; 
}


template <class T, class U>
Matrix<T> operator / (Matrix<T> m, U c){
    Matrix<T> out;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            out.M[i][j] = m.M[i][j]/c;
        }
    }
   return out; 
}


#endif
