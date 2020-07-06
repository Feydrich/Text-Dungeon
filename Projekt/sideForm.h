//---------------------------------------------------------------------------

#ifndef sideFormH
#define sideFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "mainForm.h"
#include "saveLoadXML.h"
#include "playerSettings.h"
//---------------------------------------------------------------------------
class TsideMenu : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TXMLDocument *playerSettingsXML;
	TXMLDocument *saveLoadXML;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TsideMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TsideMenu *sideMenu;
extern Plot Grid[20];
extern Player Player1;
extern UnicodeString messageHolder;

//---------------------------------------------------------------------------
#endif
