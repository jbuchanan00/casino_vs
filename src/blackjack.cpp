#include "blackjack.h"
#include <iostream>
#include <vector>
//#include <cstdlib>

Blackjack::Blackjack() {
	std::cout << "Welcome to Blackjack" << std::endl;
	for (int i = 0; i < 52; i++) {
		available_cards.push_back(deck[i]);
	}
	changeBetAmt(0);
	changeWonStatus(false);
	changeBustStatus(false);
}

//deal out the first set of cards, only two for both the dealer and player.
void Blackjack::deal() {
	changeBustStatus(false);
	changeWonStatus(false);
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			player_cards.push_back(drawCard());
		}
		else {
			dealer_cards.push_back(drawCard());
		}
	}
	std::cout << "Your cards are: " << player_cards.at(0) << " " << player_cards.at(1);
	int playerVal = getValue(player_cards);
	std::cout << "\nYour cards value is: " << playerVal << std::endl;
	std::cout << "\nDealer shown card is: " << dealer_cards.at(0) << std::endl;
}


void Blackjack::hit() {
	player_cards.push_back(drawCard());
	int cardVal = getValue(player_cards);
	std::cout << "Your cards are now";
	for (std::string x : player_cards) {
		std::cout << " " << x;
	}
	std::cout << std::endl;
	if (cardVal > 21) {
		std::cout << "You busted with " << cardVal << ". Better luck next time." << std::endl;
		changeBustStatus(true);
		return;
	}
	else if (cardVal < 22) {
		std::cout << "Your card value is now: " << cardVal << std::endl;
	}

}

//when player stands want the dealer to draw cards until hard 17 or greater
//hard 17 is 17 without an ace card
//player wins when: dealer lower, dealer busts.
//dealer wins when: player lower, player busted (taken care of in hit method)
//if player and dealer tie w/o bust player refunded bet
void Blackjack::stand() {
	int dealerVal = getValue(dealer_cards);
	int playerVal = getValue(player_cards);
	std::cout << "Dealer Cards: " << dealer_cards.at(0) << " " << dealer_cards.at(1);
	int i = 2;
	while (dealerVal < 17) {
		dealer_cards.push_back(drawCard());
		std::cout << " " << dealer_cards.at(i);
		i++;
		dealerVal = getValue(dealer_cards);
	}
	if(dealerVal <= 21){
		if (dealerVal < getValue(player_cards)) {
			changeWonStatus(true);
		}
		else if (dealerVal == playerVal) {
			changeWonStatus(false);
		}
		std::cout << "\nDealer value is " << dealerVal << std::endl;
	}
	else if (dealerVal > 21 && playerVal < 22) {
		changeWonStatus(true);
		std::cout << "\nDealer value is " << dealerVal << ". Dealer busts.\n";
	}
}

//give the value of the cards in numeric form
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
			cardNum = "11";
		}
		intVector.push_back(std::stoi(cardNum));
	}
	int sum = 0;
	for (int x : intVector) {
		sum += x;
	}
	//this is to check if an ace valued at 11 is causing a bust, changing ace value to 1 if it is
	while (sum > 21 || sum == 0) {
		sum = 0;
		for (int x : intVector) {
			sum += x;
		}
		for (int i = 0; i < intVector.size(); i++) {
			if(intVector.at(i) == 11){
				intVector.at(i) = 1;
				sum = 0;
			}
		}
		if (sum != 0) {
			break;
		}
	}

	return sum;
}

//draw card from deck and remove card from deck to avoid duplicates
std::string Blackjack::drawCard() {
	srand(time(0));
	int card_index = 0;
	card_index = std::rand() % available_cards.size();
	std::string card = available_cards.at(card_index);
	available_cards.erase(available_cards.begin() + card_index);
	return card;
}

bool Blackjack::bustStatus() {
	return player_bust_;
}

void Blackjack::changeBustStatus(bool status) {
	player_bust_ = status;
}

void Blackjack::changeWonStatus(bool status) {
	game_won_ = status;
}

bool Blackjack::wonStatus() {
	return game_won_;
}

void Blackjack::changeBetAmt(int amt) {
	bet_amt_ = amt;
}

int Blackjack::getBetAmt() {
	return bet_amt_;
}
//payout for blackjack is 1.5x bet amount
void Blackjack::calcWonAmt() {
	int playerVal = getValue(player_cards);
	int dealerVal = getValue(dealer_cards);
	//if player is higher than dealer without bust or dealer busted and player didn't
	if ((playerVal > dealerVal || dealerVal > 21) && !bustStatus()) {
		if (player_cards.size() == 2 && getValue(player_cards) == 21) {
			amt_won_ = bet_amt_ + (bet_amt_ * 1.5);
		}
		else {
			amt_won_ = bet_amt_ * 2;
		}
	}
	//if dealer has higher than player w/o bust. if player busts.
	else if ((dealerVal > playerVal && dealerVal < 22) || bustStatus()) {
		amt_won_ = 0;
	}
	else {
		amt_won_ = bet_amt_;
	}
	
}

int Blackjack::getWonAmt() {
	return amt_won_;
}

