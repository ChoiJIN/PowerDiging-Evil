#pragma once

class Screen
{
public:
	Screen()
	{
	}

	virtual ~Screen()
	{
	}

	virtual void update(double delta) = 0;

	virtual void render() = 0;

private:
};

