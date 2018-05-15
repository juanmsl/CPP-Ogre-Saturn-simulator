#ifndef __CAMERA_MANAGER_HXX__
#define __CAMERA_MANAGER_HXX__

#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreVector3.h>

#include <model/ship.hxx>

class CameraManager {
protected:
    Ogre::Camera* camera;
    Ogre::Vector3 position;
    Ogre::Vector3 direction;

public:
    CameraManager(Ogre::Camera* camera);

    void update(Ship* ship);

};

#endif