#ifndef __APP__
#define __APP__

#include <pujOgre/Application.h>

class App : public pujOgre::Application {
public:
  App();
  virtual ~App();

protected:
  virtual void createCamera() override;
  virtual void createScene() override;
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) override;
  void createAnimations();

protected:

  Ogre::AnimationState* m_AnimationState;
};


#endif