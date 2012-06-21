/* The const at the end of a member function tells whether this member
   function changes the this object or not. */

class Person {

  public:
    Person( int age_in );
    int getAge() const;		// A read-only function.
    void setAge( int age_in );	// A write function.  Can't be const.
  
  private:
    int age;

};

Person::Person(int age_in)
{
  age = age_in;
}

int Person::getAge() const
{
   return age;        // Doesn't modify anything, so better to put const behind it.
}


void Person::setAge( int age_in )
{
   age = age_in;          // Modifies data member
}


int main()
{
   Person myBrother( 28 );
   const Person myMother( 64 );

   myBrother.getAge();     // Okay
   myBrother.setAge( 4 );  // Okay

   myMother.getAge();     // Okay
   //myMother.setAge( 4 );  // Error

}

