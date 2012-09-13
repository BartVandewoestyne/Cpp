class AWOV {                // AWOV = "Abstract w/o
                            // Virtuals"
public:
  virtual ~AWOV() = 0;      // declare pure virtual
                            // destructor
};

AWOV::~AWOV() {}           // definition of pure
                           // virtual destructor
