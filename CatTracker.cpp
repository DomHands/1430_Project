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
    for(unsigned int i = 0; i < cats.size(); i++){
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


void CatTracker::drawScoreboard() const{
    for (int i = 0; i < score/100; i++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 10; y++) {
                screen.plotPixel(10 + i * 15 + x, 810 + y, 0, 0, 0);
            }
        }
    }
}

void CatTracker::drawLivesBoard() const{
	for(int i = 0; i < 1000; i++){
		for(int j = 851; j < 900; j++){
			screen.plotPixel(i,j,255,255,255);
		}
	}


    for (int i = 0; i < lives; i++) {
        for (int x = 0; x < 15; x++) {
            for (int y = 0; y < 15; y++) {
                screen.plotPixel(10 + i * 25 + x, 860 + y, 255, 0, 0);
            }
        }
    }
}

