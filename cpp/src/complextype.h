/*************  ✨ Custom complex data type 🌟  *************/
/**
 * \file complextype.h
 * \brief Definition and implementation of the complex_t data type, a custom data type for representing complex numbers.
 */


#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

#define USE_MATH_DEFINES

#include <math.h>
#include <cmath>
#include <stdint.h>

namespace complexDSP
{

/**
 * \brief Complex number data type
 * 
 * This struct represents a complex number, with real and imaginary components.
 */
typedef struct complex_type
{
    /**
     * \brief Real component of the complex number
     */
    double re = 0.0;

    /**
     * \brief Imaginary component of the complex number
     */
    double im = 0.0;

    /**
     * \brief Default constructor for complex_t
     * 
     * Initializes the complex number to zero.
     */
    complex_type() = default;

    // constructor
    /**
     * \brief Constructor for complex_t
     * 
     * Initializes the complex number with the given real and imaginary components.
     * 
     * @param r The real component of the complex number
     * @param i The imaginary component of the complex number
     * 
     */
    complex_type(double r, double i) : re{r}, im{i} {}

    /**
     * \brief Assign to the real component of the complex number
     * 
     * @param r The value to assign to the real component
     * 
     * @returns void
     */
    void real(const double& r) { re = r; };

    /**
     * \brief Assign to the imaginary component of the complex number
     * 
     * @param i The value to assign to the imaginary component
     * 
     * @returns void
     */
    void imag(const double& i) { im = i; };

    /**
     * \brief Access the real component of the complex number
     * 
     * @returns The real component of the complex number
     */
    double real() const { return re; };

    /**
     * \brief Access the imaginary component of the complex number
     * 
     * @returns The imaginary component of the complex number
     */
    double imag() const { return im; };

    /**
     * \brief Compute the squared magnitude of the complex number
     * 
     * @returns The squared magnitude of the complex number
     */
    inline double sqmag() const { return re * re + im * im; };
    
    /**
     * \brief Compute the magnitude of the complex number
     * 
     * @returns The magnitude of the complex number
     */
    inline double abs() const { return std::sqrt(sqmag()); };

    /**
     * \brief Compute the angle of the complex number
     * 
     * @returns The angle of the complex number in radians
     */
    inline double angle() const { return std::atan2(im, re); };

    /**
     * \brief Compute the magnitude of a complex number in decibels
     * 
     * @param c The complex number
     * 
     * @return The magnitude of the complex number in decibels
     */
    inline double dB() const {return 10.0 * std::log10(sqmag());};

} complex_t;

/**
 * \brief Add two complex numbers
 * 
 * This operator overloads the addition operator for complex_t types,
 * returning the result of adding complex number `a` to complex number `b`.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return The sum of the two complex numbers as a complex_t type
 */

complex_t operator+
(
    const complex_t& a,
    const complex_t& b
)
{
    return {a.re + b.re, a.im + b.im};
}

/**
 * \brief Add two complex numbers and store the result in the first complex number
 * 
 * This operator overloads the addition-assignment operator for complex_t types,
 * adding complex number `b` to complex number `a` in-place.
 * 
 * @param a The first complex number, modified in-place
 * @param b The second complex number
 * 
 * @return A reference to the modified complex number `a`
 */
complex_t& operator+=
(
    complex_t& a,
    const complex_t& b
)
{
    a.re += b.re;
    a.im += b.im;
    return a;
}

/**
 * \brief Subtract two complex numbers
 * 
 * This operator overloads the subtraction operator for complex_t types,
 * returning the result of subtracting complex number `b` from complex number `a`.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return The difference of the two complex numbers as a complex_t type
 */
complex_t operator-
(
    const complex_t& a,
    const complex_t& b
)
{
    return {a.re - b.re, a.im - b.im};
}

/**
 * \brief Subtract two complex numbers in-place
 * 
 * This operator overloads the subtraction-assignment operator for complex_t types,
 * subtracting complex number `b` from complex number `a` in-place.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return A reference to the modified complex number `a`
 */
complex_t& operator-= 
(
    complex_t& a,
    const complex_t& b
)
{
    a.re -= b.re;
    a.im -= b.im;
    return a;
}

/**
 * \brief Multiply two complex numbers
 * 
 * This operator overloads the multiplication operator for complex_t types,
 * returning the result of multiplying complex number `a` by complex number `b`.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return The product of the two complex numbers as a complex_t type
 */

complex_t operator*
(
    const complex_t& a,
    const complex_t& b
)
{
    return {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
}

/**
 * \brief Multiply two complex numbers in-place
 * 
 * This operator overloads the multiplication-assignment operator for complex_t types,
 * multiplying complex number `a` by complex number `b` in-place.
 * 
 * @param a The first complex number, modified in-place
 * @param b The second complex number
 * 
 * @return A reference to the modified complex number `a`
 */
complex_t& operator*=
(
    complex_t& a,
    const complex_t& b
)
{
    a.re *= b.re - a.im * b.im;
    a.im *= a.re * b.im + a.im * b.re;
    return a;
}

/**
 * \brief Divide two complex numbers
 * 
 * This operator overloads the division operator for complex_t types,
 * returning the result of dividing complex number `a` by complex number `b`.
 * 
 * @param a The dividend complex number
 * @param b The divisor complex number
 * 
 * @return The result of the division as a complex_t type
 * 
 * \note The division is performed by multiplying `a` by the conjugate of `b` 
 *       and dividing by the magnitude of `b` squared.
 */
complex_t operator/
(
    const complex_t& a,
    const complex_t& b
)
{
    double denom = b.re * b.re + b.im * b.im;
    return {(a.re * b.re + a.im * b.im) / denom, (a.im * b.re - a.re * b.im) / denom};
}

complex_t& operator/=
(
    complex_t& a,
    const complex_t& b
)
{
    double denom = b.re * b.re + b.im * b.im;
    a.re = (a.re * b.re + a.im * b.im) / denom;
    a.im = (a.im * b.re - a.re * b.im) / denom;
    return a;
}

/**
 * \brief Compare two complex numbers for equality
 * 
 * This operator overloads the equality operator for complex_t types,
 * returning true if the real and imaginary components of both complex numbers are equal.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return True if the complex numbers are equal, false otherwise
 */
const bool operator==
(
    const complex_t& a,
    const complex_t& b
) 
{
    return a.re == b.re && a.im == b.im;
}

/**
 * \brief Compare two complex numbers for inequality
 * 
 * This operator overloads the inequality operator for complex_t types,
 * returning true if either the real or imaginary components of the complex numbers differ.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return True if the complex numbers are not equal, false otherwise
 */
const bool operator!=
(
    const complex_t& a,
    const complex_t& b
) 
{
    return a.re != b.re || a.im != b.im;
}

/**
 * \brief Compare two complex numbers based on their magnitude
 * 
 * This operator overloads the less-than operator for complex_t types,
 * returning true if the magnitude of the first complex number is less than
 * the magnitude of the second complex number.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return True if the magnitude of the first complex number is less than
 * the magnitude of the second complex number, false otherwise
 */
const bool operator<
(
    const complex_t& a,
    const complex_t& b
)
{
    return a.abs() < b.abs();
}

/**
 * \brief Compare two complex numbers by magnitude
 * 
 * This operator overloads the greater than operator for complex_t types,
 * returning true if the magnitude of the first complex number is greater than
 * the magnitude of the second complex number.
 * 
 * @param a The first complex number
 * @param b The second complex number
 * 
 * @return True if the magnitude of the first complex number is greater than
 *         the magnitude of the second complex number, false otherwise
 */
const bool operator>
(
    const complex_t& a,
    const complex_t& b
)
{
    return a.abs() > b.abs();
}

} // namespace complexDSP

#endif