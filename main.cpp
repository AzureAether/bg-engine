#include <iostream>
using namespace std;

// Types of position
const int DOUBLE  = 0;  // double or roll?
const int ROLL    = 1;  // position before dice are rolled
const int TAKE    = 2;  // take or drop?
const int CHECKER = 3;  // which checker move?

// Useful board
const int OPENER_BOARD[24] = {-2,0,0,0,0,5,0,3,0,0,0,-5,5,0,0,0,-3,0,-5,0,0,0,0,2};

/* This class represents backgammon game states.
 *
 * The kinds of states include:
 * - Cube or Roll decisions
 * - Take or Drop decisions
 * - Checker play decisions
 * - Rolling (IE the position immediately before rolling)
 *
 * A position is described by:
 * - match score (0a-0a for a money game)
 * - checker position
 * - cube position
 * - decision
 *
 */
class Pos {
public:
    //How many points is plr/opp away from winning the match?
    int plrAway = 1;
    int oppAway = 1;

    //1 means centered, 2 means plr owns, -2 means opp owns
    int cube = 1;

    //How many checkers are on each board point
    //(Opponent's checkers are negative)
    int checkers[24] = {-2,0,0,0,0,5,0,3,0,0,0,-5,5,0,0,0,-3,0,-5,0,0,0,0,2};

    /* Is the game state:
     * - a DOUBLE/Roll decision?
     * - a TAKE/Drop decision?
     * - a CHECKER decision?
     * - a probabilistic ROLL node 
     */
    int decision = ROLL;

    //Value on the dice (if a Checker decision)
    int dice[2];

    //Is this the opening roll?
    bool opener = true;

    //Rules
    bool crawfordRule = true;
    bool crawfordGame = true; //Is the Crawford rule in effect in this position?
    bool jacobyRule = true;

    Pos() {
        
    }

    void display() {
        //Cube info
        if(cube > 1){cout << "O holds the " << cube << "cube\n\n";}
        else if(cube < 1){cout << "X holds the " << -cube << "cube\n\n";}
        else{cout << "The cube is centered.\n\n";}

        //Match score info
        cout << "O is " << plrAway << " away\n";
        cout << "X is " << oppAway << " away\n\n";

        //Rule info
        if(plrAway > 1 || oppAway > 1){
            if(crawfordGame){cout << "This is a Crawford game (no cube).";}
            else{cout << "The Crawford rule applies to this match.";}
        } else if (plrAway == 0 && oppAway == 0) {
            if(jacobyRule){cout << "This is a cash game with the Jacoby rule (no undoubled gammons)";}
            else{cout << "This is a cash game.";}
        }

        int height = 0;

        for(int i = 0; i < 24; i++){
            if(abs(checkers[i]) > height){height = abs(checkers[i]);}
        }
        
        for(int y = height; y > 0; y--){
            for(int x = 0; x < 24; x++){
                if(abs(checkers[x]) >= y){
                    if(checkers[x] > 0){cout << " O ";}
                    else{cout << " X ";}
                } else {cout << "   ";}
            }
            cout << "\n";
        }
        cout << "========================================================================\n";
        cout << " 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24\n";
    }
};

int main() {
    Pos p;
    p.display();

    return 0;
}