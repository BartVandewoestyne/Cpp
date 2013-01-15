#include "AppSettings.h"
#include "tinyxml.h"

void AppSettings::save(const char* pFilename)
{
  TiXmlDocument doc;  
  TiXmlElement* msg;
  TiXmlComment * comment;
  string s;
  TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
  doc.LinkEndChild( decl ); 
 
  TiXmlElement * root = new TiXmlElement(m_name.c_str());  
  doc.LinkEndChild( root );  

  comment = new TiXmlComment();
  s=" Settings for "+m_name+" ";
  comment->SetValue(s.c_str());  
  root->LinkEndChild( comment );  

  // block: messages
  {
    MessageMap::iterator iter;

    TiXmlElement * msgs = new TiXmlElement( "Messages" );  
    root->LinkEndChild( msgs );  
 
    for (iter=m_messages.begin(); iter != m_messages.end(); iter++)
    {
      const string & key=(*iter).first;
      const string & value=(*iter).second;
      msg = new TiXmlElement(key.c_str());  
      msg->LinkEndChild( new TiXmlText(value.c_str()));  
      msgs->LinkEndChild( msg );  
    }
  }

  // block: windows
  {
    TiXmlElement * windowsNode = new TiXmlElement( "Windows" );  
    root->LinkEndChild( windowsNode );  

    list<WindowSettings>::iterator iter;

    for (iter=m_windows.begin(); iter != m_windows.end(); iter++)
    {
      const WindowSettings& w=*iter;

      TiXmlElement * window;
      window = new TiXmlElement( "Window" );  
      windowsNode->LinkEndChild( window );  
      window->SetAttribute("name", w.name.c_str());
      window->SetAttribute("x", w.x);
      window->SetAttribute("y", w.y);
      window->SetAttribute("w", w.w);
      window->SetAttribute("h", w.h);
    }
  }

  // block: connection
  {
    TiXmlElement * cxn = new TiXmlElement( "Connection" );  
    root->LinkEndChild( cxn );  
    cxn->SetAttribute("ip", m_connection.ip.c_str());
    cxn->SetDoubleAttribute("timeout", m_connection.timeout); 
  }

  doc.SaveFile(pFilename);  
}


void AppSettings::load(const char* pFilename)
{
  TiXmlDocument doc(pFilename);
  if (!doc.LoadFile()) return;

  TiXmlHandle hDoc(&doc);
  TiXmlElement* pElem;
  TiXmlHandle hRoot(0);

  // block: name
  {
    pElem=hDoc.FirstChildElement().Element();
    // should always have a valid root but handle gracefully if it does
    if (!pElem) return;
    m_name=pElem->Value();

    // save this for later
    hRoot=TiXmlHandle(pElem);
  }

  // block: string table
  {
    m_messages.clear(); // trash existing table

    pElem=hRoot.FirstChild( "Messages" ).FirstChild().Element();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
      const char *pKey=pElem->Value();
      const char *pText=pElem->GetText();
      if (pKey && pText) 
      {
        m_messages[pKey]=pText;
      }
    }
  }

  // block: windows
  {
    m_windows.clear(); // trash existing list

    TiXmlElement* pWindowNode=hRoot.FirstChild( "Windows" ).FirstChild().Element();
    for( pWindowNode; pWindowNode; pWindowNode=pWindowNode->NextSiblingElement())
    {
      WindowSettings w;
      const char *pName=pWindowNode->Attribute("name");
      if (pName) w.name=pName;
      
      pWindowNode->QueryIntAttribute("x", &w.x); // If this fails, original value is left as-is
      pWindowNode->QueryIntAttribute("y", &w.y);
      pWindowNode->QueryIntAttribute("w", &w.w);
      pWindowNode->QueryIntAttribute("hh", &w.h);

      m_windows.push_back(w);
    }
  }

  // block: connection
  {
    pElem=hRoot.FirstChild("Connection").Element();
    if (pElem)
    {
      m_connection.ip=pElem->Attribute("ip");
      pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
    }
  }
}
