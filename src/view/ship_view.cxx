#include "ship_view.hxx"

#include <iostream>

ShipView::ShipView(Ogre::SceneManager* sceneManager, const std::string& name) :
    name(name),
    ship(Ship()),
    shipController(ShipController(this)),
    sceneManager(sceneManager) {

    this->entity = this->sceneManager->createEntity(this->name, "ship.mesh");
    this->entity->setCastShadows(true);
    this->entity->setMaterialName("Mat");

    this->node = this->sceneManager->getRootSceneNode()->createChildSceneNode(this->name + "_node");
    this->node->attachObject(this->entity);
    this->draw();
    this->node->rotate(Ogre::Vector3(0, 0, 1), Ogre::Radian(1.57));
}

ShipView::~ShipView() {}

void ShipView::draw() {
    this->node->setPosition(this->ship.getPosition());
    this->node->setScale(Ogre::Vector3(this->ship.getSize()));
}

ShipController* ShipView::getShipController() {
    return &this->shipController;
}

Ship* ShipView::getShip() {
    return &this->ship;
}