#ifndef __SHIP_HXX__
#define __SHIP_HXX__

#include <OgreRoot.h>
#include <OgreVector3.h>

class Ship {
protected:
    Ogre::Vector3 position;
    Ogre::Real velocity;
    Ogre::Vector3 direction;
    Ogre::Real size;

public:
    Ship();

    void setSize(const Ogre::Real size);
    void setPosition(const Ogre::Vector3 position);
    void setVelocity(const Ogre::Real velocity);
    void setDirection(const Ogre::Vector3 direction);

    Ogre::Vector3 getPosition();
    Ogre::Real getVelocity();
    Ogre::Vector3 getDirection();
    Ogre::Real getSize();
};

#endif