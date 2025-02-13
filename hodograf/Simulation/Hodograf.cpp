#include "Hodograf.h"
#include "../MathHelper.h"


namespace Simulation {

    void HodografSimulation::DrawHodograf() {
        const auto& style = ImGui::GetStyle();
        const auto& draw_list = ImGui::GetWindowDrawList();
        const auto& screenPos = ImGui::GetCursorScreenPos();
        const auto& windowSize = ImGui::GetWindowSize();

        ImVec2 topLeft = screenPos;
        ImVec2 bottomRight = screenPos + windowSize;
        ImVec2 center = (topLeft + bottomRight) * 0.5f;
        center.y -= ImGui::GetFontSize() * 1.5f;
        
        float scale = 1;
        if (state.radius > windowSize.y * 0.9f * 0.5f) {
            scale = windowSize.y * 0.5f * 0.9f / state.radius;
        }
        else if (state.radius < windowSize.y * 0.1f * 0.5f) {
            scale = windowSize.y * 0.5f * 0.1f / state.radius;
        }

        float armLength = state.armWithError * scale;
        float radius = state.radius * scale;
        ImVec2 circleCenter = center - ImVec2{ windowSize.x * 0.5f - radius, 0 };
        ImVec2 posOnCircle = state.actualPosOnCircle * scale;
        float position;
        position = posOnCircle.x + sqrtf(armLength * armLength - posOnCircle.y * posOnCircle.y);



        ImVec2 rantaglePos = circleCenter + ImVec2{ position, 0 };
        ImVec2 rantagleHalfSize = appearance.weightSize * 0.5f * scale;

        draw_list->AddLine(center + ImVec2{ windowSize.x, 0 }, center - ImVec2{ windowSize.x, 0 }, ImGui::ColorConvertFloat4ToU32(appearance.horizontalLineColor), 1);
        draw_list->AddCircle(circleCenter, radius, ImGui::ColorConvertFloat4ToU32(appearance.circleColor), 30, 5);

        draw_list->AddRectFilled(rantaglePos - rantagleHalfSize, rantaglePos + rantagleHalfSize, ImGui::ColorConvertFloat4ToU32(appearance.weightColor), style.FrameRounding);

        draw_list->AddLine(rantaglePos, circleCenter + posOnCircle, ImGui::ColorConvertFloat4ToU32(appearance.armColor), 5);
    }

    void HodografSimulation::CalculateNextState(float passTime) {
        state.time += passTime;
        /*if (state.angularSpeed * state.time > MathHelper::PI * 2) {
            state.time = std::fmod(state.time, MathHelper::PI * 2 / state.angularSpeed);
        }*/
        float alfa = MathHelper::fwrap(state.angularSpeed * state.time, 0, 2 * MathHelper::PI);
        float c = cosf(alfa);
        float s = sinf(alfa);

        state.armWithError = state.arm + state.normalDistribution(gen);
        state.position = c * state.radius + state.armWithError;
        state.velocity = (state.position - state.lastPosition) / passTime;
        state.acceleration = (state.velocity - state.lastVelocity) / passTime;
        /*state.velocity = -s * state.radius * state.angularSpeed;
        state.acceleration = -c * state.radius * state.angularSpeed;*/
        state.lastPosition = state.position;
        state.lastVelocity = state.velocity;

        state.actualPosOnCircle = ImVec2{ c, s } * state.radius;
    }
}


