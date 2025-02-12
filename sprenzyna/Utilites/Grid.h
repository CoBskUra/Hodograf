#pragma once
#include <string>
#include "imgui.h"

enum Grid_CR
{
	Colum,
	Row
};


class Grid
{
private:

	ImVec2 _position;
	ImVec2 _size;
	bool _haveChildren;
	Grid_CR _kindOfSplit;
	int amountOfChildren;

	Grid* _children;
	std::string _index;

	void SetSize(ImVec2 newSize, ImVec2 position, float comulatePercent);

public:
	float percent;


	Grid(float percent = 1.0f, std::string index = "", float x = 0, float y = 0)
	{
		this->percent = percent;
		_index = index;
		_position = ImVec2(x, y);
	}


	void Split(Grid grids[], int length, Grid_CR kindOfSplit);
	Grid* FindIndex(std::string index);
	void SetIndex(std::string index);

	void SetSize(float x, float y);
	ImVec2 GetPosition();
	ImVec2 GetSize();


};