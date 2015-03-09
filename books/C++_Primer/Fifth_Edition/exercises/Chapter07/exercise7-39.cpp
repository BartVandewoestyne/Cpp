// No, this is not illegal, because the call to the overloaded Sales_data()
// constructor then becomes ambiguous.  Candidates then are:
//
//   Sales_data(std::istream &is = cin)
//     or
//   Sales_data(std::string s = ""): bookNo(s)
