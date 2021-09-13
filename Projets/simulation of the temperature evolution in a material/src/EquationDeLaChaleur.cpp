/*!
*\file EquationDeLaChaleur.cpp
* \brief La classe EquationDeLaChaleur représente l'équation de la chaleur et sa résolution.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal

*
*
*/

#include <numeric>
#include "../include/EquationDeLaChaleur.h"

#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>


namespace ensiie {

EquationDeLaChaleur::EquationDeLaChaleur(Materiau m){

    this->materiau=m;
    
}

std::vector<double> EquationDeLaChaleur::EvolutionTemperatureCasSimple(double a ,std::vector<double> T ){
    int N= T.size();
    std::vector<double> b(N,0);//coeff pour la matrice L
    std::vector<double> c(N-1,0);//coeff pour la matrice U
    std::vector<double> y(N,0);
    std::vector<double> x(N,0);
    b[0]=1+2*a;
    y[0]=T[0];
   


    for (int i =1;i<N;i++){
        c[i-1]=-(a)/b[i-1]; 
        b[i]=(1+2*a)-(-a)*c[i-1]; 
    }

    //LY=F
   
    for (int i =1;i<N;i++){
        y[i]=(T[i])-c[i-1]*y[i-1];
    }
    //UX =Y
     x[N-1]=y[N-1]/b[N-1];
    for (int i =N-2;i>0;i--){
        x[i]=(y[i]-(-a)*x[i+1])/b[i];
       
    }
    

    return x;

}





 






} // namespace ensiie