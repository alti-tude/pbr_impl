#include "main.h"
#include<assert.h>

int main(){
    Vector2<Float> a(3.0f, 1.0f);
    Vector2<Float> b(1.0f, 1.0f);

    assert(a[0]==3 and a[1]==1);

    Vector2<Float> c = a+b;
    assert(c==Vector2<Float>(4.0f, 2.0f));

    c = a-b;
    assert(c==Vector2<Float>(2.0f, 0.0f));
    
    c -= a;
    assert(c==Vector2<Float>(-1.0f, -1.0f));

    c += 1;
    assert(c==Vector2<Float>(0.0f, 0.0f));
    
    c += b;
    assert(c==Vector2<Float>(1.0f, 1.0f));

    c -= 1;
    assert(c==Vector2<Float>(0.0f, 0.0f));
    
    c = 1.2+b;
    assert(c==Vector2<Float>(2.2, 2.2));

    c = 1-b;
    assert(c==Vector2<Float>(0.0f, 0.0f));

    c = -b;
    assert(c==Vector2<Float>(-1, -1));
    
    return 0;
}