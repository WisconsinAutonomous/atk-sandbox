#pragma once
#include "wacore/WAVector3.hpp"

namespace wautodrive {
namespace wacore {

class WAQuaternion {
  public:
    // constructors
    // constructor for a null quaternion {0,0,0,0}
    WAQuaternion();

    // constructor for 4 scalars, e0 is the real, rest is imaginary
    WAQuaternion(double e0, double e1, double e2, double e3);

    // constructor for a real part, and vector with i,j,k imaginary part
    WAQuaternion(double s, WAVector3& v);

    // Copy constructor
    WAQuaternion(const WAQuaternion& other);

    // access to components
    double& e0() { return m_data[0]; }
    double& e1() { return m_data[1]; }
    double& e2() { return m_data[2]; }
    double& e3() { return m_data[3]; }

    // return const pointer to underlying data storage
    const double* data() const { return m_data; }

  private:
    double m_data[4];
};

// Implementation of methods

inline WAQuaternion::WAQuaternion() {
    m_data[0] = 0;
    m_data[1] = 0;
    m_data[2] = 0;
    m_data[3] = 0;
}

inline WAQuaternion::WAQuaternion(double e0, double e1, double e2, double e3) {
    m_data[0] = e0;
    m_data[1] = e1;
    m_data[2] = e2;
    m_data[3] = e3;
}

inline WAQuaternion::WAQuaternion(double s, WAVector3& v) {
    m_data[0] = s;
    m_data[1] = v.x();
    m_data[2] = v.y();
    m_data[3] = v.z();
}

inline WAQuaternion::WAQuaternion(const WAQuaternion& other) {
    m_data[0] = other.m_data[0];
    m_data[1] = other.m_data[1];
    m_data[2] = other.m_data[2];
    m_data[3] = other.m_data[3];
}

}  // namespace wacore
}  // namespace wautodrive
