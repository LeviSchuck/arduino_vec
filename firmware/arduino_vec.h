#include <math.h>
#ifndef VEC_H_
#define VEC_H_

class Vec2 {
public:
  float x;
  float y;
  Vec2 (float _x, float _y) {
    x = _x;
    y = _y;
  }
  Vec2 (const Vec2 & other) {
    x = other.x;
    y = other.y;
  }
  Vec2() {
    x = 0;
    y = 0;
  }
  float length() {
    return sqrt(x * x + y * y);
  }
  float dot(const Vec2 & v) {
    return x * v.x + y * v.y;
  }
  Vec2 norm() {
    float l = length();
    Vec2 res;
    if(l <= 0) return res;
    res.x = x / l;
    res.y = y / l;
    return res;
  }
  Vec2 operator*(const Vec2 & o) const {
    return Vec2(x * o.x, y * o.y);
  }
  Vec2 operator*(float o) const {
    return Vec2(x * o, y * o);
  }
  Vec2 operator/(const Vec2 & o) const {
    return Vec2(x / o.x, y / o.y);
  }
  Vec2 operator/(float o) const {
    return Vec2(x / o, y / o);
  }
  Vec2 operator+(const Vec2 & o) const {
    return Vec2(x + o.x, y + o.y);
  }
  Vec2 operator+(float o) const {
    return Vec2(x + o, y + o);
  }
  Vec2 operator-(const Vec2 & o) const {
    return Vec2(x - o.x, y - o.y);
  }
  Vec2 operator-(float o) const {
    return Vec2(x - o, y - o);
  }
};

class Vec3 {
public:
  float x;
  float y;
  float z;
  Vec3(float _x = 0, float _y = 0, float _z = 0) {
    x = _x;
    y = _y;
    z = _z;
  }
  Vec3(const Vec3 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
  }
  Vec3(const Vec2 & v, float _z = 0) {
    x = v.x;
    y = v.y;
    z = _z;
  }
  float length() {
    return sqrt(x * x + y * y + z * z);
  }
  float dot(const Vec3 & v) {
    return x * v.x + y * v.y + z * v.z;
  }

  Vec3 operator+(const Vec3 & b) const {
    return Vec3(x+b.x,y+b.y,z+b.z);
  }
  Vec3 operator-(const Vec3 & b) const {
    return Vec3(x-b.x,y-b.y,z-b.z);
  }
  Vec3 operator+(float b) const {
    return Vec3(x+b,y+b,z+b);
  }
  Vec3 operator-(float b) const {
    return Vec3(x-b,y-b,z-b);
  }
  Vec3 operator*(float b) const {
    return Vec3(x*b,y*b,z*b);
  }
  Vec3 operator*(const Vec3 & o) const {
    return Vec3(x * o.x, y * o.y, z * o.z);
  }
  Vec3 operator/(const Vec3 & o) const {
    return Vec3(x / o.x, y / o.y, z / o.z);
  }
  Vec3 norm(){
    return *this * (1/length());
  }
  Vec3 map(float (*fun)(float)) const {
    return Vec3(fun(x), fun(y), fun(z));
  }
};
class Vec4 {
public:
  float x;
  float y;
  float z;
  float w;
  Vec4 mix(float f, const Vec4 & o) {
    Vec4 r;
    r.x = x * (1 - f) + o.x * f;
    r.y = y * (1 - f) + o.y * f;
    r.z = z * (1 - f) + o.z * f;
    r.w = w * (1 - f) + o.w * f;
    return r;
  }
  Vec4(const Vec4 & o) {
    x = o.x;
    y = o.y;
    z = o.z;
    w = o.w;
  }
  Vec4(float _x = 0, float _y = 0, float _z = 0, float _w = 0) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
  }
  Vec4(const Vec3 & o, float _w) {
    x = o.x;
    y = o.y;
    z = o.z;
    w = _w;
  }
  Vec4(const Vec2 & o, float _z = 0, float _w = 0) {
    x = o.x;
    y = o.y;
    z = _z;
    w = _w;
  }
  Vec4(float _x, const Vec2 & o, float _w = 0) {
    x = _x;
    y = o.x;
    z = o.y;
    w = _w;
  }
  Vec4 operator*(float b) const {
    return Vec4(x*b,y*b,z*b, w*b);
  }
  Vec4 operator+(const Vec4 & b) const {
    return Vec4(x+b.x,y+b.y,z+b.z,w+b.w);
  }
  Vec4 operator-(const Vec4 & b) const {
    return Vec4(x-b.x,y-b.y,z-b.z,w-b.w);
  }

};


#endif /* VEC_H_ */
