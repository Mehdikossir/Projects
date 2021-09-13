#ifndef ENSIIE_EQUATION1D_H
#define ENSIIE_EQUATION1D_H

#include "../include/EquationDeLaChaleur.h"


namespace ensiie {

/*!
*file EquationDeLaChaleur1D.h
* \brief La classe EquationDeLaChaleur1D représente l'équation de la chaleur et sa résolution numérique en 1D.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal
*
*
*/
class EquationDeLaChaleur1D : public EquationDeLaChaleur{

    public: // structors
    EquationDeLaChaleur1D(Materiau m);
   
    public:
    /*!
    *\brief Calcule u(x,t) quelque soit x dans 0 à L et t dans 0 à tmax  crée un fichier contenant les valeurs.
    * 
    *\param[in] le nombre de points
    *\param[in] La longueur de la bare.
    *\param[in] Le temps max de la propagation de la chaleur
    *\param[in] valeur de la température ambiante en Kelvin
    * \param[in] source de chaleur
    */
    void EvolutionTemperatureCasComplexe1D( int N,double L, double tmax,int u0, double f);// avec source de chaleur et condition à bord.
}; 


} // namespace ensiie

#endif // ENSIIE_EQUATION__H