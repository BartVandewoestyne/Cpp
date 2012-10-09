/**
 * TODO: implement the other examples.
 */

class Lottery {
public:
  virtual int draw();
};

class GraphicalObject {
public:
  virtual int draw();
};

class AuxLottery: public Lottery {
public:
  virtual int lotteryDraw() = 0;
  virtual int draw() { return lotteryDraw(); }
};

class AuxGraphicalObject: public GraphicalObject {
public:
  virtual int graphicalObjectDraw() = 0;
  virtual int draw() { return graphicalObjectDraw(); }
};


class LotterySimulation: public AuxLottery,
                         public AuxGraphicalObject {
public:
  virtual int lotteryDraw();
  virtual int graphicalObjectDraw();
};


int main()
{
  LotterySimulation *pls = new LotterySimulation;

  Lottery *pl = pls;
  GraphicalObject *pgo = pls;

  // this calls LotterySimulation::lotteryDraw
  pl->draw();
  // this calls LotterySimulation::graphicalObjectDraw
  pgo->draw();
}
