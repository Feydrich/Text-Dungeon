
// ******************************************************************************************************************* //
//                                                                                                                   
//                                                 XML Data Binding                                                  
//                                                                                                                   
//         Generated on: 14.5.2020. 17:40:31                                                                         
//       Generated from: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\Projekt\podaciSobe.xml   
//   Settings stored in: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\Projekt\podaciSobe.xdb   
//                                                                                                                   
// ******************************************************************************************************************* //

#ifndef   podaciSobeH
#define   podaciSobeH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLrootType;
typedef System::DelphiInterface<IXMLrootType> _di_IXMLrootType;
__interface IXMLSobeType;
typedef System::DelphiInterface<IXMLSobeType> _di_IXMLSobeType;

// IXMLrootType 

__interface INTERFACE_UUID("{259971A6-99C1-47C5-A4BF-2CC96D84D449}") IXMLrootType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLSobeType __fastcall Get_Sobe(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLSobeType __fastcall Add() = 0;
  virtual _di_IXMLSobeType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLSobeType Sobe[int Index] = { read=Get_Sobe };/* default */
};

// IXMLSobeType 

__interface INTERFACE_UUID("{F953B01F-ABA0-4D14-B0C6-FFEEDE922EAF}") IXMLSobeType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::AnsiString __fastcall Get_Soba() = 0;
  virtual void __fastcall Set_Soba(System::AnsiString Value) = 0;
  // Methods & Properties 
  __property System::AnsiString Soba = { read=Get_Soba, write=Set_Soba };
};

// Forward Decls 

class TXMLrootType;
class TXMLSobeType;

// TXMLrootType 

class TXMLrootType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLrootType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLrootType 
  virtual _di_IXMLSobeType __fastcall Get_Sobe(int Index);
  virtual _di_IXMLSobeType __fastcall Add();
  virtual _di_IXMLSobeType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLSobeType 

class TXMLSobeType : public Xml::Xmldoc::TXMLNode, public IXMLSobeType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLSobeType 
  virtual System::AnsiString __fastcall Get_Soba();
  virtual void __fastcall Set_Soba(System::AnsiString Value);
};

// Global Functions 

_di_IXMLrootType __fastcall Getroot(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLrootType __fastcall Getroot(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLrootType __fastcall Loadroot(const System::UnicodeString& FileName);
_di_IXMLrootType __fastcall  Newroot();

#define TargetNamespace ""

#endif