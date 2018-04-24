#ifndef __SHIP_CONTROLLER_HXX__
#define __SHIP_CONTROLLER_HXX__

#include "../model/ship.hxx"

class ShipView;

class ShipController {
protected:
    ShipView* shipView;

public:
    ShipController(ShipView* shipView);
    virtual ~ShipController();

    void update(const Ogre::Real time);

    void acelerate();
    void deacelerate();
};

#endif