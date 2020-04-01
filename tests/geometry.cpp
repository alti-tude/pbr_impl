#include "main.h"
#include<assert.h>

int main(){
    Vector3<Float> a(-3.0, -1.0, 1.0);
    Vector3<Float> b(1.0, 1.0, 3.0);

    assert(a[0]==-3 and a[1]==-1 and a[2]==1);
    assert(b[0]==1 and b[1]==1 and b[2]==3);

    assert(a.absDot(b) == 1);
    assert(b.dot(a) == -1);

    assert(a.cross(b)==Vector3<Float>(-4, 10, -2));
    assert(b.cross(a)==-Vector3<Float>(-4, 10, -2));
    assert(std::sqrt(a.dot(a)) == a.length());

    b.normalise();
    assert(b.dot(b)==1);
    
    b.x = b.y = b.z = 0;
    assert(b.dot(b)==0);
    assert(b.length()==0);
    return 0;
}