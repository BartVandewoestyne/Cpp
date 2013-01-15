/**
 * Compile with:
 *
 *   g++ build_simple_doc.cpp -ltinyxml
 *
 */

#include "tinyxml.h"

void build_simple_doc( )
{
  // Make xml: <?xml ..><Hello>World</Hello>
  TiXmlDocument doc;
  TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
  TiXmlElement * element = new TiXmlElement( "Hello" );
  TiXmlText * text = new TiXmlText( "World" );
  element->LinkEndChild( text );
  doc.LinkEndChild( decl );
  doc.LinkEndChild( element );
  doc.SaveFile( "madeByHand.xml" );
}

int main()
{
  build_simple_doc();
}
