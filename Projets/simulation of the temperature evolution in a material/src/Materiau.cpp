/*!
*\file Materiau.cpp
* \brief La classe Materiau représente représente la matière utilisée pour réaliser un objet.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal

*
*
*/
#include "../include/Materiau.h"

 
namespace ensiie {

Materiau::Materiau(const char* materiau,double lambda, double rho, double c){

    this->materiau=materiau;
    this->lambda= lambda;
    this->rho = rho;
    this->c = c;
}

Materiau::Materiau(){

    this->materiau="none";
    this->lambda= 0;
    this->rho = 0;
    this->c = 0;
}








} // namespace ensiie