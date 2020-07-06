//---------------------------------------------------------------------------

#ifndef mainMenuH
#define mainMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "mainForm.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnOK;
	TButton *btnCancel;
	TEdit *textUsername;
	TEdit *textPassword;
	TLabel *Label1;
	TLabel *Label2;
	TXMLDocument *XMLDocument2;
	TButton *btnCro;
	TButton *btnUs;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall btnOKClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnCroClick(TObject *Sender);
	void __fastcall btnUsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
extern int adjuster;
//extern TIdTCPServer *TCPServer;
//---------------------------------------------------------------------------
#endif
