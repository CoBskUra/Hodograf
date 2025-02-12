#include "Plots.h"

namespace Simulation {
    void GraphOfPosition(float time, float position,
        bool pause, bool reset)
    {
        static ScrollingBuffer data;

        if (reset)
        {
            data.Erase();
        }

        const char* name = "Position";

        //Analog signal values
        if (pause) {
            data.AddPoint(time, position);
        }

        auto windowSize = ImGui::GetWindowSize();
        auto size = windowSize - ImVec2(30, 50);



        if (ImPlot::BeginPlot("##GraphOfPositionVelocityAcceleration", size)) {
            ImPlot::SetupAxisLimits(ImAxis_X1, time - 10.0, time, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1, -1, 1);
            
                if (data.Data.size() > 0)
                    ImPlot::PlotLine(name, &data.Data[0].x, &data.Data[0].y, data.Data.size(), 0, data.Offset, 2 * sizeof(float));

            ImPlot::EndPlot();
        }
    }

    void GraphOfAcceleration(float time, float acceleration,
        bool pause, bool reset)
    {
        static ScrollingBuffer data;

        if (reset)
        {
            data.Erase();
        }

        const char* name = "Acceleration";

        //Analog signal values
        if (pause) {
            data.AddPoint(time, acceleration);
        }

        auto windowSize = ImGui::GetWindowSize();
        auto size = windowSize - ImVec2(30, 50);



        if (ImPlot::BeginPlot("##Acceleration", size)) {
            ImPlot::SetupAxisLimits(ImAxis_X1, time - 10.0, time, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1, -1, 1);

            if (data.Data.size() > 0)
                ImPlot::PlotLine(name, &data.Data[0].x, &data.Data[0].y, data.Data.size(), 0, data.Offset, 2 * sizeof(float));

            ImPlot::EndPlot();
        }
    }

    void GraphOfVelocity(float time, float velocity,
        bool pause, bool reset)
    {
        static ScrollingBuffer data;

        if (reset)
        {
            data.Erase();
        }

        const char* name = "Velocity";

        //Analog signal values
        if (pause) {
            data.AddPoint(time, velocity);
        }

        auto windowSize = ImGui::GetWindowSize();
        auto size = windowSize - ImVec2(30, 50);



        if (ImPlot::BeginPlot("##Velocity", size)) {
            ImPlot::SetupAxisLimits(ImAxis_X1, time - 10.0, time, ImGuiCond_Always);
            ImPlot::SetupAxisLimits(ImAxis_Y1, -1, 1);

            if (data.Data.size() > 0)
                ImPlot::PlotLine(name, &data.Data[0].x, &data.Data[0].y, data.Data.size(), 0, data.Offset, 2 * sizeof(float));

            ImPlot::EndPlot();
        }
    }

    void GraphOfTrajectory(float position, float velocity, bool pause, bool reset)
    {
        static ScrollingBuffer trajectory;
        if (reset)
        {
            trajectory.Erase();
        }

        const char* label = "Trajectory";

        if(pause)
            trajectory.AddPoint(position, velocity);

        auto windowSize = ImGui::GetWindowSize();
        auto size = windowSize - ImVec2(30, 50);

        if (ImPlot::BeginPlot("##GraphOfTrajectory", size)) {
            ImPlot::SetupAxisLimits(ImAxis_Y1, -10, 10);
            ImPlot::SetupAxisLimits(ImAxis_X1, -10, 10);
            if (trajectory.Data.size() > 0)
            ImPlot::PlotLine(label, &trajectory.Data[0].x, &trajectory.Data[0].y, trajectory.Data.size(), 0, trajectory.Offset, 2 * sizeof(float));
            
            ImPlot::EndPlot();
        }
    }
}