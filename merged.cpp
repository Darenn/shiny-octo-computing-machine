#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#ifndef VECTOR2_H
#define VECTOR2_H


namespace fuzzyTelegram {

template <typename T> class Vector2 {

public:
  T x;
  T y;

  /*!
  * \brief Initialize to a Vector2(0, 0).
  */
  Vector2(void);

  /*!
  * \brief Initiliaze to a Vector2(x, y).
  * \param x The x value of the vector.
  * \param y The y value of the vector;
  */
  Vector2(const T x, const T y);

  /*!
  * \brief Initiliaze to a Vector2(xy, xy).
  * \param xy The value of x and y components.
  */
  Vector2(const T xy);

  /*!
  * \brief Make a copy of the vector given (could be an other type).
  * \param v A reference to the vector to copy.
  */
  template <typename U> explicit Vector2(const Vector2<U> &vector);

  ~Vector2(void);

  /*!
  * \brief Return the length of this vector.
  * \return The length of this vector.
  */
  float magnitude() const;

  /*!
  * \brief Return the square length of this vector.
  * \return The square length of this vector.
  */
  float squaredMagnitude() const;

  /*!
  * \brief Normalize this vector;
  */
  void normalize();

  /*!
  * \brief Return a string representation of a vector : "(x, y)".
  * \return A string representation of a vector : "(x, y)".
  */
  std::string toString() const;

  /*!
  * \brief Return A copy of this vector with a magnitude of 1.
  * \return A copy of this vector with a magnitude of 1.
  */
  Vector2 normalized() const;

  /*!
  * \brief Set the x and y value of this vector.
  * \param xValue The x value of the vector.
  * \param yValue The y value of the vector.
  */
  template <typename U, typename V> void set(U xValue, V yValue);

  /*!
  * \brief Return a Vector2(0, 1).
  * \return A Vector2(0, 1).
  */
  static Vector2 up();

  /*!
  * \brief Return a Vector2(0, -1).
  * \return A Vector2(0, -1).
  */
  static Vector2 down();

  /*!
  * \brief Return a Vector2(-1, 0).
  * \return A Vector2(-1, 0).
  */
  static Vector2 left();

  /*!
  * \brief Return a Vector2(1, 0).
  * \return A Vector2(1, 0).
  */
  static Vector2 right();

  /*!
  * \brief Return a Vector(0, 0).
  * \return A Vector2(0, 0).
  */
  static Vector2 zero();

  /*!
  * \brief Return a Vector2(1, 1).
  * \return A Vector2(1, 1).
  */
  static Vector2 one();

  /*!
  * \brief Return the dot product of two vectors.
  * \param vector1 The first vector.
  * \param vector2 The second vector.
  * \return The dot product of vector1 and vector 2
  */
  static float dot(const Vector2 &vector1, const Vector2 &vector2);

  /*!
  * \brief Return the angle in degrees between two vectors.
  * \param from Where the angle starts.
  * \param to Where the angle ends.
  * \return The angle in degrees between from and to.
  */
  static float angle(const Vector2 &from, const Vector2 &to);

  /*!
  * \brief Return A copy of the vector with its magnitude clamped to
  * maxLength.
  * \param vector The vector we want to clamp.
  * \param maxLength The maximum length magnitude.
  * \return A copy of vector with its magnitude clamped to maxLength.
  */
  static Vector2 clampMagnitude(const Vector2 &vector, float maxLength);

  /*!
  * \brief Return the distance between two vectors.
  * \param v The first vector.
  * \param u The second vector.
  * \return The distance between v and u.
  */
  static float distance(const Vector2 &v, const Vector2 &u);

  /*!
  * \brief Linearly interpolate between vectorA and vectorB by t.
  * \param vectorA The first vector.
  * \param vectorB The second vector.
  * \param t How far interpolation is done. Clamped between 0 and 1. When t =
  * 0,
  * return vectorA,  when t = 1 return vectorB, when t = 0.5 return the
  * midpoint
  * of vectorA and vectorB.
  * \return A vector interpolated.
  */
  static Vector2 lerp(const Vector2 &vectorA, const Vector2 &vectorB, float t);

  /*!
  * \brief Insert into the output stream the vector's representation "(x, y)".
  * \param output The output stream.
  * \param v The vector to insert into output.
  * \return A The output stream.
  */
  friend std::ostream &operator<<(std::ostream &output, const Vector2 &v) {
    output << '(' << v.x << ", " << v.y << ')';
    return output;
  }

  /*!
  * \brief Extract the x and y components from the input stream into v.
  * \param input The input stream.
  * \param v The vector in which we insert x and y components.
  * \return The input stream.
  */
  friend std::istream &operator>>(std::istream &input, Vector2 &v) {
    input >> v.x >> v.y;
    return input;
  }

  /*!
  * \brief Return the x (i == 0) or y (i == 1) components.
  * \param i L'index.
  * \return The x component if i == 0, y if i == 1.
  * \exception std::out_of_range Index i is out of range if i > 1 or i < 0.
  */
  const T operator[](const std::size_t i) const;

  /*!
  * \brief Set x and y of this to x and y of the given vector.
  * \param v The vector this is assigned.
  * \return This vector.
  */
  template <typename U> Vector2 &operator=(const Vector2<U> &v);

  /*!
  * \brief Set x and y of this to the given value.
  * \param f The new value of x and y of this.
  * \return This vector.
  */
  template <typename U> Vector2 &operator=(const U &value);

  /*!
  * \brief Return the inverse of this vector "(-x, -y)".
  * \return The inverse of this vector..
  */
  Vector2 operator-(void) const;

  /*!
  * \brief Check if this vector is equal to another.
  * \return true if x and y components of both vectors are equal.
  */
  template <typename U> bool operator==(const Vector2<U> &v) const;

  /*!
  * \brief Check if this vector is different from another.
  * \return true if x and y components of both vectors are different.
  */
  template <typename U> bool operator!=(const Vector2<U> &v) const;

  /*!
  * \brief Add this vector to another.
  * \return A vector with x and y components of this vector added to x and y
  * components of the other.
  */
  const Vector2 operator+(const Vector2 &v) const;

  /*!
  * \brief Substract this vector to another.
  * \return A vector with x and y components of this vector substracted from x
  * and y components of the other.
  */
  const Vector2 operator-(const Vector2 &v) const;

  /*!
  * \brief Multiply this vector to another.
  * \return A vector with x and y components of this vector multiplied by x
  * and y components of the other.
  */
  const Vector2 operator*(const Vector2 &v) const;

  /*!
  * \brief Divide this vector to another.
  * \return A vector with x and y components of this vector divided by x
  * and y components of the other.
  */
  const Vector2 operator/(const Vector2 &v) const;

  /*!
  * \brief Add x and y components of the other vector to x and y components of
  * this vector.
  * \return This vector.
  */
  template <typename U> Vector2 &operator+=(const Vector2<U> &v);

  /*!
  * \brief Substract x and y components of the other vector from x and y
  * components of this vector.
  * \return This vector.
  */
  template <typename U> Vector2 &operator-=(const Vector2<U> &v);

  /*!
  * \brief Multiply x and y components of the this vector by x and y
  * components of the other vector.
  * \return This vector.
  */
  template <typename U> Vector2 &operator*=(const Vector2<U> &v);

  /*!
  * \brief Divide x and y components of the this vector by x and y
  * components of the other vector.
  * \return This vector.
  */
  template <typename U> Vector2 &operator/=(const Vector2<U> &v);

  /*!
  * \brief Return a copy of this vector with v added to x and y components.
  * \return A copy of this vector with v added to x and y components.
  */
  template <typename U> const Vector2 operator+(U value) const;

  /*!
  * \brief Return a copy of this vector with v substracted from x and y
  * components.
  * \return A copy of this vector with v substracted from x and y components.
  */
  template <typename U> const Vector2 operator-(U value) const;

  /*!
  * \brief Return a copy of this vector with x and y components multiplied by
  * v.
  * \return A copy of this vector with x and y components multiplied by v.
  */
  template <typename U> const Vector2 operator*(U v) const;

  /*!
  * \brief Return a copy of this vector with x and y components divided by v.
  * \return A copy of this vector with x and y components divided by v.
  */
  template <typename U> const Vector2 operator/(U v) const;

  /*!
  * \brief Add the given value to x and y components of this vector.
  * \return This vector.
  */
  template <typename U> Vector2 &operator+=(U v);

  /*!
  * \brief Substract the given value from x and y components of this vector.
  * \return This vector.
  */
  template <typename U> Vector2 &operator-=(U v);

  /*!
  * \brief Multiply x and y components of this vector by the given value.
  * \return This vector.
  */
  template <typename U> Vector2 &operator*=(U v);

  /*!
  * \brief Divide x and y components of this vector by the given value.
  * \return This vector.
  */
  template <typename U> Vector2 &operator/=(U v);
};

typedef Vector2<char> Vector2c;
typedef Vector2<short int> Vector2si;
typedef Vector2<int> Vector2i;
typedef Vector2<long int> Vector2li;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<long double> Vector2ld;
typedef Vector2<unsigned char> Vector2uc;
typedef Vector2<unsigned short int> Vector2usi;
typedef Vector2<unsigned int> Vector2ui;
typedef Vector2<unsigned long int> Vector2uli;
}

#endif

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

using namespace std;

/**
 * Shoot enemies before they collect all the incriminating data!
 * The closer you are to an enemy, the more damage you do but don't get too
 *close or you'll get killed.
 **/
int main() {

  // game loop
  while (1) {
    int x;
    int y;
    cin >> x >> y;
    cin.ignore();
    int dataCount;
    cin >> dataCount;
    cin.ignore();
    for (int i = 0; i < dataCount; i++) {
      int dataId;
      int dataX;
      int dataY;
      cin >> dataId >> dataX >> dataY;
      cin.ignore();
    }
    int enemyCount;
    cin >> enemyCount;
    cin.ignore();
    for (int i = 0; i < enemyCount; i++) {
      int enemyId;
      int enemyX;
      int enemyY;
      int enemyLife;
      cin >> enemyId >> enemyX >> enemyY >> enemyLife;
      cin.ignore();
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "MOVE 0 0" << endl; // MOVE x y or SHOOT id
  }
}
