#ifndef VECTOR3_H
#define VECTOR3_H

#include"core.h"

#include<assert.h>
#include<typeinfo>
#include<string>

template<typename T>
class Vector3{
public:
    T x,y,z;

public:
    Vector3():x(0), y(0), z(0) {}

    Vector3(T x, T y, T z): x(x), y(y), z(z) {
        assert(!HasNaNs());
    }

    char type() const{
        return *typeid(T).name();
    }

    T operator[](int index) const{
        assert(index<=2 and index>=0);
        if(index==0) return x;
        if(index==1) return y;
        return z;
    }

    bool HasNaNs() const{
        return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }

    /* ------------------------ addition -------------------- */
    Vector3<T> operator+(Vector3<T> const &v) const{
        return Vector3<T>(x+v.x, y+v.y, z+v.z);
    }

    Vector3<T> operator+(T const scalar) const{
        return Vector3<T>(x+scalar, y+scalar, z+scalar);
    }

    void operator+=(Vector3<T> const &v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    void operator+=(T const scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
    }

    friend Vector3<T> operator+(T const scalar, Vector3<T> const &v){
        return v+scalar;
    }

    /* ------------------------ subtraction -------------------- */

    Vector3<T> operator-(Vector3<T> const &v) const{
        return Vector3<T>(x-v.x, y-v.y, z-v.z);
    }

    Vector3<T> operator-(T const scalar) const{
        return Vector3<T>(x-scalar, y-scalar, z-scalar);
    }

    Vector3<T> operator-() const{
        return Vector3<T>(-x, -y, -z);
    }

    void operator-=(Vector3<T> const &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    void operator-=(T const scalar) {
        x -= scalar;
        y -= scalar;
        z -= scalar;
    }

    friend Vector3<T> operator-(T const scalar, Vector3<T> const &v){
        return Vector3<T>(scalar-v.x, scalar-v.y, scalar-v.z);
    }

    /* ---------------mutiply--------------------------------*/
    Vector3<T> operator*(Vector3<T> const &v) const{
        return Vector3<T>(x*v.x, y*v.y, z*v.z);
    }

    Vector3<T> operator*(T const scalar) const{
        return Vector3<T>(x*scalar, y*scalar, z*scalar);
    }

    void operator*=(Vector3<T> const &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
    }

    void operator*=(T const scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    friend Vector3<T> operator*(T const scalar, Vector3<T> const &v){
        return v*scalar;
    }

    /* ---------------divide--------------------------------*/
    Vector3<T> operator/(Vector3<T> const &v) const{
        assert(v.x!=0 and v.y!=0 and v.z!=0);
        return Vector3<T>(x/v.x, y/v.y, z/v.z);
    }

    Vector3<T> operator/(T const scalar) const{
        assert(scalar!=0);
        double reciprocal = 1.0/scalar;
        return Vector3<T>(x*reciprocal, y*reciprocal, z*reciprocal);
    }

    void operator/=(Vector3<T> const &v) {
        assert(v.x!=0 and v.y!=0 and v.z!=0);
        x /= v.x;
        y /= v.y;
        z /= v.z; 
    }

    void operator/=(T const scalar) {
        assert(scalar!=0);
        double reciprocal = 1.0/scalar;
        x *= reciprocal;
        y *= reciprocal;
        z *= reciprocal; 
    }

    friend Vector3<T> operator/(T const scalar, Vector3<T> const &v){
        assert(v.x!=0 and v.y!=0 and v.z!=0);
        return Vector3<T>(scalar/v.x, scalar/v.y, scalar/v.z);
    }
    
    /* ---------------geometry------------------------------------*/
    T dot(Vector3<T> const& v) const{
        return x*v.x+y*v.y+z*v.z;
    }

    T absDot(Vector3<T> const& v) const{
        return std::abs(this->dot(v));
    }

    Vector3<T> cross(Vector3<T> const&v){
        double x = this->x, y = this->y, z = this->z;
        double a=v.x, b=v.y, c=v.z;
        return Vector3<T>(y*c - z*b, z*a - x*c, x*b - y*a);
    }

    Float length() const{
        return (Float)sqrt((*this).dot(*this));
    }

    void normalise(){
        assert(x!=0 or y!=0 or z!=0);

        T len = length();
        x /= len;
        y /= len;
        z /= len;
    }
    
    /* ---------------misc-----------------------------------*/
    T minComponent() const{
        return std::min(x, std::min(y,z));
    }

    T maxComponent() const{
        return std::max(x, std::max(y,z));
    }

    T mixDimension() const{
        T mi = this->mixComponent();
        return mi == x? 0 : (mi==y? 1 : 2);
    }

    T maxDimension() const{
        T ma = this->maxComponent();
        return ma == x? 0 : (ma==y? 1 : 2);
    }

    /* ---------------output---------------------------------*/
    friend std::ostream& operator<<(std::ostream &out, Vector3<T> const &v){
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }

    friend bool operator==(Vector3<T> const &v1, Vector3<T> const &v2){
        return v1.x==v2.x && v1.y==v2.y and v1.z==v2.z;
    }

    friend bool operator!=(Vector3<T> const &v1, Vector3<T> const &v2){
        return !(v1==v2);
    }
};

template <typename T>
T min(Vector3<T> const& v1, Vector3<T> const& v2){
    return Vector3<T>(std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z));
}

template<typename T>
Vector3<T> permute(Vector3<T> const& v, int x, int y, int z){
    return Vector3<T>(v[x], v[y], v[z]);
}

#endif