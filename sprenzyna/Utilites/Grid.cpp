#include "Grid.h"

void Grid::Split(Grid grids[], int length, Grid_CR kindOfSplit)
{
	_children = grids;
	amountOfChildren = length;
	for (int i = 0; i < length; i++)
		_children[i]._kindOfSplit = kindOfSplit;
	SetSize(_size.x, _size.y);
}

Grid* Grid::FindIndex(std::string index)
{
	if (_index == index)
		return this;

	for (int i = 0; i < amountOfChildren; i++) {
		Grid* result = _children[i].FindIndex(index);
		if (result != nullptr)
			return result;
	}
	return nullptr;
}

void Grid::SetIndex(std::string index)
{
	_index = index;
}

void Grid::SetSize(float x, float y)
{
	if (_size.x == x && _size.y == y)
		return;

	SetSize(ImVec2(x, y), _position, 0);
	_size = ImVec2(x, y);
}


void Grid::SetSize(ImVec2 newParentSize, ImVec2 parentPosition, float comulatePercent)
{
	_size = newParentSize;
	_position = parentPosition;
	switch (_kindOfSplit) {
	case Grid_CR::Colum:
		_size.x = percent * newParentSize.x;
		_position.x = parentPosition.x + newParentSize.x * comulatePercent;
		break;
	case Grid_CR::Row:
		_size.y = percent * newParentSize.y;
		_position.y = parentPosition.y + newParentSize.y * comulatePercent;
		break;
	default:
		break;
	}

	float newComulatePercent = 0;
	for (int i = 0; i < amountOfChildren; i++)
	{
		_children[i].SetSize(_size, _position, newComulatePercent);
		newComulatePercent += _children[i].percent;
	}
}


ImVec2 Grid::GetPosition()
{
	return _position;
}

ImVec2 Grid::GetSize()
{
	return _size;
}
