#ifndef BUS_FACTORY_H_
#define BUS_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Bus.h"

/**
 *@brief Bus Factory to produce Bus class.
 **/
class BusFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~BusFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
