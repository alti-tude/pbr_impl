#include "main.h"
#include<assert.h>

int main(){
    Vector3f a(3,3,3), b, c;
    coordinateSystem(a, &b, &c);
    assert(a.dot(b)<(Float)1e-8);
    assert(b.dot(c)<(Float)1e-8);
    assert(c.dot(a)<(Float)1e-8);

    std::cout << std::abs(a.length()-1) << std::endl;
    assert(std::abs(a.length()-1) < (Float)1e-6);
    assert(std::abs(b.length()-1) < (Float)1e-6);
    assert(std::abs(b.length()-1) < (Float)1e-6);
}