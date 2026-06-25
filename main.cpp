#include <iostream>
using namespace std;

// Types of position
const int DOUBLE  = 0;  // double or roll?
const int ROLL    = 1;  // position before dice are rolled
const int TAKE    = 2;  // take or drop?
const int CHECKER = 3;  // which checker move?

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
    int plrAway = 0;
    int oppAway = 0;

    //1 means centered, 2 means plr owns, -2 means opp owns
    int cube = 1;

    //How many checkers are on each board point
    //(Opponent's checkers are negative)
    int checkers[24];

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
    bool opener = false;

    void display() {
        cout << "I am a backgammon position.";
    }
};

int main() {
    cout << "Hello, world!";

    return 0;
}