#ifndef ENSIIE_VECTOR_H
#define ENSIIE_VECTOR_H

#include <stdio.h>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <vector>


namespace ensiie {
/*!
*file Vector.h
*\brief La classe vecteur définit un vecteur et les différentes oppérations sur ce dernier.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal
*
*
*/

template <class T> class Vector {
    int size_;
    T* data_;

    public:
        Vector(int); // Constructor
        Vector(const Vector<T>&); // Copy constructor
        ~Vector(); // Destructor

        int get_size() const; // Getter method for the size of a vector
        void set_size(int); // Setter method for the size of a vector

        T operator[](int) const; // Overload the [] operator for a vector
        T& operator[](int); // Overload the [] operator for a vector

        Vector<T>& operator=(const Vector<T>&); // Overload the = operator for a vector

        double norm(int = 2); // Calculate the pth norm of a vector
};

template <class T> std::ostream& operator<<(std::ostream&, const Vector<T>&); // Overload the << operator

template <class T> Vector<T> operator+(const Vector<T>&, const Vector<T>&); // Overload the + operator
template <class T> Vector<T> operator-(const Vector<T>&, const Vector<T>&); // Overload the - operator

template <class T> Vector<T> operator*(const Vector<T>&, const Vector<T>&); // Overload the * operator
template <class T> Vector<T> operator*(const Vector<T>&, int); // Overload the * operator
template <class T> Vector<T> operator*(int, const Vector<T>&); // Overload the * operator

template <class T> Vector<T> operator/(const Vector<T>&, int); // Overload the / operator

template <class T> Vector<T> cross(const Vector<T>&, const Vector<T>&); // Cross product for 3D vectors
std::vector<double> sum_vect(std::vector <double> ,std::vector <double> );

} // namespace ensiie

#endif // ENSIIE_VECTOR_H