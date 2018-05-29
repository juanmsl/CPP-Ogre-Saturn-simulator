#ifndef __SHIP_HXX__
#define __SHIP_HXX__

#include <OgreRoot.h>
#include <OgreVector3.h>

#include <common/transform.hxx>

class Ship : public Transform {
protected:
    Ogre::Real size;
    Ogre::Real mass;

public:
    Ship();

    void setSize(const Ogre::Real size);
    Ogre::Real getSize();
    Ogre::Real getMass();
};

#endif