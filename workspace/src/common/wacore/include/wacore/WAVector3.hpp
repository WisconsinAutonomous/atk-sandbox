#pragma once
#include <cassert>

namespace wautodrive {
namespace wacore {

class WAVector3 {
  public:
    // Constructors
    WAVector3();
    WAVector3(double x, double y, double z);
    WAVector3(const WAVector3& other);

    // Access components
    double& x() { return m_data[0]; }
    double& y() { return m_data[1]; }
    double& z() { return m_data[2]; }

    // Return const pointer to underlying array storage
    const double* data() const { return m_data; }

    // Subscript operator
    double& operator[](unsigned index);

    // Arithmetic operations
    WAVector3 operator+(const WAVector3& other) const;
    WAVector3 operator-(const WAVector3& other) const;

  private:
    double m_data[3];
};

extern const WAVector3 VNULL(0., 0., 0.);
extern const WAVector3 VECT_X(1., 0., 0.);
extern const WAVector3 VECT_Y(0., 1., 0.);
extern const WAVector3 VECT_Z(0., 0., 1.);

// ====================================================
// IMPLEMENTATION OF WAVector3 methods
// ====================================================

// Constructors

inline WAVector3::WAVector3() {
    m_data[0] = 0;
    m_data[1] = 0;
    m_data[2] = 0;
}

inline WAVector3::WAVector3(double x, double y, double z) {
    m_data[0] = x;
    m_data[1] = y;
    m_data[2] = z;
}

inline WAVector3::WAVector3(const WAVector3& other) {
    m_data[0] = other.m_data[0];
    m_data[1] = other.m_data[1];
    m_data[2] = other.m_data[2];
}

// Subscript operators

inline double& WAVector3::operator[](unsigned index) {
    assert(index < 3);
    return m_data[index];
}

// Arithmetic operations

inline WAVector3 WAVector3::operator+(const WAVector3& other) const {
    WAVector3 v;
    v.m_data[0] = m_data[0] + other.m_data[0];
    v.m_data[1] = m_data[1] + other.m_data[1];
    v.m_data[2] = m_data[2] + other.m_data[2];
    return v;
}

inline WAVector3 WAVector3::operator-(const WAVector3& other) const {
    WAVector3 v;
    v.m_data[0] = m_data[0] - other.m_data[0];
    v.m_data[1] = m_data[1] - other.m_data[1];
    v.m_data[2] = m_data[2] - other.m_data[2];
    return v;
}

}  // namespace wacore
}  // namespace wautodrive
