
// ******************************************************************************************************************* //
//                                                                                                                   
//                                                 XML Data Binding                                                  
//                                                                                                                   
//         Generated on: 14.5.2020. 17:40:31                                                                         
//       Generated from: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\Projekt\podaciSobe.xml   
//   Settings stored in: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\Projekt\podaciSobe.xdb   
//                                                                                                                   
// ******************************************************************************************************************* //

#include <System.hpp>
#pragma hdrstop

#include "podaciSobe.h"


// Global Functions 

_di_IXMLrootType __fastcall Getroot(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLrootType) Doc->GetDocBinding("root", __classid(TXMLrootType), TargetNamespace);
};

_di_IXMLrootType __fastcall Getroot(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getroot(DocIntf);
};

_di_IXMLrootType __fastcall Loadroot(const System::UnicodeString& FileName)
{
  return (_di_IXMLrootType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("root", __classid(TXMLrootType), TargetNamespace);
};

_di_IXMLrootType __fastcall  Newroot()
{
  return (_di_IXMLrootType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("root", __classid(TXMLrootType), TargetNamespace);
};

// TXMLrootType 

void __fastcall TXMLrootType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("Sobe"), __classid(TXMLSobeType));
  ItemTag = "Sobe";
  ItemInterface = __uuidof(IXMLSobeType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLSobeType __fastcall TXMLrootType::Get_Sobe(int Index)
{
  return (_di_IXMLSobeType) List->Nodes[Index];
};

_di_IXMLSobeType __fastcall TXMLrootType::Add()
{
  return (_di_IXMLSobeType) AddItem(-1);
};

_di_IXMLSobeType __fastcall TXMLrootType::Insert(const int Index)
{
  return (_di_IXMLSobeType) AddItem(Index);
};

// TXMLSobeType 

System::AnsiString __fastcall TXMLSobeType::Get_Soba()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Soba")]->Text;
};

void __fastcall TXMLSobeType::Set_Soba(System::AnsiString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Soba")]->NodeValue = Value;
};
