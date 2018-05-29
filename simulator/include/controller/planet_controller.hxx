#ifndef __PLANET_CONTROLLER__
#define __PLANET_CONTROLLER__

#include <model/planet.hxx>
#include <model/ship.hxx>

class PlanetView;

class PlanetController {
protected:
    PlanetView* planetView;
    
public:
    PlanetController(PlanetView* planetView);
    virtual ~PlanetController();

    void update(const Ogre::Real time);
    void attract();
};

#endif