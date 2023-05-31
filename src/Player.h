#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class Player : public Person // la clase Player hereda con ambito publico de la clase Person
{
    int playerNum;
    int position;
public:
    Player() {};
    Player(const string &name, const int &playerNum, const int &position) : Person(name), playerNum(playerNum), position(position) {}; 
    ~Player() {};
    // Getters
    int getPlayerNum();
    int getPosition();
    // Setters
    void setPlayerNum(int);
    void setPosition(int);
};

int Player::getPlayerNum() {
    return playerNum;
}

void Player::setPlayerNum(int _playerNum) {
    playerNum = _playerNum;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int _position) {
    position = _position;
}