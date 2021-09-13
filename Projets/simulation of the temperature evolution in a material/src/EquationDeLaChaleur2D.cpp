/*!
*\file EquationDeLaChaleur2D.cpp
* \brief La classe EquationDeLaChaleur représente l'équation de la chaleur et sa résolution en 1D.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal

*
*
*/

#include <numeric>
#include "../include/EquationDeLaChaleur2D.h"

#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>


namespace ensiie {




EquationDeLaChaleur2D::EquationDeLaChaleur2D(Materiau m):EquationDeLaChaleur(m){

    
    
}


void EquationDeLaChaleur2D::EvolutionTemperatureCasComplexe2D(int N,double L, double tmax,int u0, double f){
    Materiau m =  this->get_materiau();
    double dt, dx,dy;
    dt= tmax/N;
    dx= L/N;
    dy=L/N;
     double coef1 = (dt/(m.get_c()*m.get_rho()));
    double coef2 = (m.get_lambda()/(dx*dx));
    double coef3 = (m.get_lambda()/(dy*dy));
    double F=tmax*f*f;
    int a = (int)((L/6 * 100) +1);
    int b = (int)((2*L/6 * 100) +1);
    int c = (int)((4*L/6 * 100) +1);
    int d = (int)((5*L/6 * 100) +1);
    double ***U;
    U=new double**[N];
 
    //Les conditions initiales
    for(int i=0;i<=N-1;i++){
        U[i] = new double*[N+1];
        for(int j=0;j<N+1;j++){
         U[i][j]= new double[N+1];
        }}
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            U[0][i][j]=u0;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N+1;j++){
            U[i][0][j]=u0;
            U[i][j][0]=u0;
            U[i][N][j]=u0;
            U[i][j][N]=u0;
        }}
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if((j>a && j<b) || (j>c && j<d )){
            for(int k=1;k<a;k++){
                U[i][j][k] = U[i-1][j][k]+coef1*(coef2*(U[i-1][j+1][k]-2*U[i-1][j][k]+U[i-1][j-1][k])+coef3*(U[i-1][j][k+1]-2*U[i-1][j][k]+U[i-1][j][k-1]));
            }
            for(int k=17;k<b;k++){
                            U[i][j][k] = U[i-1][j][k]+coef1*(coef2*(U[i-1][j+1][k]-2*U[i-1][j][k]+U[i-1][j-1][k])+coef3*(U[i-1][j][k+1]-2*U[i-1][j][k]+U[i-1][j][k-1])+F);
                        }
            for(int k=b;k<c;k++){
                U[i][j][k] = U[i-1][j][k]+coef1*(coef2*(U[i-1][j+1][k]-2*U[i-1][j][k]+U[i-1][j-1][k])+coef3*(U[i-1][j][k+1]-2*U[i-1][j][k]+U[i-1][j][k-1]));
            }
            for(int k=c;k<d;k++){
                            U[i][j][k] = U[i-1][j][k]+coef1*(coef2*(U[i-1][j+1][k]-2*U[i-1][j][k]+U[i-1][j-1][k])+coef3*(U[i-1][j][k+1]-2*U[i-1][j][k]+U[i-1][j][k-1])+F);
                        }
            for(int k=d;k<N;k++){
                    U[i][j][k] = U[i-1][j][k]+coef1*(coef2*(U[i-1][j+1][k]-2*U[i-1][j][k]+U[i-1][j-1][k])+coef3*(U[i-1][j][k+1]-2*U[i-1][j][k]+U[i-1][j][k-1]));
                                    }
        }
            else {
                for(int k=1;k<100;k++){
                    U[i][j][k] = U[i-1][j][k]+coef1*(coef2*(U[i-1][j+1][k]-2*U[i-1][j][k]+U[i-1][j-1][k])+coef3*(U[i-1][j][k+1]-2*U[i-1][j][k]+U[i-1][j][k-1]));
                }
            }
    }}
    

    const char separateur(' ');
    std::ofstream sortie(m.get_nom(),std::ios::out);


     for (int i = 0; i < N; i++){
        for (int j = 0; j < N+1; j++){
            for(int k=0;k<N+1;k++){
                sortie << U[i][j][k] << separateur;
        }
        sortie<< std::endl;
    }
    }

     sortie.close();

    for (int i = 0; i < N; i++)
         delete[] U[i];
    delete[] U;
 }



} // namespace ensiie