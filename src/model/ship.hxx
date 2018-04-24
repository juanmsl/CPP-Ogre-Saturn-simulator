#ifndef __SHIP_HXX__
#define __SHIP_HXX__

#include <OgreRoot.h>
#include <OgreVector3.h>

class Ship {
protected:
    Ogre::Vector3 position;
    Ogre::Vector3 velocity;
    Ogre::Vector3 aceleration;
    Ogre::Real size;

public:
    Ship();
    Ship(const Ogre::Vector3 position, const Ogre::Vector3 velocity, const Ogre::Vector3 aceleration, const Ogre::Real size);

    void setSize(const Ogre::Real size);
    void setPosition(const Ogre::Vector3 position);
    void setVelocity(const Ogre::Vector3 velocity);
    void setAceleration(const Ogre::Vector3 aceleration);

    Ogre::Vector3 getPosition();
    Ogre::Vector3 getVelocity();
    Ogre::Vector3 getAceleration();
    Ogre::Real getSize();
};

#endif