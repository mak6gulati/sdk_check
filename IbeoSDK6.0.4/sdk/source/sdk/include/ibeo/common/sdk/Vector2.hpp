//==============================================================================
//!\file
//!
//!$$IBEO_LICENSE_BEGIN$$
//!Copyright (c) Ibeo Automotive Systems GmbH 2010-2019
//!All Rights Reserved.
//!
//!For more details, please refer to the accompanying file
//!IbeoLicense.txt.
//!$$IBEO_LICENSE_END$$
//!
//!\date Jan 11, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/Math.hpp>
#include <ibeo/common/sdk/io_prototypes.hpp>

#include <iostream>
#include <limits>

//==============================================================================

namespace ibeo {
namespace common {
namespace sdk {

//==============================================================================

//! \class Vector2
//! \brief Vector class for which can store 2 elements (x and y).
//! Dedicated to be used for 2d calculations
// ------------------------------------------------------------------------------
template<typename T>
class Vector2
{
public: // type definitions
    //========================================
    using value_type = T;

public: // constructors
    //========================================
    //! \brief Default constructor, initializes x and y to 0
    //----------------------------------------
    Vector2() : m_x{0}, m_y{0} {}

    //========================================
    //! \brief Constructor with member initialization
    //! \param[in]      x      initialization value for member x
    //! \param[in]      y      initialization value for member y
    //----------------------------------------
    Vector2(const value_type x, const value_type y) : m_x{x}, m_y{y} {}

    //========================================
    //! \brief Default Destructor
    //----------------------------------------
    virtual ~Vector2() {}

public: // operators
    //========================================
    //! \brief Operator for adding another two vectors
    //! \param[in]      other  The vector which shall be added to this one
    //! \return A new vector holding the sum of both vectors
    //! \sa operator+=
    //----------------------------------------
    Vector2<value_type> operator+(const Vector2<value_type>& other) const
    {
        return Vector2<value_type>(m_x + other.m_x, m_y + other.m_y);
    }

    //========================================
    //! \brief Operator for adding another Vector2 to this one
    //! \param[in]      other  The vector which shall be added to this one
    //! \return The sum of both vectors
    //----------------------------------------
    Vector2<value_type>& operator+=(const Vector2<value_type>& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }

    //========================================
    //! \brief Operator for subtracting two vectors
    //! \param[in]      other  The vector which shall be subtracted from this one
    //! \return A new vector holding the difference of both vectors
    //! \sa operator-=
    //----------------------------------------
    Vector2<value_type> operator-(const Vector2<value_type>& other) const
    {
        return Vector2<value_type>(m_x - other.m_x, m_y - other.m_y);
    }

    //========================================
    //! \brief Operator for multipling the Vector with a factor (scales the vector)
    //! \param[in]      other  The factor which shall be multiplied to the vector
    //! \return The scaled vector
    //! \sa scale
    //----------------------------------------
    Vector2<value_type>& operator-=(const Vector2<value_type>& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return *this;
    }

    //========================================
    //! \brief Operator for multipling the Vector with a factor (scales the vector)
    //! \param[in]      factor  The factor which shall be multiplied to the vector
    //! \return A new vector which is scaled about the factor
    //----------------------------------------
    Vector2<value_type> operator*(const value_type factor) const
    {
        return Vector2<value_type>{m_x * factor, m_y * factor};
    }

    //========================================
    //! \brief Operator for multipling the Vector with a factor (scales the vector)
    //! \param[in]      factor  The factor which shall be multiplied to the vector
    //! \return The scaled vector
    //----------------------------------------
    Vector2<value_type>& operator*=(const value_type factor)
    {
        m_x *= factor;
        m_y *= factor;
        return *this;
    }

    //========================================
    //! \brief Operator for dividing the vector by a divisor (scales the vector)
    //! \param[in]      divisor  The divisor which shall be used for scaling the vector
    //! \return A new vector holding a scaled vector
    //! \sa operator/=
    //! \sa getScaled
    //----------------------------------------
    Vector2<value_type> operator/(const value_type divisor) const
    {
        return Vector2<value_type>{m_x / divisor, m_y / divisor};
    }

    //========================================
    //! \brief Operator for dividing the Vector by a divisor (scales the vector)
    //! \param[in]      divisor  The divisor which shall be used for scaling the vector
    //! \return The scaled vector
    //! \sa scale
    //----------------------------------------
    Vector2<value_type>& operator/=(const value_type divisor)
    {
        m_x /= divisor;
        m_y /= divisor;
        return *this;
    }

    //========================================
    //! \brief Operator for getting the dot product of two vectors
    //! \param[in]      other  The vector which shall be multiplied to the first one
    //! \return A scalar value holding the result of the dot product
    //----------------------------------------
    value_type operator*(const Vector2<value_type>& other) const { return m_x * other.m_x + m_y * other.m_y; }

    //========================================
    //! \brief Operator for calculating the cross product of two vectors
    //! \param[in]      other  The vector which shall used for the cross product
    //! calculation
    //! \return The cross product of the two vectors
    //----------------------------------------
    value_type operator^(const Vector2<value_type>& other) const { return m_x * other.m_y - m_y * other.m_x; }

public: // member functions
    //========================================
    //! \brief Getter function for the x value
    //! \return The x component of the vector
    //----------------------------------------
    value_type getX() const { return m_x; }

