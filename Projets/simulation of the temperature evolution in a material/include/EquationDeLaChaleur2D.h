#ifndef ENSIIE_EQUATION2D_H
#define ENSIIE_EQUATION2D_H

#include "../include/EquationDeLaChaleur1D.h"


namespace ensiie {

/*!
*file EquationDeLaChaleur2D.h
* \brief La classe EquationDeLaChaleur2D représente l'équation de la chaleur et sa résolution numérique en 2D .
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal
*
*
*/
class EquationDeLaChaleur2D : public EquationDeLaChaleur{

    public: // structors
    EquationDeLaChaleur2D(Materiau m);
   
    public:
    /*!
    *\brief Calcule u(x,y,t) quelque soit x,y dans 0 à L et t dans 0 à tmax et crée un fichier contenant les valeurs.
    * 
    *\param[in] le nombre de points
    *\param[in] La longueur de la plaque.
    *\param[in] Le temps max de la propagation de la chaleur
    *\param[in] valeur de la température ambiante en Kelvin
    *\param[in] source de chaleur
    */
    void EvolutionTemperatureCasComplexe2D( int N,double L, double tmax,int u0, double f);// avec source de chaleur et condition à bord.
}; 


} // namespace ensiie

#endif // ENSIIE_EQUATION__H