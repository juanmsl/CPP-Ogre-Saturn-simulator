#include "../view/ship_view.hxx"

#include <iostream>

ShipController::ShipController(ShipView* shipView) :
    shipView(shipView) {
}

ShipController::~ShipController() {

}

void ShipController::update(const Ogre::Real time) {
    Ogre::Vector3 position = this->shipView->getShip()->getPosition();
    Ogre::Real velocity = this->shipView->getShip()->getVelocity();
    Ogre::Vector3 direction = this->shipView->getShip()->getDirection();

    position += direction * velocity * time;

    this->shipView->getShip()->setPosition(position);
    
    this->shipView->draw();
}

void ShipController::acelerate() {
    Ogre::Real velocity = this->shipView->getShip()->getVelocity();

    velocity += 10;

    this->shipView->getShip()->setVelocity(velocity);
}

void ShipController::deacelerate() {
    Ogre::Real velocity = this->shipView->getShip()->getVelocity();

    velocity -= 10;

    this->shipView->getShip()->setVelocity(velocity);
}