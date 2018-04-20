#include "math_utilities.hxx"

bool MathUtilities::isInsideInTriangle(const Ogre::Vector3& p, const Ogre::Vector3& a, const Ogre::Vector3& b, const Ogre::Vector3& c) {
    Ogre::Vector3 v0 = b - a;
    Ogre::Vector3 v1 = c - a;
    Ogre::Vector3 v2 = p - a;
    Ogre::Vector3 bary;

    Ogre::Real d00 = v0.dotProduct(v0);
    Ogre::Real d01 = v0.dotProduct(v1);
    Ogre::Real d11 = v1.dotProduct(v1);
    Ogre::Real d20 = v2.dotProduct(v0);
    Ogre::Real d21 = v2.dotProduct(v1);
    Ogre::Real denom = d00 * d11 - d01 * d01;

    bary[1] = (d11 * d20 - d01 * d21) / denom;
    bary[2] = (d00 * d21 - d01 * d20) / denom;
    bary[0] = Ogre::Real(1.0) - bary[1] - bary[2];

    bool inside = true;
    for(int i = 0; i < 3; i++) {
        inside &=  Ogre::Real(0.0) <= bary[i] && bary [i] <= Ogre::Real(1.0);
    }

    return inside;
}