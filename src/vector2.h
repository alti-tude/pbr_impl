#ifndef VECTOR2_H
#define VECTOR2_H

#include"core.h"

#include<assert.h>
#include<typeinfo>
#include<string>

template<typename T>
class Vector2{
public:
    T x,y;

public:
    Vector2():x(0), y(0) {}

    Vector2(T x, T y): x(x), y(y) {
        assert(!HasNaNs());
    }

    char type() const{
        return *typeid(T).name();
    }

    T operator[](int index) const{
        assert(index<=1 and index>=0);
        if(index==0) return x;
        return y;
    }

    bool HasNaNs() const{
        return std::isnan(x) || std::isnan(y);
    }

    /* ------------------------ addition -------------------- */
    Vector2<T> operator+(Vector2<T> const &v) const{
        return Vector2<T>(x+v.x, y+v.y);
    }

    Vector2<T> operator+(T const scalar) const{
        return Vector2<T>(x+scalar, y+scalar);
    }

    void operator+=(Vector2<T> const &v) {
        x += v.x;
        y += v.y;
    }

    void operator+=(T const scalar) {
        x += scalar;
        y += scalar;
    }

    friend Vector2<T> operator+(T const scalar, Vector2<T> const &v){
        return v+scalar;
    }

    /* ------------------------ subtraction -------------------- */

    Vector2<T> operator-(Vector2<T> const &v) const{
        return Vector2<T>(x-v.x, y-v.y);
    }

    Vector2<T> operator-(T const scalar) const{
        return Vector2<T>(x-scalar, y-scalar);
    }

    Vector2<T> operator-() const{
        return Vector2<T>(-x, -y);
    }

    void operator-=(Vector2<T> const &v) {
        x -= v.x;
        y -= v.y;
    }

    void operator-=(T const scalar) {
        x -= scalar;
        y -= scalar;
    }

    friend Vector2<T> operator-(T const scalar, Vector2<T> const &v){
        return Vector2<T>(scalar-v.x, scalar-v.y);
    }

    /* ---------------mutiply--------------------------------*/
    Vector2<T> operator*(Vector2<T> const &v) const{
        return Vector2<T>(x*v.x, y*v.y);
    }

    Vector2<T> operator*(T const scalar) const{
        return Vector2<T>(x*scalar, y*scalar);
    }

    void operator*=(Vector2<T> const &v) {
        x *= v.x;
        y *= v.y;
    }

    void operator*=(T const scalar) {
        x *= scalar;
        y *= scalar;
    }

    friend Vector2<T> operator*(T const scalar, Vector2<T> const &v){
        return v*scalar;
    }

    /* ---------------divide--------------------------------*/
    Vector2<T> operator/(Vector2<T> const &v) const{
        assert(v.x!=0 and v.y!=0);
        return Vector2<T>(x/v.x, y/v.y);
    }

    Vector2<T> operator/(T const scalar) const{
        assert(scalar!=0);
        double reciprocal = 1.0/scalar;
        return Vector2<T>(x*reciprocal, y*reciprocal);
    }

    void operator/=(Vector2<T> const &v) {
        assert(v.x!=0 and v.y!=0);
        x /= v.x;
        y /= v.y;
    }

    void operator/=(T const scalar) {
        assert(scalar!=0);
        double reciprocal = 1.0/scalar;
        x *= reciprocal;
        y *= reciprocal;
    }

    friend Vector2<T> operator/(T const scalar, Vector2<T> const &v){
        assert(v.x!=0 and v.y!=0);
        return Vector2<T>(scalar/v.x, scalar/v.y);
    }
    
    /* ---------------geometry------------------------------------*/
    T dot(Vector2<T> const& v) const{
        return x*v.x+y*v.y;
    }

    T absDot(Vector2<T> const& v) const{
        return std::abs(this->dot(v));
    }

    Vector3<T> cross(Vector2<T> const&v){ //! remember to keep vector3
        double x = this->x, y = this->y;
        double a=v.x, b=v.y;
        return Vector3<T>(0,0, x*b - y*a);
    }

    Float length() const{
        return (Float)sqrt((*this).dot(*this));
    }

    void normalise(){
        assert(x!=0 or y!=0);
        assert(type()!='i');

        T len = length();
        x /= len;
        y /= len;
    }
    
    /* ---------------misc-----------------------------------*/
    T minComponent() const{
        return std::min(x, y);
    }

    T maxComponent() const{
        return std::max(x, y);
    }

    T mixDimension() const{
        T mi = this->mixComponent();
        return mi == x? 0 : 1;
    }

    T maxDimension() const{
        T ma = this->maxComponent();
        return ma == x? 0 : 1;
    }

    /* ---------------output---------------------------------*/
    friend std::ostream& operator<<(std::ostream &out, Vector2<T> const &v){
        out << "(" << v.x << ", " << v.y <<  ")";
        return out;
    }

    friend bool operator==(Vector2<T> const &v1, Vector2<T> const &v2){
        return v1.x==v2.x && v1.y==v2.y;
    }
};

template <typename T>
T min(Vector2<T> const& v1, Vector2<T> const& v2){
    return Vector2<T>(std::min(v1.x, v2.x), std::min(v1.y, v2.y));
}

template<typename T>
Vector2<T> permute(Vector2<T> const& v, int x, int y){
    return Vector2<T>(v[x], v[y]);
}

#endif