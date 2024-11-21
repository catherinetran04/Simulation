



What is the project about ?

    This Project is a simulation of the school environment based off the UMN Minneapolis campus. The main files we worked on were transit files to incorporate enities onto the map. The enitities were created through the factory pattern within CompositeFactory.cc which calls CreateFactory() on each type of entity. The entities were composed of characters such as humans along with vehicles, each implemented through JSON images. The project was iterative and incremental as we refactored and changed our code multiple times. 

How to run the simulation (overview of the whole project, not just the hw4)?

    (SSH verson)
    Accessing the project within SSH, we first go into terminal and use the command line "ssh -L _portnum(8087)_:127.0.0.1:_portnum(8087)_ x500@some.cselabs.umn.edu". First, we cd into the project directory and compile the code with "make -j". Then, we run "./build/bin/transit_service 8087 apps/transit_service/web/" to build the server. Depending on the used port number, we then go to http://127.0.0.1:_portnum(8087)_/ to view the map of the simulation. To schedule trips, we access http://127.0.0.1:_portnum(8087)_/schedule.html. This site allows us to schedule trips for the drone along with increasing the number of humans within the simulation. 

What does the simulation do specifically (individual features ie movement of entities etc) (overview of the whole project, not just the hw4)?

    Each entity has it's own implementation based on it's cc code. The drone is scheduled a trip and flies to its destination. On the way, it "picks up" the nearest robot and they both arrive at the destination together. The Helicopter continuously picks a random location and flies to it using a beeline strategy. Once the trip is complete, the helicopter reroutes a new route as it picks a new destination. Originally, the human was implemented similar to the helicopter where it continuously chooses a random destination. The human however, walks to it's destination using an astar algorithm. These entities are initialized within the umn.json file which sets details about each entity.

New Feature: What does it do?
    
    We decided to incorporate a bus system into our simulation. To do so, we created a busFactory and implemented it through the current compositeFactory code. Within umn.json, the bus was set to have four bus stops. The bus uses these bus stops by setting a new astar algorithm between each stop. This enables the bus loop to around in an continuous path. The Human was refactored to use the bus to make it's trip more efficient. As it creates it's random destination, it calculates the nearest bus stop along with it's stop to get off. If the nearest stop and drop off station are the same, the human decides it's more efficient to walk, and walks to it's destination as it was implemented originally. Otherwise, the human walks to the nearest bus stop, waits for the bus, boards and moves with the bus to the best drop off location, and finally walks the rest of the way to it's final destination. Once this destination is reached, the human randomly chooses a new destination and continues this search.  


Why is it significantly interesting?
    This implementation is significant because it simulates a real life environment. When students on campus have farther destination, they typically decide to take bus and trains around campus which is simulated within the model.

Which design pattern did you choose to implement it and why? 
    The main design pattern of the implementation is the factory pattern since it incorporates a new entity. In addition, we included a bit of observer pattern to notify users of the human interacting with the bus system. This includes which station the human is getting off at, when the human is waiting for the bus, and when the human boards and gets off the bus. 

Instruction to use this new feature (if the new feature is not user interactable, please mention this as well)
    When the code is build and run through make and build, the bus system is immediately implemented without needing user interaction. The best view would be to spectate the human on the server (maximum speed if you're impatient).

Sprint retrospective:
    During the sprint we were able to develop the new feature in a timely manner within the first sprint. We then refactored our existing code and then added the new entity. During our second sprint, we took time to debug, document, and finalize the project. Overall, the sprints went well and we both enjoyed the project.  Time management was a key issue throughout the entire project. Trying to balance two class schedules plus finals has beeen difficult, but we were able to completethe sprints in a timely manner. 


Dockerfile:
https://hub.docker.com/r/sjpetzold/drone_sim

UML: 
https://lucid.app/lucidchart/f65a4110-de55-4994-a395-73109f086a2b/edit?viewport_loc=-712%2C-1102%2C2316%2C1492%2C0_0&invitationId=inv_1cddc55a-d148-4362-a99a-b0492047e44b

Youtube Link for Final Presentation:
https://youtu.be/O_zo6f78Wjc