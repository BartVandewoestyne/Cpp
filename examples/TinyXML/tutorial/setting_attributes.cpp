#include "tinyxml.h"

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

  doc.SaveFile( "attributes1.xml" );
}

int main()
{
  write_attributes();
}
