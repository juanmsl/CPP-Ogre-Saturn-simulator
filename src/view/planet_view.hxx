#ifndef __PLANET_VIEW__
#define __PLANET_VIEW__

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreVector3.h>
#include <OgreQuaternion.h>
#include "../controller/planet_controller.hxx"

class PlanetView {
protected:
    PlanetController planetController;
    Ogre::SceneManager* sceneManager;
    Ogre::Entity* entity;
    Ogre::SceneNode* node;
    std::string name;

public:
    PlanetView(Ogre::SceneManager* sceneManager, const std::string& name, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius);
    virtual ~PlanetView();

    void create();
    void draw();

    PlanetController* getPlanetController();
};

#endif