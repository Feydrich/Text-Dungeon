
// ***************************************************************************************************************** //
//                                                                                                                 
//                                                XML Data Binding                                                 
//                                                                                                                 
//         Generated on: 5/24/2020 3:53:03 PM                                                                      
//       Generated from: C:\Users\Bassie\Desktop\TextDungeon0.1\TextDungeon0.1\Projekt\Win32\Debug\podaciXML.xml   
//   Settings stored in: C:\Users\Bassie\Desktop\TextDungeon0.1\TextDungeon0.1\Projekt\Win32\Debug\podaciXML.xdb   
//                                                                                                                 
// ***************************************************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "podaciXML.h"


// Global Functions 

_di_IXMLpodaciType __fastcall Getpodaci(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLpodaciType) Doc->GetDocBinding("podaci", __classid(TXMLpodaciType), TargetNamespace);
};

_di_IXMLpodaciType __fastcall Getpodaci(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getpodaci(DocIntf);
};

_di_IXMLpodaciType __fastcall Loadpodaci(const System::UnicodeString& FileName)
{
  return (_di_IXMLpodaciType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("podaci", __classid(TXMLpodaciType), TargetNamespace);
};

_di_IXMLpodaciType __fastcall  Newpodaci()
{
  return (_di_IXMLpodaciType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("podaci", __classid(TXMLpodaciType), TargetNamespace);
};

// TXMLpodaciType 

void __fastcall TXMLpodaciType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("User"), __classid(TXMLUserType));
  ItemTag = "User";
  ItemInterface = __uuidof(IXMLUserType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLUserType __fastcall TXMLpodaciType::Get_User(int Index)
{
  return (_di_IXMLUserType) List->Nodes[Index];
};

_di_IXMLUserType __fastcall TXMLpodaciType::Add()
{
  return (_di_IXMLUserType) AddItem(-1);
};

_di_IXMLUserType __fastcall TXMLpodaciType::Insert(const int Index)
{
  return (_di_IXMLUserType) AddItem(Index);
};

// TXMLUserType 

System::UnicodeString __fastcall TXMLUserType::Get_name()
{
  return GetChildNodes()->Nodes[System::UnicodeString("name")]->Text;
};

void __fastcall TXMLUserType::Set_name(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("name")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLUserType::Get_password()
{
  return GetChildNodes()->Nodes[System::UnicodeString("password")]->Text;
};

void __fastcall TXMLUserType::Set_password(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("password")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLUserType::Get_ip()
{
  return GetChildNodes()->Nodes[System::UnicodeString("ip")]->Text;
};

void __fastcall TXMLUserType::Set_ip(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("ip")]->NodeValue = Value;
};
