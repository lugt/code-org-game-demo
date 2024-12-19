//
// Created by lugt on 24-12-19.
//

#include <vector>
#include "render.hpp"
#include "scene.hpp"
#include "ui_scene.hpp"

using namespace std;

class LogicObject {

}

class LogicScene {
  std::vector<GameObject> gameObjects;
  public:
    Scene() {
      for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects.push_back(GameObject());
      }
    }
    addObject(LogicObject obj);
  protected:
};