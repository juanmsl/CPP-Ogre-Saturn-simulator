#ifndef __CAMERA_MANAGER_HXX__
#define __CAMERA_MANAGER_HXX__

#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include <model/ship.hxx>

class CameraManager {
public:
    Ogre::Camera* camera;

public:
    CameraManager(Ogre::Camera* camera);

    void update(Ship* ship);

};

#endif