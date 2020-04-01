#include "main.h"
#include<assert.h>

int main(){
    Vector3<int> a(3.0, 1.0, 1.0);
    Vector3<int> b(1.0, 1.0, 3.0);

    assert(a[0]==3 and a[1]==1 and a[2]==1);
    assert(b[0]==1 and b[1]==1 and b[2]==3);

    Vector3<int> c = a*b;
    assert(c==Vector3<int>(3.0, 1.0, 3.0));

    c *= 2.5; //autocast to int here as well
    assert(c==Vector3<int>(6.0, 2.0, 6.0));
    
    c *= b;
    assert(c==Vector3<int>(6.0, 2.0, 18.0));
    
    c = 2*b;
    assert(c==Vector3<int>(2.0, 2.0, 6.0));

    c = b*2;
    assert(c==Vector3<int>(2.0, 2.0, 6.0));

    c = a/b;
    assert(c==Vector3<int>(3.0/1, 1.0/1, 1.0/3));

    c = b;
    c /= 2;
    assert(c==Vector3<int>(1.0/2, 1.0/2, 3.0/2));
    
    c = a;
    c /= b;
    assert(c==Vector3<int>(3.0/1, 1.0/1, 1.0/3));
    
    c = 2/b;
    assert(c==Vector3<int>(2/1.0, 2/1.0, 2/3.0));

    c = b/2; //fails for denom = 0.x since auotocast to int.
    assert(c==Vector3<int>(1.0/2, 1.0/2, 3.0/2));

    return 0;
}