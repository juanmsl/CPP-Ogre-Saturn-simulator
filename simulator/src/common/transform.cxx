#include <common/transform.hxx>

Transform::Transform() {

}

Transform::Transform(const Ovec3& position) {
    this->init(position, Ovec3::ZERO, Ovec3::ZERO, Ovec3::ZERO);
}

Transform::Transform(const Ovec3& position, const Ovec3& velocity) {
    this->init(position, velocity, Ovec3::ZERO, Ovec3::ZERO);
}

Transform::Transform(const Ovec3& position, const Ovec3& velocity, const Ovec3& aceleration) {
    this->init(position, velocity, aceleration, Ovec3::ZERO);
}

Transform::Transform(const Ovec3& position, const Ovec3& velocity, const Ovec3& aceleration, const Ovec3& direction) {
    this->init(position, velocity, aceleration, direction);
}

/*
* Getters
*/

Ovec3& Transform::getPosition() {
    return this->m_position;
}

Ovec3& Transform::getVelocity() {
    return this->m_velocity;
}

Ovec3& Transform::getAceleration() {
    return this->m_aceleration;
}

Ovec3& Transform::getDirection() {
    return this->m_direction;
}

/*
* Setters
*/

void Transform::setPosition(const Ovec3& position) {
    this->m_position = position;
}

void Transform::setVelocity(const Ovec3& velocity) {
    this->m_velocity = velocity;
}

void Transform::setAceleration(const Ovec3& aceleration) {
    this->m_aceleration = aceleration;
}

void Transform::setDirection(const Ovec3& direction) {
    this->m_direction = direction.normalisedCopy();
    this->setVelocity(m_direction * m_velocity.length());
}

/*
* Methods
*/

void Transform::update(const Ogre::Real time) {
    this->m_position += m_velocity * time;
    this->m_velocity += m_aceleration * time;
}

void Transform::init(const Ovec3& position, const Ovec3& velocity, const Ovec3& aceleration, const Ovec3& direction) {
    this->setPosition(position);
    this->setVelocity(velocity);
    this->setAceleration(aceleration);
    this->setDirection(direction);
}