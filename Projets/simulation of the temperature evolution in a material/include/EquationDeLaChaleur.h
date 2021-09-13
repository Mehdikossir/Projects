#ifndef ENSIIE_EQUATION_H
#define ENSIIE_EQUATION_H

#include "Materiau.h"
#include "Vector.h"
#include <vector>


namespace ensiie {

/*!
*file EquationDeLaChaleur.h
* \brief La classe EquationDeLaChaleur représente l'équation de la chaleur et sa résolution numérique .
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal
*
*
*/
class EquationDeLaChaleur{
   
    private:
   
       Materiau materiau;

    public: // structors
    EquationDeLaChaleur(Materiau m);
    
  

    public: // getters
    Materiau get_materiau(){return materiau;}
    

    public: // setters 
    void set_materiau(Materiau m){materiau = m;}

    public:
    /*!
    *
    * \brief Résolution de l'équation de la chaleur à 1D implicite dans le cas simple sans source de chaleur ni condition à bord en utilisant la sécomposition LU pour une matrice tridiagonale
    *
    *\param[in] coefficient de diffusivité thermique
    *\param[in] vecteur qui contient les 101 valeures de la température en Kelvin à l'instant i.
    *
    * \return les valeurs de la température en Kelvin à l'instant i+1
    */
    std::vector<double> EvolutionTemperatureCasSimple(double a ,std::vector<double> T ); // sans source de chaleur ni condition à bord.

    
}; 


} // namespace ensiie

#endif // ENSIIE_EQUATION__H