#include "app.hxx"

#include <OgreBone.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreKeyFrame.h>
#include <OgreMeshManager.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreSkeletonInstance.h>

#include <iostream>

App::App() : pujOgre::Application() {}

App::~App() {
  for(PlanetView* planet : this->planets) {
    delete planet;
  }
}

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

  PlanetView* mercurio = new PlanetView(this->m_SceneMgr, "mercurio", Ogre::Vector3(0, 0, 0), Ogre::Real(10), Ogre::Real(25));
  this->planets.push_back(mercurio);

}

bool App::frameRenderingQueued(const Ogre::FrameEvent& evt) {
  Ogre::Real time = evt.timeSinceLastFrame;
  if(this->pujOgre::Application::frameRenderingQueued(evt)) {
    for(int i = 0; i < this->planets.size(); i++) {
      this->planets[i]->getPlanetController()->update(time);
    }
    return true;
  }
  return false;
}