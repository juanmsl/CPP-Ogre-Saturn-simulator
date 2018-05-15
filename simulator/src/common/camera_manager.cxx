#include <common/camera_manager.hxx>

CameraManager::CameraManager(Ogre::Camera* camera) :
    camera(camera) {
}

void CameraManager::update(Ship* ship) {
    Ogre::Vector3 position = ship->getPosition();
    Ogre::Vector3 direction = ship->getDirection();
    Ogre::Vector3 cameraLook = position;
    Ogre::Vector3 cameraPosition = position - 5 * (direction);

    //this->camera->lookAt(position + direction);
    //this->camera->setPosition(position);

    this->camera->lookAt(cameraLook);
    this->camera->setPosition(cameraPosition);
}
