#include <string>
#include <map>
#include <list>
#include "tinyxml.h"
using namespace std;

typedef std::map<std::string,std::string> MessageMap;

// a basic window abstraction - demo purposes only
class WindowSettings
{
public:
  int x,y,w,h;
  string name;

  WindowSettings()
    : x(0), y(0), w(100), h(100), name("Untitled")
  {
  }

  WindowSettings(int x, int y, int w, int h, const string& name)
  {
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->name=name;
  }
};

class ConnectionSettings
{
public:
  string ip;
  double timeout;
};

class AppSettings
{
public:
  string m_name;
  MessageMap m_messages;
  list<WindowSettings> m_windows;
  ConnectionSettings m_connection;

  AppSettings() {}

  void save(const char* pFilename);
  void load(const char* pFilename);
  
  // just to show how to do it
  void setDemoValues()
  {
    m_name="MyApp";
    m_messages.clear();
    m_messages["Welcome"]="Welcome to "+m_name;
    m_messages["Farewell"]="Thank you for using "+m_name;
    m_windows.clear();
    m_windows.push_back(WindowSettings(15,15,400,250,"Main"));
    m_connection.ip="Unknown";
    m_connection.timeout=123.456;
  }
};


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


//int main(void)
//{
//  AppSettings settings;
//  
//  settings.setDemoValues();
//
//  settings.save("appsettings2.xml");
//  settings.load("appsettings2.xml");
//  return 0;
//}


int main(void)
{
  // block: customise and save settings
  {
    AppSettings settings;
    settings.m_name="HitchHikerApp";
    settings.m_messages["Welcome"]="Don't Panic";
    settings.m_messages["Farewell"]="Thanks for all the fish";
    settings.m_windows.push_back(WindowSettings(15,25,300,250,"BookFrame"));
    settings.m_connection.ip="192.168.0.77";
    settings.m_connection.timeout=42.0;

    settings.save("appsettings2.xml");
  }
  
  // block: load settings
  {
    AppSettings settings;
    settings.load("appsettings2.xml");
    printf("%s: %s\n", settings.m_name.c_str(), 
      settings.m_messages["Welcome"].c_str());
    WindowSettings & w=settings.m_windows.front();
    printf("%s: Show window '%s' at %d,%d (%d x %d)\n", 
      settings.m_name.c_str(), w.name.c_str(), w.x, w.y, w.w, w.h);
    printf("%s: %s\n", settings.m_name.c_str(), settings.m_messages["Farewell"].c_str());
  }
  return 0;
}
