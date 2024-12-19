//
// Created by lugt on 24-12-19.
//

#ifndef RENDER_H
#define RENDER_H

#include "render.h"
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

class BaseRenderObject;

class RenderThread : public QThread {
private:
  QMutex mutex;
  std::vector<BaseRenderObject> BaseRenderObjects;
public:
  RenderThread();
  BaseRenderObject addBaseRenderObject(int style) {
    BaseRenderObject BaseRenderObject(style);
    BaseRenderObjects.push_back(BaseRenderObject);
    return BaseRenderObject;
  }
  void run() {
    while (true) {
      drawBackground();
      drawText();
      for (int i = 0; i < BaseRenderObjects.size(); i++) {
        BaseRenderObjects[i]->onDraw();
      }
    };
  }
};

void drawCircle(int x, int y, int r);

// Get the global render thread.
export RenderThread* RenderThread();

class BaseRenderObject {
private:
  int style;
  int x;
  int y;
public:
  BaseRenderObject(){};
  BaseRenderObject(int _style): style(_style) {};
};

#endif //RENDER_H
