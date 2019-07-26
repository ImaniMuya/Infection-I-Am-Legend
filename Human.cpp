/**
 * @file Human.cpp
 * @brief The Human class implementation file.
 *
 * -- Enter the correct information below, then remove this line.
 * @author Person 1 Imani Muya
 * @author Person 2 Grace Rose
 * @date Date 11-18-2017
 */

#include <cstdlib>
#include <iostream>

#include "Human.h"
#include "conio.h"

using namespace std;

/**
 * @brief The Human class constructor.
 * This function initializes the row, col, infected, and board variables.
 *
 * @param initRow the initial human row location.
 * @param initCol the initial human column location.
 * @param initInfected whether the human is initially infected.
 * @param theBoard a pointer to the board (used to ask board whether a proposed move is ok).
 */
Human::Human(int initRow, int initCol, bool initInfected, Board* theBoard, bool dead) {
    row = initRow;
    col = initCol;

    suddenDeath = false;
    infected = initInfected;
    board = theBoard;
    dead = false;

}

/**
 * @brief The Human class destructor.
 * The Human class destructor does nothing (so far), but is here as a placeholder to remind
 * you that it is a good idea for classes to have destructors, even if you can't think of
 * work for destructor at this point.
 */
Human::~Human() {
    // Nothing to do
}

/**
 * @brief Have the human try to move.
 * To know whether it is ok to move to some position (r,c), ask the board
 * whether the position is ok. E.g., "if( board->tryMove(r,c) ) ..."
 * If the move is ok, then update the human's row and column to reflect the move.
 */
void Human::move() {
    // Generate a +/- 2 row and column delta.
    if (isDead()) return;
    int rowDelta=rand()%5-2, colDelta=rand()%5-2;

    // Ask the board whether you
    if(board->tryMove(row+rowDelta, col+colDelta)) {
	row+=rowDelta;
	col+=colDelta;
    }
}

/**
 * @brief Get the human's current row/col location.
 * Returns the human's current row/column location via the reference parameters.
 * @param[out] currentRow the human's current row
 * @param[out] currentCol the human's current column
 */
void Human::getLocation(int& currentRow, int& currentCol) {
    currentRow = row;
    currentCol = col;
}

/**
 * @brief Set the human's row/col location.
 * Sets the human's current row/column location to the parameter values.
 * @param[in] newRow the human's new row location
 * @param[in] newCol the human's new column location
 */
void Human::setLocation(int newRow, int newCol) {
    row=newRow;
    col=newCol;
}

/**
 * @brief Sets this human to be infected.
 * Sets this human object's state to infected.
 */
void Human::setInfected() {
    infected = true;
}

/**
 * @brief reports whether this human is infected.
 * @return whether this human object is infected.
 */
bool Human::isInfected() {
    return infected;
}

/**
 * @brief Draws the human.
 * Draws the human at the current row/col location on the screen.
 * Remember that the first conio row=1, and first conio col=1.
 */
void Human::draw() {
    cout << conio::gotoRowCol(row+1,col+1);
    if( infected && !dead ) {
        cout << conio::bgColor(conio::LIGHT_RED);
        cout << '#' << conio::resetAll() << flush;

    } else if (isDead()){
        cout << conio::bgColor(conio::GRAY);
        cout << 'X' << conio::resetAll() << flush;

    }
    else {
        cout << conio::bgColor(conio::LIGHT_GREEN);
        cout << '@' << conio::resetAll() << flush;

    }
}

/**
* @brief  Checks Human's Dead attribute, and returns a true or a false
*/
bool Human::isDead() {
    return dead;
}

/**
* @brief  sets Human's dead attribute to true
*/
void Human::kill() {
    dead = true;
}

/**
* @brief  Constructor for the WillSmith class, sets his initial placement to 10,40 and sets infected to
* false
*/
willSmith::willSmith(int initRow, int initCol, bool initInfected, Board* theBoard, bool dead)
: Human ( initRow,  initCol,  initInfected,  theBoard,  dead) {
    row = 10;
    col = 40;

    suddenDeath = false;
    infected = false;
    board = theBoard;

}
/**
 * @brief sets willSmith's location
 */
void willSmith::setLocation(int newRow, int newCol) {
    row=newRow;
    col=newCol;
}

/**
* @brief  always sets WillSmith's isInfected to false
*/
bool willSmith::isInfected() {
    return false;
}

