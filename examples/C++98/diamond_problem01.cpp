/**
 * Example illustrating the Diamond Problem.
 *
 * References:
 *
 *   [1] http://www.programmerinterview.com/index.php/c-cplusplus/diamond-problem/
 */

class Animal
{
public:
    int getWeight() { return weight; };

private:
    int weight;
};


// Comment out the two 'virtual's here to see the compiler error.
class Tiger : virtual public Animal { /* ... */ };
class Lion : virtual public Animal { /* ... */ };
						
class Liger : public Tiger, public Lion { /* ... */ };


int main( )
{
    Liger lg ;
    
    int weight = lg.getWeight();  // compiler error: request for
                                  // member ‘getWeight’ is ambiguous
}
