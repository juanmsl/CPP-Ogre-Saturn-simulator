#include "planet.hxx"

Planet::Planet(const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius, const Ogre::Radian rotation) :
    position(position),
    mass(mass),
    radius(radius),
    rotation(rotation) {}

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