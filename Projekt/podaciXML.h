
// ***************************************************************************************************************** //
//                                                                                                                 
//                                                XML Data Binding                                                 
//                                                                                                                 
//         Generated on: 5/24/2020 3:53:03 PM                                                                      
//       Generated from: C:\Users\Bassie\Desktop\TextDungeon0.1\TextDungeon0.1\Projekt\Win32\Debug\podaciXML.xml   
//   Settings stored in: C:\Users\Bassie\Desktop\TextDungeon0.1\TextDungeon0.1\Projekt\Win32\Debug\podaciXML.xdb   
//                                                                                                                 
// ***************************************************************************************************************** //

#ifndef   podaciXMLH
#define   podaciXMLH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLpodaciType;
typedef System::DelphiInterface<IXMLpodaciType> _di_IXMLpodaciType;
__interface IXMLUserType;
typedef System::DelphiInterface<IXMLUserType> _di_IXMLUserType;

// IXMLpodaciType 

__interface INTERFACE_UUID("{68D1AAF3-47C3-4707-BBAF-28C3AF090C83}") IXMLpodaciType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLUserType __fastcall Get_User(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLUserType __fastcall Add() = 0;
  virtual _di_IXMLUserType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLUserType User[int Index] = { read=Get_User };/* default */
};

// IXMLUserType 

__interface INTERFACE_UUID("{A26FBF1F-B29D-4E23-AA38-9FE1ACC8C5A4}") IXMLUserType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_name() = 0;
  virtual System::UnicodeString __fastcall Get_password() = 0;
  virtual System::UnicodeString __fastcall Get_ip() = 0;
  virtual void __fastcall Set_name(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_password(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_ip(System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString name = { read=Get_name, write=Set_name };
  __property System::UnicodeString password = { read=Get_password, write=Set_password };
  __property System::UnicodeString ip = { read=Get_ip, write=Set_ip };
};

// Forward Decls 

class TXMLpodaciType;
class TXMLUserType;

// TXMLpodaciType 

class TXMLpodaciType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLpodaciType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLpodaciType 
  virtual _di_IXMLUserType __fastcall Get_User(int Index);
  virtual _di_IXMLUserType __fastcall Add();
  virtual _di_IXMLUserType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLUserType 

class TXMLUserType : public Xml::Xmldoc::TXMLNode, public IXMLUserType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLUserType 
  virtual System::UnicodeString __fastcall Get_name();
  virtual System::UnicodeString __fastcall Get_password();
  virtual System::UnicodeString __fastcall Get_ip();
  virtual void __fastcall Set_name(System::UnicodeString Value);
  virtual void __fastcall Set_password(System::UnicodeString Value);
  virtual void __fastcall Set_ip(System::UnicodeString Value);
};

// Global Functions 

_di_IXMLpodaciType __fastcall Getpodaci(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLpodaciType __fastcall Getpodaci(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLpodaciType __fastcall Loadpodaci(const System::UnicodeString& FileName);
_di_IXMLpodaciType __fastcall  Newpodaci();

#define TargetNamespace ""

#endif