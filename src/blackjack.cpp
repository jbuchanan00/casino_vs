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
	std::cout << "\nDealer shown card is: " << dealer_cards.at(0) << std::endl;
}

void Blackjack::hit() {

}

void Blackjack::stand() {

}