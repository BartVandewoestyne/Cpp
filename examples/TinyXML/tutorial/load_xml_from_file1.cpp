/**
 * Compile with:
 *
 *   g++ load_xml_from_file1.cpp -ltinyxml
 *
 */

#include <iostream>
#include <sstream>
#include "tinyxml.h"
using namespace std;

int main()
{
    TiXmlDocument doc( "demo.xml" );
    doc.LoadFile();
}
