#include <model/ship.hxx>

Ship::Ship() :
    Transform::Transform(Ovec3(-380, 0, 40), Ovec3::ZERO, Ovec3::ZERO, Ovec3(1, 0, 0)),
    size(Ogre::Real(0.5)),
    mass(Ogre::Real(175000) * MathUtilities::scaleFactor) {
}

void Ship::setSize(const Ogre::Real size) {
    this->size = size;
}

Ogre::Real Ship::getSize() {
    return this->size;
}

Ogre::Real Ship::getMass() {
    return this->mass;
}