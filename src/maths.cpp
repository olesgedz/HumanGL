//
// Created by Esmeralda Bednar on 12/19/20.
//

#include <math.h>
#include "maths.h"

float vec3::length()
{
    return  sqrt(x * x + y * y + z * z);
}

vec3 normalize(vec3 vector)
{
    float length = vector.length();
    return vec3(vector.x / length, vector.y / length, vector.z / length);
}

vec3 cross(vec3& vector1, vec3& vector2)
{
    float x = vector1.y * vector2.z - vector1.z * vector2.y;
    float y = vector1.z * vector2.x - vector1.x * vector2.z;
    float z = vector1.x * vector2.y - vector1.y * vector2.x;
    return vec3(x, y, z);
}

float dot(vec3& vector1, vec3& vector2)
{
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

mat4 look_at(vec3 eye, vec3 center, vec3 up)
{
    mat4 matrix;
    vec3 x, y, z;

    z = eye - center;
    z = normalize(z);
    y = up;
    x = cross(y, z);
    y = cross(z, x);
    x = normalize(x);
    y = normalize(y);
    matrix.mat[0] = x.x;
    matrix.mat[1] = x.y;
    matrix.mat[2] = x.z;
    matrix.mat[3] = -dot(x, eye);
    matrix.mat[4] = y.x;
    matrix.mat[5] = y.y;
    matrix.mat[6] = z.y;
    matrix.mat[7] = -dot(y, eye);
    matrix.mat[8] = z.x;
    matrix.mat[9] = z.y;
    matrix.mat[10] = z.z;
    matrix.mat[11] = -dot(z, eye);
    matrix.mat[12] = 0.0f;
    matrix.mat[13] = 0.0f;
    matrix.mat[14] = 0.0f;
    matrix.mat[15] = 1.0f;
}