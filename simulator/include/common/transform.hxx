#ifndef __TRANSFORM_HXX__
#define __TRANSFORM_HXX__

#include <OgreRoot.h>
#include <OgreVector3.h>

typedef Ogre::Vector3 Ovec3;

class Transform {
protected:
    Ovec3 m_position;
    Ovec3 m_velocity;
    Ovec3 m_aceleration;
    Ovec3 m_direction;

public:
    Transform();
    Transform(const Ovec3& position);
    Transform(const Ovec3& position, const Ovec3& velocity);
    Transform(const Ovec3& position, const Ovec3& velocity, const Ovec3& aceleration);
    Transform(const Ovec3& position, const Ovec3& velocity, const Ovec3& aceleration, const Ovec3& direction);

    virtual Ovec3& getPosition();
    virtual Ovec3& getVelocity();
    virtual Ovec3& getAceleration();
    virtual Ovec3& getDirection();

    virtual void setPosition(const Ovec3& position);
    virtual void setVelocity(const Ovec3& velocity);
    virtual void setAceleration(const Ovec3& aceleration);
    virtual void setDirection(const Ovec3& direction);

    virtual void update(const Ogre::Real time);

private:
    void init(const Ovec3& position, const Ovec3& velocity, const Ovec3& aceleration, const Ovec3& direction);
};

#endif