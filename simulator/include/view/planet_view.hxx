#ifndef __PLANET_VIEW__
#define __PLANET_VIEW__

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreVector3.h>

#include <controller/planet_controller.hxx>
#include <model/planet.hxx>
#include <common/math_utilities.hxx>

class PlanetView {
protected:
    PlanetController planetController;
    Ogre::SceneManager* sceneManager;
    Ogre::Entity* entity;
    Ogre::SceneNode* node;
    std::string name;
    std::string mesh;
    std::string material;
    Planet planet;

public:
    PlanetView(Ogre::SceneManager* sceneManager, const std::string& name, const std::string& mesh, const std::string& material, Ship* ship, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius, const Ogre::Radian rotation);
    virtual ~PlanetView();

    void draw();

    PlanetController* getPlanetController();
    Planet* getPlanet();
};

#endif