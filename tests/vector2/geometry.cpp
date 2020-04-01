#include "main.h"
#include<assert.h>

int main(){
    Vector2<Float> a(-3.0, -1.0);
    Vector2<Float> b(1.0, 1.0);

    assert(a[0]==-3 and a[1]==-1);
    assert(b[0]==1 and b[1]==1);

    assert(a.absDot(b) == 4);
    assert(b.dot(a) == -4);

    assert(a.cross(b)==Vector3<Float>(0, 0, -2));
    assert(b.cross(a)==Vector3<Float>(0, 0, 2));
    assert(std::sqrt(a.dot(a)) == a.length());

    b.normalise();
    assert(b.dot(b)-1.0<(Float)1e-8);
    
    b.x = b.y = 0;
    assert(b.dot(b)==0);
    assert(b.length()==0);
    return 0;
}