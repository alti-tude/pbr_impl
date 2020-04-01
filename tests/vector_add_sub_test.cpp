#include "main.h"
#include<assert.h>

int main(){
    Vector3<Float> a(3.0f, 1.0f, 1.0f);
    Vector3<Float> b(1.0f, 1.0f, 3.0f);

    assert(a[0]==3 and a[1]==1 and a[2]==1);

    Vector3<Float> c = a+b;
    assert(c==Vector3<Float>(4.0f, 2.0f, 4.0f));

    c = a-b;
    assert(c==Vector3<Float>(2.0f, 0.0f, -2.0f));
    
    c -= a;
    assert(c==Vector3<Float>(-1.0f, -1.0f, -3.0f));

    c += 1;
    assert(c==Vector3<Float>(0.0f, 0.0f, -2.0f));
    
    c += b;
    assert(c==Vector3<Float>(1.0f, 1.0f, 1.0f));

    c -= 1;
    assert(c==Vector3<Float>(0.0f, 0.0f, 0.0f));
    
    c = 1+b;
    assert(c==Vector3<Float>(2.0f, 2.0f, 4.0f));

    c = 1-b;
    assert(c==Vector3<Float>(0.0f, 0.0f, -2.0f));

    c = -b;
    assert(c==Vector3<Float>(-1, -1, -3));

    return 0;
}