#include <iostream>
#include <pujOgre/Application.h>

#include <OgreBone.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreKeyFrame.h>
#include <OgreMeshManager.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreSkeletonInstance.h>

class SimulatorAPP : public pujOgre::Application {
public:
  SimulatorAPP();
  virtual ~SimulatorAPP();

protected:
  virtual void createCamera() override;
  virtual void createScene() override;
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;
  void createAnimations();

protected:
  Ogre::AnimationState* m_AnimationState;
};

// -------------------------------------------------------------------------
// Main
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    int main(int argc, char* argv[])
#endif // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  {
    // Create application object
    SimulatorAPP app;
    try
    {
      app.go();
    }
    catch(Ogre::Exception& e)
    {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      std::cerr
        << "An exception has occured: "
        << e.getFullDescription().c_str()
        << std::endl;
#endif // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    } // yrt
    return(0);
  }
#ifdef __cplusplus
}
#endif // __cplusplus

// -------------------------------------------------------------------------
SimulatorAPP::SimulatorAPP() : pujOgre::Application() {}

// -------------------------------------------------------------------------
SimulatorAPP::~SimulatorAPP() {}

// -------------------------------------------------------------------------
void SimulatorAPP::createCamera() {
  this->pujOgre::Application::createCamera();
  this->m_Camera->setPosition(Ogre::Vector3(25, 25, 25));
  this->m_Camera->lookAt(Ogre::Vector3(0, 10, 0));
  this->m_Camera->setNearClipDistance(5);
}

// -------------------------------------------------------------------------
void SimulatorAPP::createScene() {
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

// -------------------------------------------------------------------------
bool SimulatorAPP::frameRenderingQueued(const Ogre::FrameEvent& evt) {
  if(this->pujOgre::Application::frameRenderingQueued(evt)) {
    this->m_AnimationState->addTime(evt.timeSinceLastFrame);
    return true;
  }
  
  return false;
}

// -------------------------------------------------------------------------
void SimulatorAPP::createAnimations() {}