    //========================================
    //! \brief Getter function for the y value
    //! \return The y component of the vector
    //----------------------------------------
    value_type getY() const { return m_y; }

    //========================================
    //! \brief Setter function for the x value
    //! \param[in]      val  The value which will replace the current x value
    //----------------------------------------
    void setX(const value_type val) { m_x = val; }

    //========================================
    //! \brief Setter function for the y value
    //! \param[in]      val  The value which will replace the current y value
    //----------------------------------------
    void setY(const value_type val) { m_y = val; }

    //========================================
    //! \brief Calculates the length of the vector
    //! \return The length of the vector
    //----------------------------------------
    value_type getLength() const { return std::sqrt(m_x * m_x + m_y * m_y); }

    //========================================
    //! \brief Calculates the squared length of the vector
    //! \return The squared length of the vector
    //----------------------------------------
    value_type getSquaredLength() const { return m_x * m_x + m_y * m_y; }

    //========================================
    //! \brief Calculates the angle between a vector facing in x direction and
    //! this one
    //! \return The angle of the vector
    //----------------------------------------
    value_type getAngle() const { return std::atan2(m_y, m_x); }

    //========================================
    //! \brief Normalizes the vector to have a length of 1
    //----------------------------------------
    void normalize() { *this = getNormalized(); }

    //========================================
    //! \brief Calculates a normalized vector from this on
    //! \return A new normalized vector
    //! \sa normalize
    //----------------------------------------
    Vector2<value_type> getNormalized() const
    {
        if (isZero())
        {
            return *this;
        }

        return *this / getLength();
    }

    //========================================
    //! \brief Scales this vector by a factor
    //! \param[in]      factor  The factor which will be used for scaling
    //! \sa operator*=
    //----------------------------------------
    void scale(const value_type factor) { this->operator*=(factor); }

    //========================================
    //! \brief Calculates a scaled version of this vector
    //! \param[in]      factor  The factor which will be used for scaling
    //! \return A new vector holding a scaled version of this one
    //! \sa scale
    //----------------------------------------
    Vector2<value_type> getScaled(const value_type factor) { return *this * factor; }

    //========================================
    //! \brief Checks this vector to have 0 length
    //! \return \c true if the vector length is less than epsilon, \c false otherwise
    //! (depends on the template type)
    //----------------------------------------
    bool isZero() const
    {
        T distance{getLength()};
        if (distance < std::numeric_limits<T>::epsilon() && distance > -std::numeric_limits<T>::epsilon())
        {
            return true;
        }

        return false;
    }

    //========================================
    //! \brief Rotates this point around the orign (0,0)
    //! \param[in]      angle  The angle about the vector will be rotated
    //----------------------------------------
    void rotate(const value_type angle) { *this = getRotated(angle); }

