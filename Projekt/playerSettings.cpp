
// ******************************************************************************************* //
//                                                                                           
//                                     XML Data Binding                                      
//                                                                                           
//         Generated on: 6/1/2020 1:21:38 AM                                                 
//       Generated from: C:\Users\Bassie\Desktop\TextDungeon1.0\Projekt\playerSettings.xml   
//   Settings stored in: C:\Users\Bassie\Desktop\TextDungeon1.0\Projekt\playerSettings.xdb   
//                                                                                           
// ******************************************************************************************* //

#include <System.hpp>
#pragma hdrstop

#include "playerSettings.h"


// Global Functions 

_di_IXMLplayerType __fastcall Getplayer(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLplayerType) Doc->GetDocBinding("player", __classid(TXMLplayerType), TargetNamespace);
};

_di_IXMLplayerType __fastcall Getplayer(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getplayer(DocIntf);
};

_di_IXMLplayerType __fastcall Loadplayer(const System::UnicodeString& FileName)
{
  return (_di_IXMLplayerType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("player", __classid(TXMLplayerType), TargetNamespace);
};

_di_IXMLplayerType __fastcall  Newplayer()
{
  return (_di_IXMLplayerType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("player", __classid(TXMLplayerType), TargetNamespace);
};

// TXMLplayerType 

double __fastcall TXMLplayerType::Get_health()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("health")]->Text);
};

void __fastcall TXMLplayerType::Set_health(double Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("health")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLplayerType::Get_dex()
{
  return GetChildNodes()->Nodes[System::UnicodeString("dex")]->Text;
};

void __fastcall TXMLplayerType::Set_dex(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("dex")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLplayerType::Get_stregth()
{
  return GetChildNodes()->Nodes[System::UnicodeString("stregth")]->Text;
};

void __fastcall TXMLplayerType::Set_stregth(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("stregth")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLplayerType::Get_poruka()
{
  return GetChildNodes()->Nodes[System::UnicodeString("poruka")]->Text;
};

void __fastcall TXMLplayerType::Set_poruka(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("poruka")]->NodeValue = Value;
};
