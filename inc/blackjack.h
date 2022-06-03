#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <array>
#include <string>
#include <vector>

class Blackjack {
private:
    std::string deck[52] = {"hA", "hK", "hQ", "hJ",
                            "h10", "h9", "h8", "h7",
                            "h6", "h5", "h4", "h3",
                            "h2", "dA", "dK",
                            "dQ", "dJ","d10", "d9",
                            "d8", "d7","d6", "d5",
                            "d4", "d3","d2",
                            "cA", "cK", "cQ", "cJ",
                            "c10", "c9", "c8", "c7",
                            "c6", "c5", "c4", "c3",
                            "c2", "sA", "sK",
                            "sQ", "sJ", "s10", "s9",
                            "s8", "s7", "s6", "s5",
                            "s4", "s3", "s2" };
    bool player_bust_;
protected:
    std::vector<std::string> player_cards;
    std::vector<std::string> dealer_cards;
    std::vector<std::string> available_cards;
    int getValue(std::vector<std::string>);
    std::string drawCard();
public:
    Blackjack();
    ~Blackjack() {}
    void deal();
    void hit();
    void stand();
    bool bustStatus();
    void changeBustStatus(bool);
};


#endif