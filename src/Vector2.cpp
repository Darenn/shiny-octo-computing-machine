#include "Vector2.hpp"
#include <cassert>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

namespace fuzzyTelegram {

template <typename T> Vector2<T>::Vector2(void) : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(const T xValue, const T yValue) : x(xValue), y(yValue) {}

template <typename T> Vector2<T>::Vector2(const T xy) : x(xy), y(xy) {}

template <typename T>
template <typename U>
Vector2<T>::Vector2(const Vector2<U> &vector)
    : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}

template <typename T> Vector2<T>::~Vector2<T>() {}

template <typename T> float Vector2<T>::magnitude() const {
  return sqrt(x * x + y * y);
}

template <typename T> float Vector2<T>::squaredMagnitude() const {
  return x * x + y * y;
}

template <typename T> void Vector2<T>::normalize() {
  float length = this->magnitude();
  x = x / length;
  y = y / length;
  assert(x <= 1 && x >= -1);
  assert(y <= 1 && y >= -1);
}

template <typename T> std::string Vector2<T>::toString() const {
  std::stringstream s;
  s << *this;
  return s.str();
}

template <typename T>
template <typename U, typename V>
void Vector2<T>::set(U xValue, V yValue) {
  x = static_cast<T>(xValue);
  y = static_cast<T>(yValue);
}

template <typename T> Vector2<T> Vector2<T>::normalized() const {
  Vector2<T> v(*this);
  v.normalize();
  return v;
}

template <typename T> Vector2<T> Vector2<T>::up() { return Vector2<T>(0, 1); }

template <typename T> Vector2<T> Vector2<T>::down() {
  return Vector2<T>(0, -1);
}

template <typename T> Vector2<T> Vector2<T>::left() {
  return Vector2<T>(-1, 0);
}

template <typename T> Vector2<T> Vector2<T>::right() {
  return Vector2<T>(1, 0);
}

template <typename T> Vector2<T> Vector2<T>::zero() { return Vector2<T>(0, 0); }

template <typename T> Vector2<T> Vector2<T>::one() { return Vector2<T>(1, 1); }

template <typename T>
float Vector2<T>::dot(const Vector2 &vector1, const Vector2 &vector2) {
  return vector1.x * vector2.x + vector1.y * vector2.y;
}

template <typename T>
float Vector2<T>::angle(const Vector2 &from, const Vector2 &to) {
  return acosf(Vector2<T>::dot(from.normalized(), to.normalized())) * 180 /
         M_PI;
}

template <typename T>
float Vector2<T>::distance(const Vector2 &v, const Vector2 &u) {
  return (v - u).magnitude();
}

template <typename T>
const T Vector2<T>::operator[](const std::size_t i) const {
  if (i == 0)
    return x;
  else if (i == 1)
    return y;
  else
    throw std::out_of_range("Index should be 0 or 1.");
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator=(const Vector2<U> &v) {
  assert(v != NULL);
  x = static_cast<T>(v.x);
  y = static_cast<T>(v.y);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator=(const U &value) {
  x = static_cast<T>(value);
  y = static_cast<T>(value);
  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator-(void) const {
  return Vector2<T>(-x, -y);
}

template <typename T>
template <typename U>
bool Vector2<T>::operator==(const Vector2<U> &v) const {
  return static_cast<T>(v.x) == x && static_cast<T>(v.y) == v.y;
}

template <typename T>
template <typename U>
bool Vector2<T>::operator!=(const Vector2<U> &v) const {
  return static_cast<T>(v.x) != x || static_cast<T>(v.y) != v.y;
}

template <typename T>
const Vector2<T> Vector2<T>::operator+(const Vector2<T> &v) const {
  return Vector2<T>(x + v.x, y + v.y);
}

template <typename T>
const Vector2<T> Vector2<T>::operator-(const Vector2<T> &v) const {
  return Vector2<T>(x - v.x, y - v.y);
}

template <typename T>
const Vector2<T> Vector2<T>::operator*(const Vector2<T> &v) const {
  return Vector2<T>(x * v.x, y * v.y);
}

template <typename T>
const Vector2<T> Vector2<T>::operator/(const Vector2<T> &v) const {
  return Vector2<T>(x / v.x, y / v.y);
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator+=(const Vector2<U> &v) {
  x += v.x;
  y += v.y;
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator-=(const Vector2<U> &v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator*=(const Vector2<U> &v) {
  x *= v.x;
  y *= v.y;
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator/=(const Vector2<U> &v) {
  x /= v.x;
  y /= v.y;
  return *this;
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator+(U value) const {
  return Vector2<T>(x + static_cast<T>(value), y + static_cast<T>(value));
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator-(U value) const {
  return Vector2<T>(x - static_cast<T>(value), y - static_cast<T>(value));
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator*(U value) const {
  return Vector2<T>(x * static_cast<T>(value), y * static_cast<T>(value));
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator/(U value) const {
  assert(value != 0);
  return Vector2<T>(x / static_cast<T>(value), y / static_cast<T>(value));
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator+=(const U value) {
  x += static_cast<T>(value);
  y += static_cast<T>(value);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator-=(const U value) {
  x -= static_cast<T>(value);
  y -= static_cast<T>(value);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator*=(const U value) {
  x *= static_cast<T>(value);
  y *= static_cast<T>(value);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator/=(const U value) {
  x /= static_cast<T>(value);
  y /= static_cast<T>(value);
  return *this;
}

// template class Vector2<int>;
// template class Vector2<float>;
};
