#ifndef __MATH_UTILITIES__
#define __MATH_UTILITIES__

#include <OgreRoot.h>
#include <OgreVector3.h>

class MathUtilities {
public:
    static Ogre::Real scaleFactor;
    static Ogre::Real lightVelocity;
    static bool isInsideInTriangle(const Ogre::Vector3& p, const Ogre::Vector3& a, const Ogre::Vector3& b, const Ogre::Vector3& c);
};

#endif