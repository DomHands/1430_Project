/*
* Author: Dominic Handsborough ...
* Assignment Title: Final Project
* Assignment Description: Whack-a-mole
* Due Date: 5/7/2025
* Date Created: 4/22/2025
* Date Last Modified: 4/22/2025
*/

#include "CatTracker.h"

CatTracker::CatTracker(SDL_Plotter& screenIn) :
screen(screenIn), score(0), lives(3) {}

void CatTracker::tryAddMole(){
	bool canPlace = true;
	int randX = random(Cat::getRoamingDistance(), 1000 - Cat::getRoamingDistance());
	int randY = random(Cat::getRoamingDistance(), 800 - Cat::getRoamingDistance());
	point location(randX, randY);
	for(Cat& currCat : cats){
		if(currCat.wouldOverlap(location)){
			canPlace = false;
		}
	}
	if(canPlace){
		cats.push_back(Cat(location));
	}
}

void CatTracker::checkKills(point click){
	for(int i = 0; i < cats.size(); i++){
		if(cats.at(i).contains(click)){
			score += cats.at(i).kill(screen);
			cats.erase(cats.begin() + i--);
		}
	}
}

void CatTracker::update(){
	for(Cat& currCat : cats){
		currCat.update(screen);
	}
}

void CatTracker::checkTimeouts(){
	for(int i = 0; i < cats.size(); i++){
		if(cats.at(i).isTimedOut()){
			cats.at(i).kill(screen);
			cats.erase(cats.begin() + i--);
			lives--;
		}
	}
}

int CatTracker::getLives() const{
	return lives;
}

int CatTracker::getScore() const{
	return score;
}




