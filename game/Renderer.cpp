//
// Created by niels on 5/27/21.
//

#include "Renderer.h"

Renderer &Renderer::getInstance() {
    static Renderer INSTANCE;
    return INSTANCE;
}