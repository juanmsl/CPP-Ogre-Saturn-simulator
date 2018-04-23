#ifndef __APP__
#define __APP__

#include <vector>

#include <pujOgre/Application.h>
#include "../view/planet_view.hxx"

class App : public pujOgre::Application {
protected:
  std::vector<PlanetView*> planets;

public:
  App();
  virtual ~App();

protected:
  virtual void createCamera() override;
  virtual void createScene() override;
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;
  void createAnimations();
};


#endif