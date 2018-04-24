#ifndef __SHIP_VIEW_HXX__
#define __SHIP_VIEW_HXX__

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreVector3.h>
#include "../controller/ship_controller.hxx"
#include "../model/ship.hxx"

class ShipView {
protected:
    ShipController shipController;
    Ogre::SceneManager* sceneManager;
    Ogre::Entity* entity;
    Ogre::SceneNode* node;
    std::string name;
    Ship ship;

public:
    ShipView(Ogre::SceneManager* sceneManager, const std::string& name);
    virtual ~ShipView();

    void draw();

    ShipController* getShipController();
    Ship* getShip();
};

#endif