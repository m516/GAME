#pragma once

#include "../application.h"

class Network
{
    public:
        Network(Application*);
        void start();

    private:
        void networkLoop();
        Application* application;
    protected:
};