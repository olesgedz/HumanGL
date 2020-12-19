//
// Created by Esmeralda Bednar on 12/19/20.
//

#ifndef HUMAGL_MATHS_H
#define HUMAGL_MATHS_H

struct vec3
{
    float x;
    float y;
    float z;
    vec3() : x(0.0f), y(0.0f), z(0.0f) {};
    vec3(float x, float y, float z) : x(x), y(y), z(z) {};
    vec3 operator +(vec3& other)
    {
        return vec3(x + other.x, y + other.y, z + other.z);
    }
    vec3 operator -(vec3& other)
    {
        return vec3(x - other.x, y - other.y, z - other.z);
    }
    float length();
};

struct mat4
{
    float mat[16];
    mat4()
    {
        for (int i = 0; i < 16; ++i)
            mat[i] = 0.0f;
    };
    mat4(mat4& other)
    {
        for (int i = 0; i < 16; ++i)
            mat[i] = other.mat[i];
    };
};

vec3    normalize(vec3 vector);
vec3    cross(vec3& vector1, vec3& vector2);
float   dot(vec3& vector1, vec3& vector2);
mat4    look_at(vec3 eye, vec3 center, vec3 up);

#endif //HUMAGL_MATHS_H
