/*
* Author: Dominic Handsborough ...
* Assignment Title: Final Project
* Assignment Description: Whack-a-mole
* Due Date: 5/7/2025
* Date Created: 4/21/2025
* Date Last Modified: 4/22/2025
*/

#ifndef CAT_H_
#define CAT_H_
#include "SDL_Plotter.h"
#include "CatPicture.h"
#include <cmath>
double distance(point p1, double x, double y);
double distance(point p1, point p2);
int random(int min, int max);
class Cat{
private:
	point start;
	point position;
	int timeAlive;
	static const int radius = 25;
	static const int roamingDistance = 100;
	static const int lifeSpan = 50;
	static const int speed = 3;

	color furColor;
    	color eyeColor;
   	color noseColor;
    	color whiskerColor;
   	color mouthColor;
    	color tongueColor;
public:
	Cat(point = point(500, 500));

	void draw(SDL_Plotter&);
	void undraw(SDL_Plotter&);
	void update(SDL_Plotter&);
	bool contains(point);
	bool wouldOverlap(point);
	bool isTimedOut();
	int kill(SDL_Plotter&);
	static int getRoamingDistance();//
};
#endif /* CAT_H_ */
