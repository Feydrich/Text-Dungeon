
// ******************************************************************************************* //
//                                                                                           
//                                     XML Data Binding                                      
//                                                                                           
//         Generated on: 6/1/2020 1:21:38 AM                                                 
//       Generated from: C:\Users\Bassie\Desktop\TextDungeon1.0\Projekt\playerSettings.xml   
//   Settings stored in: C:\Users\Bassie\Desktop\TextDungeon1.0\Projekt\playerSettings.xdb   
//                                                                                           
// ******************************************************************************************* //

#ifndef   playerSettingsH
#define   playerSettingsH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLplayerType;
typedef System::DelphiInterface<IXMLplayerType> _di_IXMLplayerType;

// IXMLplayerType 

__interface INTERFACE_UUID("{B16059AA-DBCF-4C4C-9C01-4E483AD8FD4C}") IXMLplayerType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual double __fastcall Get_health() = 0;
  virtual System::UnicodeString __fastcall Get_dex() = 0;
  virtual System::UnicodeString __fastcall Get_stregth() = 0;
  virtual System::UnicodeString __fastcall Get_poruka() = 0;
  virtual void __fastcall Set_health(double Value) = 0;
  virtual void __fastcall Set_dex(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_stregth(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_poruka(System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property double health = { read=Get_health, write=Set_health };
  __property System::UnicodeString dex = { read=Get_dex, write=Set_dex };
  __property System::UnicodeString stregth = { read=Get_stregth, write=Set_stregth };
  __property System::UnicodeString poruka = { read=Get_poruka, write=Set_poruka };
};

// Forward Decls 

class TXMLplayerType;

// TXMLplayerType 

class TXMLplayerType : public Xml::Xmldoc::TXMLNode, public IXMLplayerType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLplayerType 
  virtual double __fastcall Get_health();
  virtual System::UnicodeString __fastcall Get_dex();
  virtual System::UnicodeString __fastcall Get_stregth();
  virtual System::UnicodeString __fastcall Get_poruka();
  virtual void __fastcall Set_health(double Value);
  virtual void __fastcall Set_dex(System::UnicodeString Value);
  virtual void __fastcall Set_stregth(System::UnicodeString Value);
  virtual void __fastcall Set_poruka(System::UnicodeString Value);
};

// Global Functions 

_di_IXMLplayerType __fastcall Getplayer(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLplayerType __fastcall Getplayer(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLplayerType __fastcall Loadplayer(const System::UnicodeString& FileName);
_di_IXMLplayerType __fastcall  Newplayer();

#define TargetNamespace ""

#endif