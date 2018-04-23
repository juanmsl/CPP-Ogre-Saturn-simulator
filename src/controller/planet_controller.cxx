#include "../view/planet_view.hxx"

PlanetController::PlanetController(PlanetView* planetView, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius) :
    planetView(planetView),
    planet(Planet(position, mass, radius)) {
}

PlanetController::~PlanetController() {}


void PlanetController::update(const Ogre::Real time) {
    Ogre::Radian angle = this->planet.getRotation() + Ogre::Radian(time);
    this->planet.setRotation(angle);
    this->planetView->draw();
}

void PlanetController::attract() {}


Planet* PlanetController::getPlanet() {
    return &this->planet;
}
