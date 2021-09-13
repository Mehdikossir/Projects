/*!
*\file main.cpp
* \brief La classe Materiau représente la matière utilisée pour réaliser un objet.
*\n On caractérise un matériau par sa conductivité thermique , sa masse volumique et sa chaleur massique
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal
*
*
*/

/*!
*
* \mainpage Résolution numérique de l'équation de la chaleur.
*\n Ce projet  en C++ s'intéresse à la résolutin numérique de l'équation de la chaleur en 1D et 2D.
*L'objectif est de simuler l’évolution de la température dans un matériau.
*\n Le projet consistera en la résolution de l’équation de la chaleur en utilisant la méthode des différences finies, dans le cas implicite, en considérant 2 objets : une barre infiniment mince (d = 1) de longueur L et une plaque infiniment mince (d = 2) en respectant les condition au bord.
*/

#include <iostream>
#include <chrono>
#include <thread>

#include "../include/EquationDeLaChaleur2D.h"
#include <string.h>




using namespace std;


int main()
{
     try
    {
        
    int u0 = 13;
    int N=100;
    int L=1;
    double tmax =16;
    double f =80;
   /*------------------------------*/
    /*       Application numérique sur une bare (cas 1D) pour les 3 matériaux  */
    ensiie::Materiau cuivre("cuivre",389, 8940,380);
    ensiie::Materiau fer("fer",80.2,7874,440);
    ensiie::Materiau verre("verre",1.2,2530,840);
    ensiie::Materiau polystyrene("polystyrene",0.1,1040,1200);
    ensiie::EquationDeLaChaleur1D equation1(cuivre);
    ensiie::EquationDeLaChaleur1D equation2(fer);
    ensiie::EquationDeLaChaleur1D equation3(verre);
    ensiie::EquationDeLaChaleur1D equation4(polystyrene);
    auto start1 = std::chrono::system_clock::now();
    std::thread t1(&ensiie::EquationDeLaChaleur1D::EvolutionTemperatureCasComplexe1D,equation1,N,L,tmax,273.15+u0,273.15+f);
      t1.join();
     std::thread t2(&ensiie::EquationDeLaChaleur1D::EvolutionTemperatureCasComplexe1D,equation2,N,L,tmax,273.15+u0,273.15+f);
      t2.join();
     std::thread t3(&ensiie::EquationDeLaChaleur1D::EvolutionTemperatureCasComplexe1D,equation3,N,L,tmax,273.15+u0,273.15+f);
      t3.join();
     std::thread t4(&ensiie::EquationDeLaChaleur1D::EvolutionTemperatureCasComplexe1D,equation4,N,L,tmax,273.15+u0,273.15+f);
      t4.join(); 
    auto end1 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cout << "Elapsed time with thread 1D: " << elapsed1.count() << "s\n";
    
   /*------------------------------*/
    /*       Application numérique sur une bare (cas 2D) pour les 3 matériaux  */

    ensiie::Materiau cuivre2d("cuivre2d",389, 8940,380);
    ensiie::Materiau fer2d("fer2d",80.2,7874,440);
    ensiie::Materiau verre2d("verre2d",1.2,2530,840);
    ensiie::Materiau polystyrene2d("polystyrene2d",0.1,1040,1200);

    ensiie::EquationDeLaChaleur2D equation5(cuivre2d);
    ensiie::EquationDeLaChaleur2D equation6(fer2d);
    ensiie::EquationDeLaChaleur2D equation7(verre2d);
    ensiie::EquationDeLaChaleur2D equation8(polystyrene2d);
    
     auto start2 = std::chrono::system_clock::now();
    std::thread t5(&ensiie::EquationDeLaChaleur2D::EvolutionTemperatureCasComplexe2D,equation5,N,L,tmax,273.15+u0,273.15+f);
      t5.join();
    std::thread t6(&ensiie::EquationDeLaChaleur2D::EvolutionTemperatureCasComplexe2D,equation6,N,L,tmax,273.15+u0,273.15+f);
      t6.join();
     std::thread t7(&ensiie::EquationDeLaChaleur2D::EvolutionTemperatureCasComplexe2D,equation7,N,L,tmax,273.15+u0,273.15+f);
      t7.join();
     std::thread t8(&ensiie::EquationDeLaChaleur2D::EvolutionTemperatureCasComplexe2D,equation8,N,L,tmax,273.15+u0,273.15+f);
      t8.join(); 
    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "Elapsed time with thread 2D: " << elapsed2.count() << "s\n";
    
    
        
    }
    catch(const char *str)
    {
        std::cout << str << std::endl;
    }

    return 0;

 
  

}