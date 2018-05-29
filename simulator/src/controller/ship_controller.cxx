#include <view/ship_view.hxx>

#include <iostream>

ShipController::ShipController(ShipView* shipView, Ship* ship) :
    shipView(shipView),
    ship(ship) {
}

ShipController::~ShipController() {

}

void ShipController::update(const Ogre::Real time) {
    this->ship->update(time);
    
    this->shipView->draw();
}

void ShipController::acelerate() {
    Ogre::Vector3 velocity = this->ship->getVelocity();
    Ogre::Vector3 direction = this->ship->getDirection();

    velocity = direction * (velocity.length() + 500);

    this->ship->setVelocity(velocity);
}

void ShipController::deacelerate() {
    Ogre::Vector3 velocity = this->ship->getVelocity();
    Ogre::Vector3 direction = this->ship->getDirection();

    velocity = direction * (velocity.length() - 500);

    this->ship->setVelocity(velocity);
}