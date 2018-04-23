#ifndef __PLANET_HXX__
#define __PLANET_HXX__

#include <OgreRoot.h>
#include <OgreVector3.h>

class Planet {
protected:
    Ogre::Vector3 position;
    Ogre::Real mass;
    Ogre::Real radius;
    Ogre::Radian rotation;

public:
    Planet();
    Planet(const Ogre::Vector3 position);
    Planet(const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius);

    void setPosition(const Ogre::Vector3 position);
    void setMass(const Ogre::Real mass);
    void setRadius(const Ogre::Real radius);
    void setRotation(const Ogre::Radian rotation);

    Ogre::Vector3 getPosition();
    Ogre::Real getMass();
    Ogre::Real getRadius();
    Ogre::Radian getRotation();
};

#endif