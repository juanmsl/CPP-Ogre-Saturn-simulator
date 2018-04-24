#include "ship.hxx"

Ship::Ship() :
    position(Ogre::Vector3(-380, 0, 40)),
    velocity(Ogre::Vector3(0, 0, 0)),
    aceleration(Ogre::Vector3(0, 0, 0)),
    size(Ogre::Real(2)) {
}

Ship::Ship(const Ogre::Vector3 position, const Ogre::Vector3 velocity, const Ogre::Vector3 aceleration, const Ogre::Real size) :
    position(position),
    velocity(velocity),
    aceleration(aceleration),
    size(size) {}

void Ship::setSize(const Ogre::Real size) {
    this->size = size;
}

void Ship::setPosition(const Ogre::Vector3 position) {
    this->position = position;
}

void Ship::setVelocity(const Ogre::Vector3 velocity) {
    this->velocity = velocity;
}

void Ship::setAceleration(const Ogre::Vector3 aceleration) {
    this->aceleration = aceleration;
}

Ogre::Vector3 Ship::getPosition() {
    return this->position;
}

Ogre::Vector3 Ship::getVelocity() {
    return this->velocity;
}

Ogre::Vector3 Ship::getAceleration() {
    return this->aceleration;
}

Ogre::Real Ship::getSize() {
    return this->size;
}
