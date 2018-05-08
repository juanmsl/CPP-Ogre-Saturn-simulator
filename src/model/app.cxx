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
  delete this->shipView;
  delete this->cameraManager;
}

void App::createScene() {
  // Lights
  this->m_SceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  this->m_SceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

  Ogre::Light* light1 = this->m_SceneMgr->createLight("Light1");
  light1->setType(Ogre::Light::LT_POINT);
  light1->setPosition(Ogre::Vector3(0, 0, 0));
  light1->setDiffuseColour(1.0, 1.0, 1.0);
  light1->setSpecularColour(1.0, 1.0, 1.0);

  Ogre::Light* light2 = this->m_SceneMgr->createLight("Light2");
  light2->setType(Ogre::Light::LT_POINT);
  light2->setPosition(Ogre::Vector3(-600, 0, 0));
  light2->setDiffuseColour(1.0, 1.0, 1.0);
  light2->setSpecularColour(1.0, 1.0, 1.0);

  this->cameraManager = new CameraManager(this->m_Camera);
  this->shipView = new ShipView(this->m_SceneMgr, this->cameraManager, "ship");
  //this->planets.push_back(new PlanetView(this->m_SceneMgr, "sol", "sun.mesh", "", Ogre::Vector3(0, 0, 0), Ogre::Real(10), Ogre::Real(40), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "mercurio", "mercury.mesh", "", Ogre::Vector3(50, 0, -200), Ogre::Real(10), Ogre::Real(20), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "venus", "Venus.mesh", "", Ogre::Vector3(400, 0, 280), Ogre::Real(10), Ogre::Real(30), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "tierra", "earth.mesh", "", Ogre::Vector3(1000, 0, -400), Ogre::Real(10), Ogre::Real(40), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "marte", "Mars.mesh", "", Ogre::Vector3(1500, 0, 400), Ogre::Real(10), Ogre::Real(40), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "jupiter", "jupiter.mesh", "", Ogre::Vector3(2300, 0, -500), Ogre::Real(10), Ogre::Real(250), Ogre::Radian(0.01)));
  //this->planets.push_back(new PlanetView(this->m_SceneMgr, "saturno", "Saturn.mesh", "", Ogre::Vector3(3500, 0, 550), Ogre::Real(10), Ogre::Real(150), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "urano", "Urano.mesh", "", Ogre::Vector3(4000, 0, -650), Ogre::Real(10), Ogre::Real(60), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "neptuno", "Neptuno.mesh", "", Ogre::Vector3(4500, 0, 700), Ogre::Real(10), Ogre::Real(50), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr, "pluton", "pluton.mesh", "", Ogre::Vector3(4800, 0, -750), Ogre::Real(10), Ogre::Real(10), Ogre::Radian(0.01)));
}

bool App::frameRenderingQueued(const Ogre::FrameEvent& evt) {
  Ogre::Real time = evt.timeSinceLastFrame;
  if(this->pujOgre::Application::frameRenderingQueued(evt)) {
    for(PlanetView* planet : this->planets) {
      planet->getPlanetController()->update(time);
    }
    this->shipView->getShipController()->update(time);
    return true;
  }
  return false;
}

bool App::keyPressed( const OIS::KeyEvent& arg ) {
  this->pujOgre::Application::keyPressed(arg);
  
  switch(arg.key) {
    case OIS::KC_W:
      this->shipView->getShipController()->acelerate();
      break;
    case OIS::KC_S:
      this->shipView->getShipController()->deacelerate();
      break;
  }

  return true;
}

bool App::mouseMoved( const OIS::MouseEvent& arg ) {
  Ogre::Real x = this->m_Mouse->getMouseState().X.rel;
  Ogre::Real y = this->m_Mouse->getMouseState().Y.rel;

  this->shipView->move(x, y);
}