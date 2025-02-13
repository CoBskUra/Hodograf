#pragma once
#include <imgui.h>
#include <string>
#include <format>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
//#include "ExtendImVec2.h"

namespace Simulation {
    struct SimulationState {
        float position = 0;
        float velocity = 0;
        float acceleration = 0;

        float lastPosition = 0;
        float lastVelocity = 0;

        float angularSpeed = 0;
        float arm = 250;
        float armWithError = 250;
        float radius = 60;

        float time = 0;

        ImVec2 actualPosOnCircle;

        float positionScalar = 10;

        float standard_variation = 1;
        std::normal_distribution<float> normalDistribution{ 0,0.0000001 };
    };

    struct HodografsAppearance {
        ImVec2 weightSize;
        ImVec4 circleColor{ 1, 0.2f, 0.2, 1 };
        ImVec4 weightColor{ 0.3, 0.3, 0.5, 1 };
        ImVec4 armColor{ 0.3, 0.8, 0.3, 1 };
        ImVec4 horizontalLineColor{1, 0, 0, 1};
    };

    class HodografSimulation {
        std::mt19937 gen;
    public:
        SimulationState state;
        HodografsAppearance appearance;

        HodografSimulation(SimulationState state, HodografsAppearance appearance)
        {
            this->state = state;
            this->appearance = appearance;

            std::random_device rd{};
            gen = std::mt19937{ rd()};
        }

        void DrawHodograf();
        void CalculateNextState(float passTime);
    };


};