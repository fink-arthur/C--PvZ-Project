#pragma once

class Strip{

	public:
	Strip();
	~Strip();
	void draw();
	void setSelection(int newValue);

	int selection = 0;
};
