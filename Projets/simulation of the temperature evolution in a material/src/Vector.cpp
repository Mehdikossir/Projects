/*!
*\file Vector.cpp
* \brief La classe vecteur définit un vecteur et les différentes oppérations sur ce dernier.
*\date 17/01/2021
*\author KOSSIR EL Mehdi - Karunanayakage Shamal

*
*
*/
#include "../include/Vector.h"

namespace ensiie {

/// Defines the default constructor for vectors
/// int size : the size of the vector
template <class T> Vector<T>::Vector(int size) {
    set_size(size);
    data_ = new T[size];
    if (!data_)
        throw std::runtime_error("Error when allocating memory for vector data.");
}

/// Defines the copy constructor for vectors
/// Vector copy : the vector to copy
template <class T> Vector<T>::Vector(const Vector<T>& copy) {
    set_size(copy.size_);
    data_ = new T[copy.size_];
    if (data_)
        for (int i = 0; i < size_; i++)
            data_[i] = copy.data_[i];
    else
        throw std::runtime_error("Error when allocating memory for vector data.");
}

/// Defines the default destructor for vectors
template <class T> Vector<T>::~Vector() {
    if (data_)
        delete[] data_;
}

/// Getter method for the size of a vector
/// returns the size of the vector
template <class T> int Vector<T>::get_size() const {
    if (size_ <= 0)
        throw std::runtime_error("Vector size is <= 0.");
    return size_;
}

/// Setter method for the size of a vector
/// int size : the size of the vector
template <class T> void Vector<T>::set_size(int size) {
    if (size <= 0)
        throw std::runtime_error("Vector size is <= 0.");
    size_ = size;
}

/// Overload the [] operator for a vector
template <class T> T Vector<T>::operator[](int index) const {
    if (index < 0 || index >= get_size())
        throw std::runtime_error("Index out of bounds.");
    return data_[index];
}

/// Overload the [] operator for a vector
template <class T> T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= get_size())
        throw std::runtime_error("Index out of bounds.");
    return data_[index];
}

/// Overload the = operator for a vector
template <class T> Vector<T>& Vector<T>::operator=(const Vector<T>& copy) {
    set_size(copy.get_size());
    if (&copy != this) {
        Vector<T> tmp = copy;
        T* tmp_data_ = data_;
        data_ = tmp.data_;
        tmp.data_ = tmp_data_;
    }
    return *this;
}

/// Calculate the pth norm of a vector
/// int p : calculate the pth norm (default : 2)
template <class T> double Vector<T>::norm(int p) {
    if (p < 1)
        throw std::runtime_error("Can't calculate norm for p < 1.");

    double sum = 0;
    for (int i = 0; i < get_size(); i++)
        sum += pow(abs((*this)[i]), p);
    return pow(sum, 1./p);;
}

/// Overload the << operator to display a vector
template <class T> std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    for (int i = 0; i < v.get_size(); i++)
        os << ((i == 0) ? "[" : ", ") << v[i];
    return os << "]";
}

/// Overload the + operator
template <class T> Vector<T> operator+(const Vector<T>& vect1, const Vector<T>& vect2) {
    Vector<T> r = Vector<T>(std::max(vect1.get_size(), vect2.get_size()));
    for (int i = 0; i < r.get_size(); i++)
        r[i] = ((i < vect1.get_size()) ? vect1[i] : 0) + ((i < vect2.get_size()) ? vect2[i] : 0);
    return r;
}

/// Overload the - operator
template <class T> Vector<T> operator-(const Vector<T>& vect1, const Vector<T>& vect2) {
    Vector<T> r = Vector<T>(std::max(vect1.get_size(), vect2.get_size()));
    for (int i = 0; i < r.get_size(); i++)
        r[i] = ((i < vect1.get_size()) ? vect1[i] : 0) - ((i < vect2.get_size()) ? vect2[i] : 0);
    return r;
}

/// Overload the * operator for two vectors
template <class T> Vector<T> operator*(const Vector<T>& vect1, const Vector<T>& vect2) {
    Vector<T> r = Vector<T>(std::max(vect1.get_size(), vect2.get_size()));
    for (int i = 0; i < r.get_size(); i++)
        r[i] = ((i < vect1.get_size()) ? vect1[i] : 0) * ((i < vect2.get_size()) ? vect2[i] : 0);
    return r;
}

/// Overload the * operator for a vector and a scalar
template <class T> Vector<T> operator*(const Vector<T>& vect, int scal) {
    Vector<T> r = Vector<T>(vect);
    for (int i = 0; i < r.get_size(); i++)
        r[i] *= scal;
    return r;
}
template <class T> Vector<T> operator*(int scal, const Vector<T>& vect) { return operator*(vect, scal); }

/// Overload the / operator for a vector and a scalar
template <class T> Vector<T> operator/(const Vector<T>& vect, int scal) {
    if (scal == 0)
        throw std::runtime_error("Error : division by 0.");

    Vector<T> r = Vector<T>(vect);
    for (int i = 0; i < r.get_size(); i++)
        r[i] /= scal;
    return r;
}

/// Calculate the cross product for two 3D vectors
template <class T> Vector<T> cross(const Vector<T>& vect1, const Vector<T>& vect2) {
    if (vect1.get_size() != vect2.get_size() || vect1.get_size() != 3)
        throw std::runtime_error("Both vector's sizes must be 3.");

    Vector<T> res = Vector<T>(3);
    res[0] = vect1[1] * vect2[2] - vect1[2] * vect2[1];
    res[1] = vect1[2] * vect2[0] - vect1[0] * vect2[2];
    res[2] = vect1[0] * vect2[1] - vect1[1] * vect2[0];
    return res;
}

std::vector<double> sum_vect(std::vector <double> vect1 ,std::vector <double> vect2 ){

    std::vector <double> res(vect1.size(),0);
    for (size_t i=0;i<vect1.size();i++){
        res[i]= vect1[i]+vect2[i];
    }
    return res;

}

} // namespace ensiie