/**
 * Declaration of the Human class.
 *
 * @author Stefan Brandle
 * @date March 2012
 */

#include "Board.h"

#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

/**
 * @class Human
 * @brief The Human class declaration.
 */
class Human {
    public:
        Human(int initRow, int initCol, bool initInfected, Board* thisBoard, bool dead);
	virtual ~Human();
	virtual void move();
	virtual void draw();
    //virtual void die();

	// "Setters" and "getters"
	virtual void getLocation(int& row, int& col);
	virtual void setLocation(int row, int col);
	virtual void setInfected();
	virtual bool isInfected();
    virtual bool isDead();
    virtual void kill();

    protected:
    bool suddenDeath;
    bool infected;     // Track whether or not this human is infected.
	int row, col;      // The row and column where this human is on the board.
    bool dead;
    Board *board;      // Pointer to the board so the human can ask the board whether
	                   // the human can move to a given location on the board.
};

/**
 * @class WillSmith
 * @brief The willSmith class declaration. WillSmith inherits from the Human class
 */
class willSmith : public Human {
public:
    willSmith(int initRow, int initCol, bool initInfected, Board* thisBoard, bool dead);
    virtual bool isInfected(); //Always false because Will Smith cannot be infected
    virtual void draw(); //draws Will Smith in blue
    virtual void move(); //Will Smill
	virtual void setLocation(int row, int col);
    virtual void setDeath();
};

class BadGuy : public Human {
public:
    BadGuy(int initRow, int initCol, bool initInfected, Board* thisBoard, bool dead);
    virtual void draw();
	virtual void move();
	virtual void setLocation(int row, int col);
    virtual void setDeath();
    virtual void setTerminated();
    virtual bool isTerminated();

protected:
    bool terminated;

};

class dog : public Human {
public:
    dog(int initRow, int initCol, bool initInfected, Board* thisBoard, bool dead);
    virtual void draw();
   	virtual void move();
    virtual bool isInfected();
    virtual void setLocation(int row, int col);
    virtual void setDeath();
    virtual void setTerminated();
    virtual bool isTerminated();

protected:
    bool terminated;
};

#endif // HUMAN_H
