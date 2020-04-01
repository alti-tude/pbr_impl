#include "main.h"
#include<assert.h>

int main(){
    Vector2<int> a(3.0, 1.0);
    Vector2<int> b(1.0, 1.0);

    assert(a[0]==3 and a[1]==1);
    assert(b[0]==1 and b[1]==1);

    Vector2<int> c = a*b;
    assert(c==Vector2<int>(3.0, 1.0));

    c *= 2.5; //autocast to int here as well
    assert(c==Vector2<int>(6.0, 2.0));
    
    c *= b;
    assert(c==Vector2<int>(6.0, 2.0));
    
    c = 2*b;
    assert(c==Vector2<int>(2.0, 2.0));

    c = b*2;
    assert(c==Vector2<int>(2.0, 2.0));

    c = a/b;
    assert(c==Vector2<int>(3.0/1, 1.0/1));

    c = b;
    c /= 2;
    assert(c==Vector2<int>(1.0/2, 1.0/2));
    
    c = a;
    c /= b;
    assert(c==Vector2<int>(3.0/1, 1.0/1));
    
    c = 2/b;
    assert(c==Vector2<int>(2/1.0, 2/1.0));

    c = b/2; //fails for denom = 0.x since auotocast to int.
    assert(c==Vector2<int>(1.0/2, 1.0/2));

    return 0;
}