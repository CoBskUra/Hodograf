#include "Text.h"

void DragFloatWithDisable(const bool active, const char* label, float* v, float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
	if (active) {
		ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags);
	}
	else
		ImGui::LabelText(label, "%.3f", *v);
}
