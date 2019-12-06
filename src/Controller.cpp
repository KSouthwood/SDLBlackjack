//
// Created by Keri Southwood-Smith on 9/20/19.
//

#include "Controller.h"

Controller::Controller() {
    std::cout << "Controller()\n";
}

/******************
 *  Summary: Initialize the game
 *
 *  Description: Initialize the game by calling the appropriate set-up routines
 *      for the renderer, then loading the textures and creating the shoe if
 *      the renderer loaded without error.
 *
 *  Parameter(s):
 *      N/A
 */
bool Controller::GameInit() {
    std::cout << "GameInit()\n";
    if (rend.InitRenderer()) {
        rend.LoadTexturesFromDisk();
        deck.CreateShoe();
    }
    return rend.is_valid;
}

/******************
 *  Summary: Game loop
 *
 *  Description: Loop that controls the flow of the game and keeps going until the player
 *      decides to quit.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::GameLoop() {
    std::cout << "GameLoop()\n";
    bool game_quit = false;

    while (!game_quit) {
        for (int i = 0; i < 10; ++i) {
            if (deck.shuffle) {
                deck.ShuffleCards();
            }
            ClearHands();
            rend.RenderTable();
            DealHands();
            PlayPlayerHand();
            PlayDealerHand();
            WhoWon();
//            SDL_RenderPresent(rend.renderer);
            SDL_Delay(2000);
        }
        game_quit = true;
    }
}

/******************
 *  Summary: Set hands to initial values
 *
 *  Description: Set the player and dealer hands to initial values for starting play. Set score to 0
 *      and ensure the vector of Cards is empty.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::ClearHands() {
    std::cout << "ClearHands()\n";

    // re-set scores to 0
    player.score = 0;
    dealer.score = 0;

    // clear vectors
    player.cards.clear();
    dealer.cards.clear();
}

/******************
 *  Summary: Deals initial cards
 *
 *  Description: Deal the initial cards to the player and the dealer.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::DealHands() {
    for (int i = 0; i < 2; ++i) {
        deck.DealCard(player.cards);
        player.score = DeckOfCards::ScoreHand(player.cards);
        rend.RenderHand(false, player.cards);

        deck.DealCard(dealer.cards);
        dealer.score = DeckOfCards::ScoreHand(dealer.cards);
        if (i == 0) {
            dealer.cards.front().faceup = false;
        }
        rend.RenderHand(true, dealer.cards);
    }
}

/******************
 *  Summary: Have the player play their hand
 *
 *  Description: Have the player play their hand by asking them if they want to hit or stand.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::PlayPlayerHand() {
    bool stand = false;
    CHOICES choice = NONE;

    while (!stand) {
        choice = Helpers::GetChoice();

        if (choice == HIT || choice == LEFT) {
            deck.DealCard(player.cards);
            player.score = DeckOfCards::ScoreHand(player.cards);
            rend.RenderHand(false, player.cards);
        }

        if ((player.score > 21) || (player.cards.size() == 5) ||
            (choice == STAND) || (choice == RIGHT)) {
            stand = true;
        }

    }
}

/******************
 *  Summary: Play the dealer's hand
 *
 *  Description: Play the dealer's hand until they've reached soft 17 or more.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::PlayDealerHand() {
    // TODO: delete temp code
    dealer.cards.front().faceup = true;
    rend.RenderHand(true, dealer.cards);

    while (dealer.score < 17) {
        deck.DealCard(dealer.cards);
        dealer.score = DeckOfCards::ScoreHand(dealer.cards);
        rend.RenderHand(true, dealer.cards);
    }
}

/******************
 *  Summary: Decide who won the hand
 *
 *  Description: Compare the player's hand to the dealer's hand to determine if they've won or not
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::WhoWon() {
    std::cout << "WhoWon()\n";
    std::string result = "lose";
    if (player.score < 22) {
        if ((player.score > dealer.score) || (dealer.score > 21)) {
            result = "win";
        } else if (player.score == dealer.score) {
            result = "push";
        }
    }
    std::cout << "Dealer: " << dealer.score << " Player: " << player.score << " Result: " << result << std::endl;
    rend.ShowWhoWon(result);
}

void Controller::CenterTexture() {

}
