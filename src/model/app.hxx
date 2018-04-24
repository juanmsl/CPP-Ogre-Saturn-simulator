#ifndef __APP__
#define __APP__

#include <vector>

#include <pujOgre/Application.h>
#include "../view/ship_view.hxx"
#include "../view/planet_view.hxx"

class App : public pujOgre::Application {
protected:
  std::vector<PlanetView*> planets;
  ShipView* shipView;

public:
  App();
  virtual ~App();

protected:
  virtual bool keyPressed( const OIS::KeyEvent& arg ) override;
  virtual void createCamera() override;
  virtual void createScene() override;
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;
  void createAnimations();
};


#endif