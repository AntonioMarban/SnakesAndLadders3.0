#include <iostream>
#pragma once
using namespace std;
#include <string>

class Turn {
    int turnNumber;
    int playerNumber;
    int playerStartingPosition;
    int rolled;
    char tileType;
    int playerFinalPosition;
    public:
        Turn() = default;
        Turn(const int& turnNumber, const int& playerNumber, const int& rolled, const char& tileType, const int& playerFinalPosition) : turnNumber(turnNumber + 1), playerNumber(playerNumber), playerStartingPosition(playerFinalPosition - rolled + 1), rolled(rolled), tileType(tileType), playerFinalPosition(playerFinalPosition + 1) {}
        ~Turn();
        int getTurnNumber();
        int getPlayerNumber();
        int getPlayerstartingPosition();
        int getRolled();
        char getTileType();
        int getPlayerFinalPosition();
        void setTurnNumber(int);
        void setPlayerNumber(int);
        void setPlayerStartingPosition(int);
        void setRolled(int);
        void setTileType(char);
        void setPlayerFinalPosition(int);

};

Turn::~Turn() {}


int Turn::getTurnNumber() {return turnNumber;}
int Turn::getPlayerNumber() {return playerNumber;}
int Turn::getPlayerstartingPosition() {return playerStartingPosition;}
int Turn::getRolled() {return rolled;}
char Turn::getTileType() {return tileType;}
int Turn::getPlayerFinalPosition() {return playerFinalPosition;}

void Turn::setTurnNumber(int _turnNumber) {turnNumber = _turnNumber;}
void Turn::setPlayerNumber(int _playerNumber) {playerNumber = _playerNumber;}
void Turn::setPlayerStartingPosition(int _playerStartingPosition) {playerStartingPosition = _playerStartingPosition;}
void Turn::setRolled(int _rolled) {rolled = _rolled;}
void Turn::setTileType(char _tileType) {tileType = _tileType;}
void Turn::setPlayerFinalPosition(int _playerFinalPosition) {playerFinalPosition = _playerFinalPosition;}

ostream& operator<<(ostream&out, Turn turn) {
            out << turn.getTurnNumber() << " " << turn.getPlayerNumber() << " " << turn.getPlayerstartingPosition() << " " << turn.getRolled() << " " << turn.getTileType() << " " << turn.getPlayerFinalPosition() << endl;
            return out;
        }