#pragma once
#include "imgui.h"
#include "implot.h"
#include <corecrt_math.h>
#include <stdio.h>


namespace Simulation {
    struct ScrollingBuffer {
        int MaxSize;
        int Offset;
        ImVector<ImVec2> Data;
        ScrollingBuffer(int max_size = 2000) {
            MaxSize = max_size;
            Offset = 0;
            Data.reserve(MaxSize);
        }
        void AddPoint(float x, float y) {
            if (Data.size() < MaxSize)
                Data.push_back(ImVec2(x, y));
            else {
                Data[Offset] = ImVec2(x, y);
                Offset = (Offset + 1) % MaxSize;
            }
        }
        void Erase() {
            if (Data.size() > 0) {
                Data.shrink(0);
                Offset = 0;
            }
        }
    };

    void GraphOfPosition(float time, float position, bool pause = false, bool reset = false);
    void GraphOfVelocity(float time, float velocity, bool pause = false, bool reset = false);
    void GraphOfAcceleration(float time, float acceleration, bool pause = false, bool reset = false);

    void GraphOfForces(float time, float HodografForce, float dampingForce, float w, float h, bool pause = false, bool reset = false);
    void GraphOfTrajectory(float position, float velocity, bool pause = false, bool reset = false);

};