#include "planet.hxx"

Planet::Planet() :
    position(Ogre::Vector3(0, 0, 0)),
    mass(Ogre::Real(1)),
    radius(Ogre::Real(1)),
    rotation(Ogre::Radian(0)) {}

Planet::Planet(const Ogre::Vector3 position) :
    position(position),
    mass(Ogre::Real(1)),
    radius(Ogre::Real(1)),
    rotation(Ogre::Radian(0)) {}

Planet::Planet(const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius) :
    position(position),
    mass(mass),
    radius(radius),
    rotation(Ogre::Radian(0)) {}

void Planet::setPosition(const Ogre::Vector3 position) {
    this->position = position;
}

void Planet::setMass(const Ogre::Real mass) {
    this->mass = mass;
}

void Planet::setRadius(const Ogre::Real radius) {
    this->radius = radius;
}

void Planet::setRotation(const Ogre::Radian rotation) {
    this->rotation = rotation;
}

Ogre::Vector3 Planet::getPosition() {
    return this->position;
}

Ogre::Real Planet::getMass() {
    return this->mass;
}

Ogre::Real Planet::getRadius() {
    return this->radius;
}

Ogre::Radian Planet::getRotation() {
    return this->rotation;
}