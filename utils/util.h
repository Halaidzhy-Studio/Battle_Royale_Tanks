#ifndef UTIL_H
#define UTIL_H

#define B2SCALE 10

float fromB2(float b2cor){
    return b2cor * B2SCALE;
}

float toB2(float qtcor){
    return qtcor/B2SCALE;
}

#endif // UTIL_H
