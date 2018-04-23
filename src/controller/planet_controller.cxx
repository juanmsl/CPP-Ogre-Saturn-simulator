#include "../view/planet_view.hxx"

PlanetController::PlanetController(PlanetView* planetView) :
    planetView(planetView) {
}

PlanetController::~PlanetController() {}


void PlanetController::update(const Ogre::Real time) {
    
    this->planetView->draw();
}

void PlanetController::attract() {}

