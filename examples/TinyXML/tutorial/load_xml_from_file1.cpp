#include "tinyxml.h"

int main()
{
    TiXmlDocument doc( "demo.xml" );
    doc.LoadFile();
}
