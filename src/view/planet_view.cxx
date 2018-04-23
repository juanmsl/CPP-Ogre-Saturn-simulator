#include "planet_view.hxx"

#include <iostream>

PlanetView::PlanetView(Ogre::SceneManager* sceneManager, const std::string& name, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius, const Ogre::Radian rotation) :
    name(name),
    planet(Planet(position, mass, radius, rotation)),
    planetController(PlanetController(this)),
    sceneManager(sceneManager) {
    this->create();
}

PlanetView::~PlanetView() {}

void PlanetView::create() {
    if(this->sceneManager != nullptr) {
        this->entity = this->sceneManager->createEntity(this->name, "sphere.mesh");
        this->entity->setCastShadows(true);
        this->entity->setMaterialName("Mat");

        this->node = this->sceneManager->getRootSceneNode()->createChildSceneNode(this->name + "_node");
        this->node->attachObject(this->entity);
        this->draw();
    }
}

void PlanetView::draw() {
    this->node->setPosition(this->planet.getPosition());
    this->node->setScale(Ogre::Vector3(this->planet.getRadius()));
    this->node->rotate(Ogre::Vector3(0, 1, 0), this->planet.getRotation());
}

PlanetController* PlanetView::getPlanetController() {
    return &this->planetController;
}

Planet* PlanetView::getPlanet() {
    return &this->planet;
}