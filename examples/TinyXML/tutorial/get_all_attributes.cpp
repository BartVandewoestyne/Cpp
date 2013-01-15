#include "utils.h"
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

  dump_attribs_to_stdout(window, 1);
}

int main()
{
  write_attributes();
}
