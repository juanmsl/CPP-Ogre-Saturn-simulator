#include "planet_view.hxx"

#include <iostream>

PlanetView::PlanetView(Ogre::SceneManager* sceneManager, const std::string& name, const std::string& mesh, const std::string& material, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius, const Ogre::Radian rotation) :
    name(name),
    mesh(mesh),
    material(material),
    planet(Planet(position, mass, radius, rotation)),
    planetController(PlanetController(this)),
    sceneManager(sceneManager) {

    this->entity = this->sceneManager->createEntity(this->name, this->mesh);
    this->entity->setCastShadows(true);
    //this->entity->setMaterialName("Mat");

    this->node = this->sceneManager->getRootSceneNode()->createChildSceneNode(this->name + "_node");
    this->node->attachObject(this->entity);
    this->draw();
}

PlanetView::~PlanetView() {}

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