#include <common/app.hxx>

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
  MathUtilities::scaleFactor = 0.01;
  //this->planets.push_back(new PlanetView(this->m_SceneMgr, "sol", "sun.mesh", "", Ogre::Vector3(0, 0, 0), Ogre::Real(10), Ogre::Real(40), Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "mercurio",  "mercury.mesh",  "", this->shipView->getShip(), Ogre::Vector3(57909175000, 0, 0),   Ogre::Real(3.302e23), Ogre::Real(240000000),    Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "venus",     "Venus.mesh",    "", this->shipView->getShip(), Ogre::Vector3(108208930000, 0, 0),  Ogre::Real(4.8690e24), Ogre::Real(600000000),   Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "tierra",    "earth.mesh",    "", this->shipView->getShip(), Ogre::Vector3(149597870000, 0, 0),  Ogre::Real(5.9742e24), Ogre::Real(630000000),   Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "marte",     "Mars.mesh",     "", this->shipView->getShip(), Ogre::Vector3(227936640000, 0, 0),  Ogre::Real(6.4191e23), Ogre::Real(340000000),   Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "jupiter",   "jupiter.mesh",  "", this->shipView->getShip(), Ogre::Vector3(778412010000, 0, 0),  Ogre::Real(1.8987e27), Ogre::Real(7500000000),  Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "saturno",   "Saturn.mesh",   "", this->shipView->getShip(), Ogre::Vector3(1426725400000, 0, 0), Ogre::Real(5.6851e26), Ogre::Real(6000000000),  Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "urano",     "Urano.mesh",    "", this->shipView->getShip(), Ogre::Vector3(2870972200000, 0, 0), Ogre::Real(8.6849e25), Ogre::Real(2530000000),  Ogre::Radian(0.01)));
  this->planets.push_back(new PlanetView(this->m_SceneMgr,  "neptuno",   "Neptuno.mesh",  "", this->shipView->getShip(), Ogre::Vector3(4498252900000, 0, 0), Ogre::Real(1.0244e26), Ogre::Real(2460000000),  Ogre::Radian(0.01)));
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