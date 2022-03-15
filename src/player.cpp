#include "player.h"
#include <iostream>

Player::Player() {
	dollars_ = 0;
	wins_ = 0;
	games_played_ = 0;
}

Player::~Player(){}

void Player::deposit_dollars(int dollars) {
	dollars_ += dollars;
}

void Player::withdraw_dollars(int dollars) {
	if (dollars_ - dollars < 0) {
		std::cout << "Non-sufficient funds" << std::endl;
		return;
	}
	dollars_ -= dollars;
}

void Player::won() {
	wins_++;
}

void Player::played() {
	games_played_++;
}

void Player::game_record() {
	std::cout << "Wins: " << get_wins() << std::endl;
	std::cout << "Games Played: " << get_games_played() << std::endl;
	if (get_games_played() == 0) {
		std::cout << "Winning Percentage: 0%";
	}
	else {
		std::cout << "Winning Percentage: " << get_wins() / get_games_played() << "%" << std::endl;
	}
}