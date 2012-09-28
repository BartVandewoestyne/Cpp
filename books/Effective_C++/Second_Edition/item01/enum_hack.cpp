/**
 * Note:
 *
 *   Unless you're dealing with compilers of primarily historical interest
 *   (i.e., those written before 1995), you shouldn't have to use the enum
 *   hack.
 */

class GamePlayer {
private:
  enum { NUM_TURNS = 5 };    // "the enum hack" makes
                             // NUM_TURNS a symbolic name
                             // for 5
 
  int scores[NUM_TURNS];     // fine
};
