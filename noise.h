#pragma once

#ifndef NOISE_H
#define NOISE_H
#include<math.h>

struct vector2 {
	float x;
	float y;
};

//ADAPTED FROM https://thebookofshaders.com/11/


//Dot product for vectors of lenght two
int dotProduct(vector2 vecA, vector2 vecB)
{
    int product = 0;
    product = product + vecA.x * vecB.x;
    product = product + vecA.y * vecB.y;
    return product;
}

float fract(float x) {
    return x - floor(x);
}



float random(vector2 input) {

    vector2 constant = vector2{ 12.9898, 78.233 };

    return (
        fract(
         sin(
              dotProduct(input, constant)
           )
        )
        * 43758.5453123 //Constant thingy
    );
}

vector2 addVec(vector2 a, vector2 b) {
    return(
        vector2{
            a.x + b.x,
            a.y + b.y
        }
    );
}

vector2 mulVec(vector2 a, vector2 b) {
    return(
        vector2{
            a.x * b.x,
            a.y * b.y
        }
    );
}

float mix(float x, float y, float a) {
    return(
        x * (1 - a) + y * a
        );
}

vector2 floorVec(vector2 input) {
    return(vector2{ floor(input.x), floor(input.y) });
}

vector2 fractVec(vector2 input) {
    return(vector2{ fract(input.x), fract(input.y) });
}

float noise(float x, float y) {
    vector2 input = vector2{ x, y };
    vector2 i = floorVec(input);
    vector2 f = fractVec(input);

    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(addVec(i,vector2{1.0, 0.0}));
    float c = random(addVec(i,vector2{0.0, 1.0}));
    float d = random(addVec(i,vector2{1.0, 1.0}));

    // Smooth Interpolation

    // Cubic Hermine Curve.  Same as SmoothStep()
    vector2 u = { mulVec(mulVec(f,f),  vector2 { 3- f.x * 2.0f, 3-  f.y * 2.0f }) };
    // u = smoothstep(0.,1.,f);

    // Mix 4 coorners percentages
    return mix(a, b, u.x) +
        (c - a) * u.y * (1.0 - u.x) +
        (d - b) * u.x * u.y;
}

#endif // !NOISE_H