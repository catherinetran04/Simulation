#define _USE_MATH_DEFINES
#include "Human.h"
#include "IEntity.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "DfsStrategy.h"

Human::Human(JsonObject& obj) : details(obj) {
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

Human::~Human() {
  // Delete dynamically allocated variables
  delete graph;
}

void Human::CreateNewDestination() {
    destination = {Random(-1400, 1500), position.y, Random(-800, 800)};
    toDestination = new AstarStrategy(position, destination, graph);

    float minDis = std::numeric_limits<float>::max();
    int dist;

    if ((dist = this->position.Distance(first)) < minDis) {
        busStop = first;
        minDis = dist;
        getOn = 1;
    }
    if ((dist = this->position.Distance(second)) < minDis) {
        busStop = second;
        minDis = dist;
        getOn = 2;
    }
    if ((dist = this->position.Distance(third)) < minDis) {
        busStop = third;
        minDis = dist;
        getOn = 3;
    }
    if ((dist = this->position.Distance(fourth)) < minDis) {
        busStop = fourth;
        getOn = 4;
    }
    toBusStop = new AstarStrategy(position, busStop, graph);

    minDis = std::numeric_limits<float>::max();
    if ((dist = destination.Distance(first)) < minDis) {
        dropOff = first;
        offStation = 1;
        minDis = dist;
    }
    if ((dist = destination.Distance(second)) < minDis) {
        dropOff = second;
        offStation = 2;
        minDis = dist;
    }
    if ((dist = destination.Distance(third)) < minDis) {
        dropOff = third;
        offStation = 3;
        minDis = dist;
    }
    if ((dist = destination.Distance(fourth)) < minDis) {
        offStation = 4;
        dropOff = fourth;
    }
    std::cout << "Get off stop: " << offStation<< std::endl;
    
}

void Human::GetBus(std::vector<IEntity*> entities) {
  for (auto entity : entities) {
    if (entity->isBus()) {
        bus = entity;
    }
  }
}

void Human::Update(double dt, std::vector<IEntity*> entities) {
    if (bus == nullptr) {
        GetBus(entities);
    }

    if (toDestination) {
        

        if (toBus) {
            if(getOn == offStation) {
                std::cout << "Walking is faster.." << std::endl;
                toBus = false;
                toDest = true;
            }
            
            toBusStop->Move(this, dt);

            if (toBusStop->IsCompleted()) {
                // initialize to get picked up
                // wait for bus
                speed = 0;
                wait = true;
                std::cout << "Waiting for bus...." << std::endl;
                toBus = false;
            }
        }

        if (wait) {
            if (this->position.Distance(bus->GetPosition()) <= 0.3) {
                // bus is here
                wait = false;
                onBus = true;
                std::cout << "Takin a ride, WEEEEEEE!!! :0" << std::endl;
            }
        }

        if (onBus) {
            // move with bus
            position = bus->GetPosition();
            direction = bus->GetDirection();
            if (bus->GetPosition().Distance(dropOff) <= 83) {
                // at drop off
                // walk rest of the way
                speed = 10.0;
                onBus = false;
                toDest = true;
                std::cout << "Off we go... we walkin again :<" << std::endl;
            }
        }

        // if off Bus
        if (toDest) {
            toDestination->Move(this, dt);

            if (toDestination->IsCompleted()) {
                // initialize to get to pick up
                CreateNewDestination();
                toDest = false;
                toBus = true;
            }
        }
        
    } else {
        CreateNewDestination();
    }
}