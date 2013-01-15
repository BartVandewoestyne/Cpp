#include "utils.h"
#include "tinyxml.h"

void write_app_settings_doc( )  
{  
  TiXmlDocument doc;  
  TiXmlElement* msg;
  TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
  doc.LinkEndChild( decl );  
 
  TiXmlElement * root = new TiXmlElement( "MyApp" );  
  doc.LinkEndChild( root );  

  TiXmlComment * comment = new TiXmlComment();
  comment->SetValue(" Settings for MyApp " );  
  root->LinkEndChild( comment );  
 
  TiXmlElement * msgs = new TiXmlElement( "Messages" );  
  root->LinkEndChild( msgs );  
 
  msg = new TiXmlElement( "Welcome" );  
  msg->LinkEndChild( new TiXmlText( "Welcome to MyApp" ));  
  msgs->LinkEndChild( msg );  
 
  msg = new TiXmlElement( "Farewell" );  
  msg->LinkEndChild( new TiXmlText( "Thank you for using MyApp" ));  
  msgs->LinkEndChild( msg );  
 
  TiXmlElement * windows = new TiXmlElement( "Windows" );  
  root->LinkEndChild( windows );  

  TiXmlElement * window;
  window = new TiXmlElement( "Window" );  
  windows->LinkEndChild( window );  
  window->SetAttribute("name", "MainFrame");
  window->SetAttribute("x", 5);
  window->SetAttribute("y", 15);
  window->SetAttribute("w", 400);
  window->SetAttribute("h", 250);

  TiXmlElement * cxn = new TiXmlElement( "Connection" );  
  root->LinkEndChild( cxn );  
  cxn->SetAttribute("ip", "192.168.0.1");
  cxn->SetDoubleAttribute("timeout", 123.456); // floating point attrib
  
  dump_to_stdout( &doc );
  doc.SaveFile( "appsettings.xml" );  
}


int main()
{
  write_app_settings_doc();
}
