#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player();
	~Player();
	//setters
	void withdraw_dollars(int dollars);
	void deposit_dollars(int dollars);
	void won();
	void played();
	//getters
	int get_dollars() { return dollars_; }
	int get_wins() { return wins_; }
	int get_games_played() { return games_played_; }
	void game_record();
protected:
	int dollars_;
	int wins_;
	int games_played_;
};

#endif