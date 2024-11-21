#ifndef Bus_H_
#define Bus_H_

#include "IEntity.h"
#include "IStrategy.h"

class Bus : public IEntity {
 public:
  /**
   * @brief Bus's are created with a name
   * @param obj JSON object containing the Bus's information
   */
  Bus(JsonObject& obj);

  /**
   * @brief Destroy the Bus object
   */
  ~Bus();

  /**
   * @brief Gets the speed of the Bus
   * @return The speed of the Bus
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the position of the Bus
   * @return The position of the Bus
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the Bus
   * @return The direction of the Bus
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the Bus
   * @return The destination of the Bus
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the details information of the Bus
   * @return The details information of the Bus
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Updates the Bus's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the position of the Bus
   * @param pos_ The new position of the Bus
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the Bus
   * @param dir_ The new direction of the Bus
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the Bus
   * @param des_ The new destination of the Bus
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the Station of the Bus
   * @param stat_ The new station of the Bus
   */
  void SetStation(int stat_) {station = stat_; }

  /**
   * @brief Gets the station of the Bus
   */
  int GetStation() {return station; }

  /**
   * @brief checks if bus
   * @return boolean for if bus
   */
  bool isBus() {return true; }

  /**
   * @brief Creates the new destination of the Bus
   * @param des_ The new destination of the Bus
   */
  void CreateNewDestination(Vector3 des_);


 private:
  JsonObject details;
  Vector3 position;
  Vector3 first;
  Vector3 second;
  Vector3 third;
  Vector3 fourth;
  Vector3 direction;
  Vector3 destination;
  float speed;
  int station = 1;
  IStrategy* toDestination = nullptr;
};

#endif
