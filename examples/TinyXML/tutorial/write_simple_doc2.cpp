/**
 * Compile with:
 *
 *   g++ write_simple_doc2.cpp -ltinyxml
 *
 */

#include "tinyxml.h"

void write_simple_doc2( )
{
  // same as write_simple_doc1 but add each node
  // as early as possible into the tree.

  TiXmlDocument doc;
  TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
  doc.LinkEndChild( decl );
  
  TiXmlElement * element = new TiXmlElement( "Hello" );
  doc.LinkEndChild( element );
  
  TiXmlText * text = new TiXmlText( "World" );
  element->LinkEndChild( text );
  
  doc.SaveFile( "madeByHand2.xml" );
}

int main()
{
  write_simple_doc2();
}
