/*!
*\file EquationDeLaChaleur1D.cpp
* \brief La classe EquationDeLaChaleur représente l'équation de la chaleur et sa résolution en 1D.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal

*
*
*/

#include <numeric>
#include "../include/EquationDeLaChaleur1D.h"

#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>


namespace ensiie {




EquationDeLaChaleur1D::EquationDeLaChaleur1D(Materiau m):EquationDeLaChaleur(m){

    
    
}


void EquationDeLaChaleur1D::EvolutionTemperatureCasComplexe1D(int N,double L, double tmax,int u0, double f){
    Materiau m =  this->get_materiau();
    double dt, dx;
    dt= tmax/N;
    dx= L/N;
    double coef= (m.get_lambda()*dt)/(m.get_c()*m.get_rho()*(dx*dx));
    double F1=tmax*f*f;
    std::vector<double> F(N+1,0);
    for(int i=(L/10)*100;i<=(2*L/10)*100;i++){
        F[i]=(F1)*dt/(m.get_c()*m.get_rho());
    }
    for(int j=(5*L/10)*100;j<=(6*L/10)*100;j++){
        F[j]=(F1*0.75)*dt/(m.get_c()*m.get_rho());
    }
    

    std::vector<std::vector<double> > temp;
    std::vector<double> tp;
    temp.push_back(std::vector<double>(101,u0));

    for (int i = 1; i < N; i++){
        tp=temp[i-1];
        tp[0]=tp[0]+coef*u0;
        tp[N]=tp[N]+coef*u0;
        temp.push_back(EvolutionTemperatureCasSimple(coef,sum_vect(tp,F)));
     

        temp[i][0]=u0;
        temp[i][N]=u0;
    }
    const char separateur(' ');
    std::ofstream sortie(m.get_nom(),std::ios::out);


     for (int i = 0; i < N; i++){
        for (int j = 0; j < N+1; j++){
        
            sortie << temp[i][j] << separateur;
        }
        sortie<< std::endl;
     }

     sortie.close();
 }






} // namespace ensiie