

#ifndef ENSIIE_MATERIAU_H
#define ENSIIE_MATERIAU_H
#include "Vector.h"

namespace ensiie {

/*!
*file Materiau.h
* \brief La classe Materiau représente la matière utilisée pour réaliser un objet.
*\n On caractérise un matériau par sa conductivité thermique , sa masse volumique et sa chaleur massique
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal
*
*
*/
class Materiau{
   
    private:
   
        const char* materiau; // le nom du materiau utilisé
        double lambda; // la conductivité thermique
        double rho; // la masse volumique
        double c; // la chaleur massique

    public: // structors
    Materiau(const char* materiaux, double lambda, double rho, double c);
    Materiau();
    
  

    public: // getters
    const char* get_nom(){return materiau;}
    double get_lambda(){return lambda;}
    double get_rho(){return rho;}
    double get_c(){return c; }

    public: // setters
    void set_nom(const char* m){materiau = m;}
    void set_lambda(double l){lambda =l ;}
    void set_rho(double r){rho=r;}
    void set_c(double c){this-> c = c;}

    
}; 


} // namespace ensiie

#endif // ENSIIE_MATERIAU_H