#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "vector3.h" //! maintain the order of imports as vector3 needed in vector2
#include "vector2.h"

typedef Vector2<int> Vector2i;
typedef Vector2<Float> Vector2f;
typedef Vector3<int> Vector3i;
typedef Vector3<Float> Vector3f;

template <typename T>
void coordinateSystem(Vector3<T> &v1, Vector3<T> *v2, Vector3<T> *v3){
    //* returns 3 normalised (unit) vectors (inside the pointers)
    
    v1.normalise();

    *v2 = Vector3<T>(0, v1.z, -v1.y);
    v2->normalise();

    *v3 = v1.cross(*v2); 
}

#endif