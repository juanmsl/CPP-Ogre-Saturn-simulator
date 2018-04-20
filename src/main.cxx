#include <iostream>

#include "model/app.hxx"

// Main
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else  // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
int main(int argc, char *argv[])
#endif // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
{
  // Create application object
  App app;
  try {
    app.go();
  } catch (Ogre::Exception &e) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else  // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    std::cerr
        << "An exception has occured: "
        << e.getFullDescription().c_str()
        << std::endl;
#endif // OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  }    // yrt
  return (0);
}
#ifdef __cplusplus
}
#endif // __cplusplus