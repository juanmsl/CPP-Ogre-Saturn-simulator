#include <view/ship_view.hxx>

#include <iostream>

ShipView::ShipView(Ogre::SceneManager* sceneManager, CameraManager* cameraManager, const std::string& name) :
    name(name),
    ship(Ship()),
    cameraManager(cameraManager),
    shipController(ShipController(this, &this->ship)),
    sceneManager(sceneManager) {

    this->entity = this->sceneManager->createEntity(this->name, "ship.mesh");
    this->entity->setCastShadows(true);
    this->entity->setMaterialName("Mat");

    this->node = this->sceneManager->getRootSceneNode()->createChildSceneNode(this->name + "_node");
    this->node->attachObject(this->entity);
    this->node->setDirection(this->ship.getDirection());
    this->draw();
}

ShipView::~ShipView() {}

void ShipView::draw() {
    this->node->setPosition(this->ship.getPosition());
    this->node->setScale(Ogre::Vector3(this->ship.getSize()));
    this->cameraManager->update(&this->ship);
}

void ShipView::move(const Ogre::Real x, const Ogre::Real y) {
    this->node->yaw(Ogre::Degree(x * -0.05), Ogre::Node::TS_WORLD);
    this->node->pitch(Ogre::Degree(y * -0.05), Ogre::Node::TS_LOCAL);
    this->ship.setDirection(this->node->getOrientation() * Ogre::Vector3::NEGATIVE_UNIT_Z);
}

ShipController* ShipView::getShipController() {
    return &this->shipController;
}

Ship* ShipView::getShip() {
    return &this->ship;
}