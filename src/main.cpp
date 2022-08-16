#include "player.h"
#include "blackjack.h"
#include <iostream>


int main() {
	bool game = true;
	std::cout << "*****Welcome to the Casino!*****\n";
	Player p1;
	
	while (game) {
		std::cout << "Player has $" << p1.get_dollars() << " available\n";
		std::cout << "Select the number on the list\n1.Blackjack\n2.Deposit Funds\n3.Withdraw Funds\n"
			"4.Game Results\n5.Exit Game\n";
		int game_decision;
		std::cin >> game_decision;
		if (game_decision == 1) {
			bool gameCont = true;
			while (gameCont) {
				
				Blackjack game;
				std::cout << "You currently have " << p1.get_dollars() << " dollars available.\n";
				std::cout << "How much would you like to bet?" << std::endl;
				int betAmt = 0;
				std::cin >> betAmt;
				while (betAmt > p1.get_dollars() || p1.get_dollars() <= 0) {
					if (betAmt > p1.get_dollars()) {
						std::cout << "You do not have enough funds to place that wager. Please enter again." << std::endl;
					}
					//this kicks the player out of the game to deposit funds
					if (p1.get_dollars() < 1) {
						std::cout << "You do not have any funds available. Deposit funds to continue to play." << std::endl;
						gameCont = false;
						break;
					}
					std::cin >> betAmt;
				}
				if (betAmt > 0 && p1.get_dollars() != 0) {
					p1.played();
					p1.withdraw_dollars(betAmt);
					game.changeBetAmt(betAmt);
					game.deal();
					char blackjackDecision = ' ';
					std::cout << "Press H for Hit, S for Stand" << std::endl;
					std::cin >> blackjackDecision;
					//player hits
					while (blackjackDecision == 'H' || blackjackDecision == 'h') {
						game.hit();
						if (!game.bustStatus() && (blackjackDecision == 'H' || blackjackDecision == 'h')) {
							std::cout << "Press H for Hit, S for Stand" << std::endl;
							std::cin >> blackjackDecision;
						}
						else if(!game.bustStatus() && (blackjackDecision != 'H' || blackjackDecision != 'h')) {
							game.stand();
						}
						else {
							break;
						}
					}
					//if player wants to stand instead of hit
					if (blackjackDecision == 'S' || blackjackDecision == 's') {
						game.stand();
					}
					//runs if player wins hand
					if (game.wonStatus()) {
						game.calcWonAmt();
						p1.deposit_dollars(game.getWonAmt());
						p1.won();
					}
					std::cout << "Would you like to play again? Y for yes, N for no" << std::endl;
					char blackjackCont = ' ';
					std::cin >> blackjackCont;
					if (blackjackCont != 'y' && blackjackCont != 'Y') {
						gameCont = false;
					}
				}
				
			}
		}
		if (game_decision == 2) {
			int dollars;
			std::cout << "Enter amount to deposit\n";
			std::cin >> dollars;
			p1.deposit_dollars(dollars);
		}
		if (game_decision == 3) {
			int dollars;
			std::cout << "Enter amount to withtdraw\n";
			std::cin >> dollars;
			p1.withdraw_dollars(dollars);
		}
		if (game_decision == 4) {
			p1.game_record();
			std::cout << "\n\n";
		}
		if (game_decision == 5) {
			game = false;
		}
	}
	return 0;
}