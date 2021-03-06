#pragma once

#include <btBulletDynamicsCommon.h>
#include <OgreVector3.h>

// Forward declarations.
class PhysicsCollider;
  constexpr float DEFAULT_GRAVITY = 6000.0;

class Physics {
  btBroadphaseInterface* broadphase;
  btDefaultCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* dispatcher;
  btSequentialImpulseConstraintSolver* solver;
  btDiscreteDynamicsWorld* dynamicsWorld;
  float accumTime;
  float myGrav;
  bool gravEnabled;

public:
  /**
   * Creates a new physics simulation system.
   * 
   * @param gravity acceleration due to gravity in the local coordinate system
   *                (by default, is 9800 cm/s^2, appropriate for metric units)
   */
  Physics(float gravity = DEFAULT_GRAVITY);
  ~Physics();
  
  void stepSimulation(float timestep);
  btDynamicsWorld* getDynamicsWorld();
  PhysicsCollider* rayCast(const Ogre::Vector3& start,
                           const Ogre::Vector3& direction,
                           float maxDist) const;
  const std::vector<PhysicsCollider*>
  rayCastAll(const Ogre::Vector3& start,
             const Ogre::Vector3& direction,
             float maxDist) const;

  void disableGravity();
  void enableGravity();
  bool isGravityEnabled() const;
};