/**
 * @brief Draws willSmith as a blue square with a 'W' character.
 */
void willSmith::draw() {
    cout << conio::gotoRowCol(row+1,col+1);
    cout << conio::bgColor(conio::BLUE);
    cout << 'W' << conio::resetAll() << flush;
}

/**
 * @brief allows WillSmith to move farther than normal Humans
 */
void willSmith::move() {
    int rowDelta=rand()%7-3, colDelta=rand()%7-3;

    // Ask the board whether you
    if(suddenDeath == false && board->tryMove(row+rowDelta, col+colDelta)) {
    row= row + rowDelta;
    col= col + colDelta;
    }

}

/**
 * @brief sets the suddenDeath atrribute to true, meaning all of the greens are red
 */
void willSmith::setDeath() {
    suddenDeath = true;
}

/**
 * @brief initializes BadGuy
 */
BadGuy::BadGuy(int initRow, int initCol, bool initInfected, Board* theBoard, bool dead)
: Human ( initRow,  initCol,  initInfected,  theBoard,  dead) {
    row = 1;
    col = 1;

    suddenDeath = false;
    infected = true;
    board = theBoard;
    terminated = false;
}

/**
 * @brief moves BadGuy
 */
void BadGuy::move() {
    // Generate a +/- 2 row and column delta.
    int rowDelta=rand()%5-2, colDelta=rand()%5-2;

    // Ask the board whether you
    if(suddenDeath == false && board->tryMove(row+rowDelta, col+colDelta)) {
    row= row + rowDelta;
    col= col + colDelta;
    }
    else if (suddenDeath == true) {

        col += 1;
        setLocation(row,col);
    }
}

/**
 * @brief sets BadGuys location
 */
void BadGuy::setLocation(int newRow, int newCol) {
    row=newRow;
    col=newCol;
}

/**
 * @brief draws BadGuy as a Yellow B
 */
void BadGuy::draw() {
    cout << conio::gotoRowCol(row+1,col+1);
    cout << conio::bgColor(conio::YELLOW);
    cout << 'B' << conio::resetAll() << flush;
}
/**
 * @brief sets the suddenDeath atrribute to true, meaning all of the greens are red
 */
 void BadGuy::setDeath() {
    suddenDeath = true;
}

/**
 * @brief sets the terminated atrribute to true, meaning BadGuy is dead
 */
void BadGuy::setTerminated() {
    terminated = true;
}

bool BadGuy::isTerminated() {
    if (terminated == true) return true;

    return false;
}
/**
 * @brief initializes dog
 */
dog::dog(int initRow, int initCol, bool initInfected, Board* theBoard, bool dead)
: Human ( initRow,  initCol,  initInfected,  theBoard,  dead) {
    row = 15;
    col = 40;

    suddenDeath = false;
    infected = false;
    board = theBoard;
    terminated = false;
}

/**
 * @brief sets tdog's location
 */
void dog::setLocation(int newRow, int newCol) {
    row=newRow;
    col=newCol;
}

/**
 * @brief Draws dog
 */
void dog::draw() {
    cout << conio::gotoRowCol(row+1,col+1);
    cout << conio::bgColor(conio::CYAN);
    cout << 'D' << conio::resetAll() << flush;
}

/**
 * @brief Dog's move function
 */
void dog::move() {
    // Generate a +/- 2 row and column delta.
    if (isDead()) return;
    int rowDelta=rand()%5-2, colDelta=rand()%5-2;

    // Ask the board whether you
    if(suddenDeath == false && board->tryMove(row+rowDelta, col+colDelta)) {
    row= row + rowDelta;
    col= col + colDelta;
    }
    else if (suddenDeath == true) {
        //setLocation(10,40);
        col -= 1;
    }
}
/**
 * @brief Dog cannot be infected by Zombies so this is alwasy false
 */
bool dog::isInfected() {
    return false;
}
/**
 * @brief sets the suddenDeath atrribute to true, meaning all of the greens are red
 */
void dog::setDeath() {
    suddenDeath = true;
}

/**
 * @brief sets the terminated atrribute to true, meaning dog is dead
 */
void dog::setTerminated() {
    terminated = true;
}
/**
 * @brief returns a true if Dog is terminated
 */
bool dog::isTerminated() {
    if (terminated == true) return true;

    return false;
}
