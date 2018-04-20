#include "app.hxx"

#include <OgreBone.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreKeyFrame.h>
#include <OgreMeshManager.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreSkeletonInstance.h>

App::App() : pujOgre::Application() {}

App::~App() {}

void App::createCamera() {
  this->pujOgre::Application::createCamera();
  this->m_Camera->setPosition(Ogre::Vector3(0, 25, 110));
  this->m_Camera->lookAt(Ogre::Vector3(0, 10, 0));
  this->m_Camera->setNearClipDistance(5);
}

void App::createScene() {
  // Lights
  this->m_SceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  this->m_SceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

  Ogre::Light* light1 = this->m_SceneMgr->createLight("Light1");
  light1->setType(Ogre::Light::LT_POINT);
  light1->setPosition(Ogre::Vector3(50, 50, 50));
  light1->setDiffuseColour(1.0, 1.0, 1.0);
  light1->setSpecularColour(1.0, 1.0, 1.0);

  Ogre::Light* light2 = this->m_SceneMgr->createLight("Light2");
  light2->setType(Ogre::Light::LT_POINT);
  light2->setPosition(Ogre::Vector3(0, 50, -50));
  light2->setDiffuseColour(0.5, 0.5, 0.5);
  light2->setSpecularColour(0.5, 0.5, 0.5);

  // Create a plane
  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().
    createPlane(
      "plane",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
      plane,
      150, 150, 20, 20, true, 1, 5, 5,
      Ogre::Vector3::UNIT_Z
     );

  // Associate a floor entity with the created plane
  Ogre::Entity* floor = this->m_SceneMgr->createEntity("floor", "plane");
  floor->setMaterialName("Mat");
  this->m_SceneMgr->getRootSceneNode()->attachObject(floor);
}

bool App::frameRenderingQueued(const Ogre::FrameEvent& evt) {
  Ogre::Real time = evt.timeSinceLastFrame;
  if(this->pujOgre::Application::frameRenderingQueued(evt)) {
    this->m_AnimationState->addTime(time);
    return true;
  }
  return false;
}

void App::createAnimations() {}