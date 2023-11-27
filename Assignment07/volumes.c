#include "base.h"

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

typedef enum typetag_e {
    CYLINDER,
    CUBOID,
    SPHERE,
} TypeTag;

typedef struct cylinder_s {
    double r, h;
} Cylinder;

typedef struct cuboid_s {
    double a, b, c;
} Cuboid;

typedef struct sphere_s {
    double r;
} Sphere;

typedef struct body_s {
    // todo
    TypeTag tag;
    struct cylinder_s Cylinder;
    struct cuboid_s Cuboid;
    struct sphere_s Sphere;
} Body;

/*
TypTag:
TypeTag wird verwendet, um zwischen verschiedenen Formen zu unterscheiden. 
Da die Tags Aufzählungen sind, kann der Compiler mithilfe der Switch-Anweisungen überprüfen,
welcher Fall der Aufzählung verwendet wird. In C sind Listen ganzzahlige Werte. 
Die Konstruktorfunktionen make_cylinder, make_cuboid und make_sphere werden verwendet, 
um Variablen für den jeweiligen Tag zu erstellen.
*/

Body make_cylinder(double r, double h) {
    // todo
    require("r and h must be a positive value", r > 0 && h > 0);
    Body body;
    body.tag = CYLINDER;
    body.Cylinder.r = r;
    body.Cylinder.h = h;
    return body;
}

Body make_cuboid(double a, double b, double c) {
    // todo
    require("a, b and c must be a positive value", a > 0 && b > 0 && c > 0 );
    Body body;
    body.tag = CUBOID;
    body.Cuboid.a = a;
    body.Cuboid.b = b;
    body.Cuboid.c = c;
    return body;
}

Body make_sphere(double r) {
    // todo
    require("r must be a positive value", r > 0);
    Body body;
    body.tag = SPHERE;
    body.Sphere.r = r;
    return body;
}

double volume(Body body) {
    switch (body.tag)
    {
    case SPHERE:
        return 4/3.0*M_PI*(body.Sphere.r*body.Sphere.r*body.Sphere.r);
        break;
    
    case CUBOID:
        return body.Cuboid.a*body.Cuboid.b*body.Cuboid.c;
        break;
    case CYLINDER:
        return M_PI*(body.Cylinder.r*body.Cylinder.r)*body.Cylinder.h;
        break;
    }
        
    return -1;
}

void volume_test(void) {
    test_within_d(volume(make_sphere(2)), 4 /3.0 * M_PI * 2 * 2 * 2, 1e-6);
    test_within_d(volume(make_cuboid(2, 3, 4)), 2 * 3 * 4, 1e-6);
    test_within_d(volume(make_cylinder(3, 4)), 4 * M_PI * 3 * 3 , 1e-6);
}

int main(void) {
    volume_test();
    return 0;
}
