
// *********************************************************************************************************************************************** //
//                                                                                                                                               
//                                                               XML Data Binding                                                                
//                                                                                                                                               
//         Generated on: 28.5.2020. 14:51:12                                                                                                     
//       Generated from: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\TextDungeon0.1\Projekt\Win32\Debug\saveLoadXML.xml   
//   Settings stored in: S:\Faks\4. semestar\Objektno Orijentirano Programiranje II\Projekt\TextDungeon0.1\Projekt\Win32\Debug\saveLoadXML.xdb   
//                                                                                                                                               
// *********************************************************************************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "saveLoadXML.h"


// Global Functions 

_di_IXMLsaveLoadType __fastcall GetsaveLoad(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLsaveLoadType) Doc->GetDocBinding("saveLoad", __classid(TXMLsaveLoadType), TargetNamespace);
};

_di_IXMLsaveLoadType __fastcall GetsaveLoad(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetsaveLoad(DocIntf);
};

_di_IXMLsaveLoadType __fastcall LoadsaveLoad(const System::UnicodeString& FileName)
{
  return (_di_IXMLsaveLoadType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("saveLoad", __classid(TXMLsaveLoadType), TargetNamespace);
};

_di_IXMLsaveLoadType __fastcall  NewsaveLoad()
{
  return (_di_IXMLsaveLoadType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("saveLoad", __classid(TXMLsaveLoadType), TargetNamespace);
};

// TXMLsaveLoadType 

void __fastcall TXMLsaveLoadType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("positions"), __classid(TXMLpositionsType));
  Xml::Xmldoc::TXMLNode::AfterConstruction();
};

_di_IXMLpositionsType __fastcall TXMLsaveLoadType::Get_positions()
{
  return (_di_IXMLpositionsType) GetChildNodes()->Nodes[System::UnicodeString("positions")];
};

// TXMLpositionsType 

void __fastcall TXMLpositionsType::AfterConstruction(void)
{
  ItemTag = "plot";
  ItemInterface = __uuidof(Xml::Xmlintf::IXMLNode);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

System::UnicodeString __fastcall TXMLpositionsType::Get_plot(int Index)
{
  return List->Nodes[Index]->Text;
};

Xml::Xmlintf::_di_IXMLNode __fastcall TXMLpositionsType::Add(const System::UnicodeString plot)
{
  Xml::Xmlintf::_di_IXMLNode item = AddItem(-1);
  item->NodeValue = plot;
  return item;
};

Xml::Xmlintf::_di_IXMLNode __fastcall TXMLpositionsType::Insert(const int Index, const System::UnicodeString plot)
{
  Xml::Xmlintf::_di_IXMLNode item = AddItem(Index);
  item->NodeValue = plot;
  return item;
};
