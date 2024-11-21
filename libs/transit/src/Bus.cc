#define _USE_MATH_DEFINES
#include "Bus.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"

Bus::Bus(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};
  JsonArray fir(obj["first"]);
  first = {fir[0], fir[1], fir[2]};
  JsonArray sec(obj["second"]);
  second = {sec[0], sec[1], sec[2]};
  JsonArray thir(obj["third"]);
  third = {thir[0], thir[1], thir[2]};
  JsonArray four(obj["fourth"]);
  fourth = {four[0], four[1], four[2]};

  speed = obj["speed"];
}

Bus::~Bus() {
  // Delete dynamically allocated variables
  delete graph;
}

void Bus::CreateNewDestination(Vector3 des_) {
    destination = des_;
    toDestination = new AstarStrategy(position, destination, graph);
}

void Bus::Update(double dt, std::vector<IEntity*> scheduler) {
    // to first
    // to second
    // to third
    // to fourth
    if (toDestination) {
        if (toDestination->IsCompleted()) {
            if (station == 1) {
                CreateNewDestination(second);
                station = 2;
            } else if (station == 2) {
                CreateNewDestination(third);
                station = 3;
            } else if (station == 3) {
                CreateNewDestination(fourth);
                station = 4;
            } else if (station == 4) {
                CreateNewDestination(first);
                station = 1;
            }

        } else {
            toDestination->Move(this, dt);
        }

    } else {
        // no dest -> position at first, go to second
        CreateNewDestination(second);
        SetStation(2);
    }
}
