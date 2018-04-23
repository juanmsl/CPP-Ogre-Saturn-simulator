#ifndef __PLANET_CONTROLLER__
#define __PLANET_CONTROLLER__

#include "../model/planet.hxx"

class PlanetView;

class PlanetController {
protected:
    Planet planet;
    PlanetView* planetView;
    
public:
    PlanetController(PlanetView* planetView, const Ogre::Vector3 position, const Ogre::Real mass, const Ogre::Real radius);
    virtual ~PlanetController();

    void update(const Ogre::Real time);
    void attract();

    Planet* getPlanet();
};

#endif