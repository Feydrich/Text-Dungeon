
// *********************************************************************************************************************************************** //
//                                                                                                                                               
//                                                               XML Data Binding                                                                
//                                                                                                                                               
//         Generated on: 28.5.2020. 14:51:12                                                                                                     
//       Generated from: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\TextDungeon0.1\Projekt\Win32\Debug\saveLoadXML.xml   
//   Settings stored in: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\TextDungeon0.1\Projekt\Win32\Debug\saveLoadXML.xdb   
//                                                                                                                                               
// *********************************************************************************************************************************************** //

#ifndef   saveLoadXMLH
#define   saveLoadXMLH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLsaveLoadType;
typedef System::DelphiInterface<IXMLsaveLoadType> _di_IXMLsaveLoadType;
__interface IXMLpositionsType;
typedef System::DelphiInterface<IXMLpositionsType> _di_IXMLpositionsType;

// IXMLsaveLoadType 

__interface INTERFACE_UUID("{37ED12DD-23E7-401E-A2C0-D5B57F2D28D2}") IXMLsaveLoadType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLpositionsType __fastcall Get_positions() = 0;
  // Methods & Properties 
  __property _di_IXMLpositionsType positions = { read=Get_positions };
};

// IXMLpositionsType 

__interface INTERFACE_UUID("{28295838-F4DE-4740-8D32-692A42E4CA11}") IXMLpositionsType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_plot(int Index) = 0;
  // Methods & Properties 
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Add(const System::UnicodeString plot) = 0;
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Insert(const int Index, const System::UnicodeString plot) = 0;
  __property System::UnicodeString plot[int Index] = { read=Get_plot };/* default */
};

// Forward Decls 

class TXMLsaveLoadType;
class TXMLpositionsType;

// TXMLsaveLoadType 

class TXMLsaveLoadType : public Xml::Xmldoc::TXMLNode, public IXMLsaveLoadType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLsaveLoadType 
  virtual _di_IXMLpositionsType __fastcall Get_positions();
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLpositionsType 

class TXMLpositionsType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLpositionsType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLpositionsType 
  virtual System::UnicodeString __fastcall Get_plot(int Index);
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Add(const System::UnicodeString plot);
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Insert(const int Index, const System::UnicodeString plot);
public:
  virtual void __fastcall AfterConstruction(void);
};

// Global Functions 

_di_IXMLsaveLoadType __fastcall GetsaveLoad(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLsaveLoadType __fastcall GetsaveLoad(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLsaveLoadType __fastcall LoadsaveLoad(const System::UnicodeString& FileName);
_di_IXMLsaveLoadType __fastcall  NewsaveLoad();

#define TargetNamespace ""

#endif