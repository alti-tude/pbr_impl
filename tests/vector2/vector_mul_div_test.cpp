#include "main.h"
#include<assert.h>

int main(){
    Vector2<Float> a(3.0, 1.0);
    Vector2<Float> b(1.0, 1.0);

    assert(a[0]==3 and a[1]==1);
    assert(b[0]==1 and b[1]==1);

    Vector2<Float> c = a*b;
    assert(c==Vector2<Float>(3.0, 1.0));

    c *= 2;
    assert(c==Vector2<Float>(6.0, 2.0));
    
    c *= b;
    assert(c==Vector2<Float>(6.0, 2.0));
    
    c = 2*b;
    assert(c==Vector2<Float>(2.0, 2.0));

    c = b*2;
    assert(c==Vector2<Float>(2.0, 2.0));

    c = a/b;
    assert(c==Vector2<Float>(3.0/1, 1.0/1));

    c = b;
    c /= 2;
    assert(c==Vector2<Float>(1.0/2, 1.0/2));
    
    c = a;
    c /= b;
    assert(c==Vector2<Float>(3.0/1, 1.0/1));
    
    c = 2/b;
    assert(c==Vector2<Float>(2/1.0, 2/1.0));

    c = b/2; 
    assert(c==Vector2<Float>(1.0/2, 1.0/2));

    return 0;
}