    //========================================
    //! \brief Calculates a rotated version of this vector
    //! \param[in]      angle  The angle about the vector will be rotated
    //! \return A new vector which is rotated about the given angle
    //----------------------------------------
    Vector2<value_type> getRotated(const value_type angle) const
    {
        const T dCos{std::cos(angle)};
        const T dSin{std::sin(angle)};

        return Vector2<T>{m_x * dCos - m_y * dSin, m_x * dSin + m_y * dCos};
    }

protected: // member variables
    value_type m_x;
    value_type m_y;

public: // friend functions for serialization
    template<typename TT>
    friend void readBE(std::istream& is, Vector2<TT>& value);
    template<typename TT>
    friend void readLE(std::istream& is, Vector2<TT>& value);
    template<typename TT>
    friend void writeBE(std::ostream& os, const Vector2<TT>& value);
    template<typename TT>
    friend void writeLE(std::ostream& os, const Vector2<TT>& value);

public:
    static constexpr bool isSerializable()
    {
        return (std::is_same<value_type, float>{} || std::is_same<value_type, int16_t>{}
                || std::is_same<value_type, uint16_t>{});
    }
}; // Vector2

//==============================================================================
//==============================================================================
//==============================================================================

//==============================================================================
//! \brief Operator for comparing two vectors for equality
//! \param[in]      other  The vector which shall be compared to the first one
//! \return \c true, if x and y of both vectors are equal, \c false otherwise
//------------------------------------------------------------------------------
template<typename T>
bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

//==============================================================================
//! \brief Operator for comparing two vectors for inequality
//! \param[in]      other  The vector which shall be compared to the first one
//! \return \c false, if x and y of both vectors are equal, \c true otherwise
//------------------------------------------------------------------------------
template<typename T>
bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return !(lhs == rhs);
}

//==============================================================================
//! \brief Operator for comparing two vectors for equality (special implementation for float)
//! \param[in]      other  The vector which shall be compared to the first one
//! \return \c true, if x and y of both vectors are equal, \c false otherwise
//------------------------------------------------------------------------------
inline bool operator==(const Vector2<float>& lhs, const Vector2<float>& rhs)
{
    return floatEqual(lhs.getX(), rhs.getX()) && floatEqual(lhs.getY(), rhs.getY());
}

//==============================================================================
//! \brief Operator for comparing two vectors for equality (special implementation for double)
//! \param[in]      other  The vector which shall be compared to the first one
//! \return \c true, if x and y of both vectors are equal, \c false otherwise
//------------------------------------------------------------------------------
inline bool operator==(const Vector2<double>& lhs, const Vector2<double>& rhs)
{
    return doubleEqual(lhs.getX(), rhs.getX()) && doubleEqual(lhs.getY(), rhs.getY());
}

//==============================================================================
//! \brief Tests whether two \c float vector values are nearly equal.
//! \tparam EXP   The exponent of the epsilon used for the fuzzy
//!               compare. 10^(-EXP).
//! \param[in] a  First value to be compared with second value.
//! \param[in] b  Second value to be compared with first value.
//! \return \c true if the two \c float numbers are equal in
//!         terms of the machine precision, which means their
//!         difference must be less than 10^(-EXP).
//!
//! The exponent range is defined in NegFloatPotenciesOf10.
//------------------------------------------------------------------------------
template<typename T, uint8_t EXP>
inline bool fuzzyCompareT(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return fuzzyCompareT<EXP>(lhs.getX(), rhs.getX()) && fuzzyCompareT<EXP>(lhs.getY(), rhs.getY());
}

//==============================================================================
//! \brief Fuzzy Compare two float vectors \a a and \a b. NaN is equal NaN here.
//! \tparam EXP   The exponent of the epsilon used for the fuzzy
//!               compare. 10^(-EXP).
//! \param[in] a  First vector to be compared.
//! \param[in] b  Second vector to be compared.
//! \return \c true if the difference between \a a and \a b is not smaller
//!         than 10^(-EXP) or if both are NaN.
//!         \c false otherwise.
//------------------------------------------------------------------------------
template<uint8_t EXP>
inline bool fuzzyEqualT(const Vector2<float>& lhs, const Vector2<float>& rhs)
{
    return fuzzyFloatEqualT<EXP>(lhs.getX(), rhs.getX()) && fuzzyFloatEqualT<EXP>(lhs.getY(), rhs.getY());
}

//==============================================================================
//! \brief Fuzzy Compare two double vectors \a a and \a b. NaN is equal NaN here.
//! \tparam EXP   The exponent of the epsilon used for the fuzzy
//!               compare. 10^(-EXP).
//! \param[in] a  First vector to be compared.
//! \param[in] b  Second vector to be compared.
//! \return \c true if the difference between \a a and \a b is not smaller
//!         than 10^(-EXP) or if both are NaN.
//!         \c false otherwise.
//------------------------------------------------------------------------------
template<uint8_t EXP>
inline bool fuzzyEqualT(const Vector2<double>& lhs, const Vector2<double>& rhs)
{
    return fuzzyDoubleEqualT<EXP>(lhs.getX(), rhs.getX()) && fuzzyDoubleEqualT<EXP>(lhs.getY(), rhs.getY());
}

//==============================================================================
//! \brief Stream operator for writing the vector content to a stream
//! \param[in]      os  The stream, the vector shall be written to
//! \param[in]      p   The vector which shall be streamed
//! \return The stream to which the vector was written to
//------------------------------------------------------------------------------
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& p)
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

//==============================================================================
// Serialization
//==============================================================================

//==============================================================================
// Specializations
//==============================================================================
template<typename T>
inline void writeBE(std::ostream& os, const Vector2<T>& p)
{
    static_assert(Vector2<T>::isSerializable(), "writeBE is not implemented for given template type of Vector2");

    ibeo::common::sdk::writeBE(os, p.m_x);
    ibeo::common::sdk::writeBE(os, p.m_y);
}

//==============================================================================
template<typename T>
inline void readBE(std::istream& is, Vector2<T>& p)
{
    static_assert(Vector2<T>::isSerializable(), "readBE is not implemented for given template type of Vector2");

    ibeo::common::sdk::readBE(is, p.m_x);
    ibeo::common::sdk::readBE(is, p.m_y);
}

//==============================================================================
template<typename T>
inline void writeLE(std::ostream& os, const Vector2<T>& p)
{
    static_assert(Vector2<T>::isSerializable(), "writeLE is not implemented for given template type of Vector2");

    ibeo::common::sdk::writeLE(os, p.m_x);
    ibeo::common::sdk::writeLE(os, p.m_y);
}

//==============================================================================
template<typename T>
inline void readLE(std::istream& is, Vector2<T>& p)
{
    static_assert(Vector2<T>::isSerializable(), "readLE is not implemented for given template type of Vector2");

    ibeo::common::sdk::readLE(is, p.m_x);
    ibeo::common::sdk::readLE(is, p.m_y);
}

//==============================================================================
template<typename T>
inline constexpr std::streamsize serializedSize(const Vector2<T>&)
{
    static_assert(Vector2<T>::isSerializable(), "serializedSize is not implemented for given template type of Vector2");
    return 2 * sizeof(T);
}

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
