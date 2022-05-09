#include "blackjack.h"
#include <iostream>
#include <vector>

Blackjack::Blackjack() {
	std::cout << "Welcome to Blackjack" << std::endl;
	for (int i = 0; i < 52; i++) {
		available_cards.push_back(deck[i]);
	}
}

//deal out the first set of cards, only two for dealer and two for player.
void Blackjack::deal() {
	int card_index = 0;
	for (int i = 0; i < 4; i++) {
		card_index = std::rand() % available_cards.size();
		if (i % 2 == 0) {
			player_cards.push_back(available_cards.at(card_index));
		}
		else {
			dealer_cards.push_back(available_cards.at(card_index));
		}
		available_cards.erase(available_cards.begin() + card_index);
	}
	std::cout << "Your cards are: " << player_cards.at(0) << " " << player_cards.at(1);
	int playerVal = getValue(player_cards);
	std::cout << "\nYour cards value is: " << playerVal << std::endl;
	std::cout << "\nDealer shown card is: " << dealer_cards.at(0) << std::endl;
}

void Blackjack::hit() {

}

void Blackjack::stand() {

}

int Blackjack::getValue(std::vector<std::string> valVector) {
	std::vector<int> intVector;
	for (std::string x : valVector) {
		std::string cardNum = "";
		if (x.size() == 3) {
			cardNum = x.substr(1, 3);
		}
		else if (x.size() == 2) {
			cardNum = x.substr(1, 2);
		}
		if (cardNum == "K" || cardNum == "Q" || cardNum == "J") {
			cardNum = "10";
		}
		else if (cardNum == "A") {
			if (std::stoi(cardNum) < 11) {
				cardNum = "11";
			}
			else {
				cardNum = "1";
			}
		}
		intVector.push_back(std::stoi(cardNum));
	}
	int sum = 0;
	for (int x : intVector) {
		sum += x;
	}
	return sum;
}