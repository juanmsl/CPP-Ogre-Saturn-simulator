#include <model/ship.hxx>

Ship::Ship() :
    position(Ogre::Vector3(-380, 0, 40)),
    velocity(Ogre::Real(0)),
    direction(Ogre::Vector3(1, 0, 0)),
    size(Ogre::Real(1)) {
}

void Ship::setSize(const Ogre::Real size) {
    this->size = size;
}

void Ship::setPosition(const Ogre::Vector3 position) {
    this->position = position;
}

void Ship::setVelocity(const Ogre::Real velocity) {
    this->velocity = velocity;
}

void Ship::setDirection(const Ogre::Vector3 direction) {
    this->direction = direction.normalisedCopy();
}

Ogre::Vector3 Ship::getPosition() {
    return this->position;
}

Ogre::Real Ship::getVelocity() {
    return this->velocity;
}

Ogre::Vector3 Ship::getDirection() {
    return this->direction;
}

Ogre::Real Ship::getSize() {
    return this->size;
}
