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
				game.deal();
				char blackjackDecision = ' ';
				std::cout << "Press H for Hit, S for Stand" << std::endl;
				std::cin >> blackjackDecision;
				while (blackjackDecision == 'H' || blackjackDecision == 'h') {
					game.hit();
					if (!game.bustStatus()) {
						std::cout << "Press H for Hit, S for Stand" << std::endl;
						std::cin >> blackjackDecision;
					}
					else {
						break;
					}
				}
				game.stand();
				std::cout << "Would you like to play again? Y for yes, N for no" << std::endl;
				char blackjackCont = ' ';
				std::cin >> blackjackCont;
				if (blackjackCont != 'y' && blackjackCont != 'Y') {
					gameCont = false;
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