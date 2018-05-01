#include "../view/ship_view.hxx"

ShipController::ShipController(ShipView* shipView) :
    shipView(shipView) {
}

ShipController::~ShipController() {

}

void ShipController::update(const Ogre::Real time) {
    Ogre::Vector3 position = this->shipView->getShip()->getPosition();
    Ogre::Vector3 velocity = this->shipView->getShip()->getVelocity();
    Ogre::Vector3 aceleration = this->shipView->getShip()->getAceleration();

    position += velocity * time;
    velocity += aceleration * time;

    this->shipView->getShip()->setPosition(position);
    this->shipView->getShip()->setVelocity(velocity);
    
    this->shipView->draw();
}

void ShipController::acelerate() {
    Ogre::Vector3 velocity = this->shipView->getShip()->getVelocity();
    velocity[2]++;
    this->shipView->getShip()->setVelocity(velocity);
}

void ShipController::deacelerate() {
    Ogre::Vector3 velocity = this->shipView->getShip()->getVelocity();
    velocity[2]--;
    this->shipView->getShip()->setVelocity(velocity);
}