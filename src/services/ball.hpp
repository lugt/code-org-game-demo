//
// Created by lugt on 24-12-19.
//

#include <vector>
#include <iostream>
#include "render.hpp"
#include "scene.hpp"

using namespace std;

class BallRenderObject : public BaseRenderObject {
  void onDraw() {
    cout << "RenderObject::onDraw()" << endl;
    x += 1;
    y += 1;
    drawCircle(x, y, 10);
  }
};

class Ball : public LogicObject {
private:
  int x;
  int y;
  BallRenderObject ballRenderObject;
public:
  Ball() {}
  ~Ball() {}
  void onCreate(LogicScene *scene) {
    ballRenderObject = BallRenderObject();
    RenderThread()->addObject(&ballRenderObject);
    cout << "Ball::onCreate()" << endl;
  }
}