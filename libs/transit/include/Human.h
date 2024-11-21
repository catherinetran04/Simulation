#ifndef HUMAN_H_
#define HUMAN_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "Bus.h"
#include "math/vector3.h"

class Human : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Destroy the Human object
   */
  ~Human();
  /**
   * @brief Gets the speed of the drone
   * @return The speed of the drone
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the position of the drone
   * @return The position of the drone
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the drone
   * @return The direction of the drone
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the drone
   * @return The destination of the drone
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the details information of the drone
   * @return The details information of the drone
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Updates the drone's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> entities);

  /**
   * @brief Sets the position of the drone
   * @param pos_ The new position of the drone
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the drone
   * @param dir_ The new direction of the drone
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief checks if bus
   * @return boolean for if bus
   */
  bool isBus() {return false; }

  /**
   * @brief Sets the destination of the drone
   * @param des_ The new destination of the drone
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Creates the new Destination for the human to walk to
   */
  void CreateNewDestination();

  /**
   * @brief Creates the new Final destination for the human to walk to
   */
  void CreateFinalTrip();

  /**
   * @brief Finds the bus entity in a vector of entities
   * @param entities A vector of entities to search through
   */
  void GetBus(std::vector<IEntity*> entities);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 first;
  Vector3 second;
  Vector3 third;
  Vector3 fourth;
  Vector3 direction;
  Vector3 busStop;
  Vector3 dropOff;
  Vector3 destination;
  float speed;
  int offStation;
  int getOn;
  bool toBus = true;
  bool wait = false;
  bool onBus = false;
  bool toDest = false;
  IStrategy* toBusStop = nullptr;
  IStrategy* toDestination = nullptr;
  IEntity* bus = nullptr;
};

#endif
