#pragma once
#include "Duck/Duck.h"

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Fly();
	duck.Fly();
	duck.Fly();
	duck.Fly();
	duck.Dance();
	std::cout << std::endl;
}