/**
 * Compile with:
 *
 *   g++ get_all_attributes.cpp -ltinyxml
 *
 */

#include "tinyxml.h"

const unsigned int NUM_INDENTS_PER_SPACE=2;

const char * getIndent( unsigned int numIndents )
{
  static const char * pINDENT="                                      + ";
  static const unsigned int LENGTH=strlen( pINDENT );
  unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
  if ( n > LENGTH ) n = LENGTH;

  return &pINDENT[ LENGTH-n ];
}

// print all attributes of pElement.
// returns the number of attributes printed
int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent)
{
  if ( !pElement ) return 0;

  TiXmlAttribute* pAttrib=pElement->FirstAttribute();
  int i=0;
  int ival;
  double dval;
  const char* pIndent=getIndent(indent);
  printf("\n");
  while (pAttrib)
  {
    printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value());

    if (pAttrib->QueryIntValue(&ival)==TIXML_SUCCESS)    printf( " int=%d", ival);
    if (pAttrib->QueryDoubleValue(&dval)==TIXML_SUCCESS) printf( " d=%1.1f", dval);
    printf( "\n" );
    i++;
    pAttrib=pAttrib->Next();
  }
  return i;
}

void write_attributes( )
{
  TiXmlDocument doc;

  TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
  doc.LinkEndChild( decl );
  
  TiXmlElement * window;
  window = new TiXmlElement( "Window" );  
  window->SetAttribute("name", "MainFrame");
  window->SetAttribute("x", 5);
  window->SetAttribute("y", 15);
  window->SetAttribute("w", 400);
  window->SetAttribute("h", 250);
  doc.LinkEndChild( window );

  dump_attribs_to_stdout(window, 1);
}

int main()
{
  write_attributes();
}
