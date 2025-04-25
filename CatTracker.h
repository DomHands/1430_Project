/*
* Author: Dominic Handsborough ...
* Assignment Title: Final Project
* Assignment Description: Whack-a-mole
* Due Date: 5/7/2025
* Date Created: 4/22/2025
* Date Last Modified: 4/22/2025
*/

//
//  CatTracker.h
//  Final Project
//
//  Created by Markas Flanagan on 4/25/25.
//

#ifndef CATTRACKER_H_
#define CATTRACKER_H_
#include "Cat.h"
#include <vector>
class CatTracker{
private:
    int score;
    int lives;
    vector<Cat> cats;
    SDL_Plotter& screen;
public:
    CatTracker(SDL_Plotter&);
    void tryAddMole();
    void checkKills(point);
    void update();
    void checkTimeouts();
    int getLives();
    int getScore();

    void drawScoreboard();
    void drawLivesBoard();
};




#endif /* CATTRACKER_H_ */
