#include <view/planet_view.hxx>

PlanetController::PlanetController(PlanetView* planetView) :
    planetView(planetView) {
}

PlanetController::~PlanetController() {}


void PlanetController::update(const Ogre::Real time) {
    this->attract();
    this->planetView->draw();
}

void PlanetController::attract() {
    Ship* ship = this->planetView->getPlanet()->getShip();
    Ogre::Vector3 p1 = this->planetView->getPlanet()->getPosition();
    Ogre::Vector3 p2 = ship->getPosition();
    Ogre::Real m1 = this->planetView->getPlanet()->getMass();
    Ogre::Real m2 = ship->getMass();
    Ogre::Real G = 6.673e-11;
    Ogre::Vector3 d = p1 - p2;
    Ogre::Real r = d.length();

    Ogre::Real fg = G * (m1 * m2) / (r * r);
    Ogre::Vector3 F = fg * d.normalisedCopy();
    Ogre::Vector3 aceleration = F / m2;

    Ogre::Vector3 velocity = ship->getVelocity();
    velocity += aceleration;

    ship->setVelocity(velocity);

}

