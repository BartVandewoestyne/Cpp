class Lottery {
public:
  virtual int draw();
};

class GraphicalObject {
public:
  virtual int draw();
};
 
class LotterySimulation: public Lottery,
                         public GraphicalObject {
                               // doesn't declare draw
};

class SpecialLotterySimulation: public LotterySimulation {
public:
  virtual int draw();
};


int main()
{
  LotterySimulation *pls = new LotterySimulation;
  //pls = new SpecialLotterySimulation;

  pls->draw();                   // error! ambiguous
  pls->Lottery::draw();          // fine
  pls->GraphicalObject::draw();  // fine
}
