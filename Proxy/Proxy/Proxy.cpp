// Proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class IGraphic
{
public:
	virtual void Draw() = 0;
};

class Graphic : public IGraphic
{
public:
	Graphic()
	{
	}
	~Graphic()
	{	
	}
	void Draw()
	{
		std::cout << "Drawing Graphic" << std::endl;;
	}
};

class GraphicProxy : public IGraphic
{
public:
	GraphicProxy()
	{
		this->graphic = 0;
	}
	~GraphicProxy()
	{
		if (graphic)
			delete graphic;
	}
	void Draw()
	{
		getInstance()->Draw();
	}
private:
	Graphic* graphic;
	Graphic* getInstance(void)
	{
		if(!graphic)
		{
			graphic = new Graphic;
			return graphic;
		}
	}
}; 

int main()
{
	GraphicProxy gp;
	gp.Draw();
	system("pause");
}