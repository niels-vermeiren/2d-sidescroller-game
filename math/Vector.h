//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_VECTOR_H
#define INC_2DSIDESCROLLER_VECTOR_H


class Vector {

public:
    float x;
    float y;
    Vector() {}
    Vector(float x, float y);
    Vector operator+ (const Vector &v) const;
    Vector operator- (const Vector &v) const;

};


#endif //INC_2DSIDESCROLLER_VECTOR_H
