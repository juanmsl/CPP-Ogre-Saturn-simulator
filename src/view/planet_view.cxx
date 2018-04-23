#include "planet_view.hxx"

#include <iostream>

PlanetView::PlanetView(Ogre::SceneManager* sceneManager, const std::string& name, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius) :
    name(name),
    planetController(PlanetController(this, position, mass, radius)),
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
    std::cout << this->planetController.getPlanet()->getRotation() << std::endl;
    this->node->setPosition(this->planetController.getPlanet()->getPosition());
    this->node->scale(Ogre::Vector3(this->planetController.getPlanet()->getRadius()));
    //this->node->rotate(Ogre::Vector3(0, 1, 0), Ogre::Radian(0));
}

PlanetController* PlanetView::getPlanetController() {
    return &this->planetController;
}