#include "BusFactory.h"

IEntity* BusFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("bus") == 0) {
    std::cout << "Bus Created" << std::endl;
    return new Bus(entity);
  }
  return nullptr;
}
