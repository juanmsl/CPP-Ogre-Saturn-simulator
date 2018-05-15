#ifndef __APP__
#define __APP__

#include <vector>

#include <PujOgreApplication.h>

#include <view/ship_view.hxx>
#include <view/planet_view.hxx>
#include <common/camera_manager.hxx>

class App : public pujOgre::Application {
protected:
  std::vector<PlanetView*> planets;
  ShipView* shipView;
  CameraManager* cameraManager;

public:
  App();
  virtual ~App();

protected:
  virtual bool mouseMoved( const OIS::MouseEvent& arg ) override;
  virtual bool keyPressed( const OIS::KeyEvent& arg ) override;
  virtual void createScene() override;
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;
  void createAnimations();
};


#endif