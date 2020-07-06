//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "connectForm.h"
#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConnectionForm *ConnectionForm;
UnicodeString Address="127.0.0.1";
//---------------------------------------------------------------------------
__fastcall TConnectionForm::TConnectionForm(TComponent* Owner)
	: TForm(Owner)
{
	HostLabel->Font->Color=clWhite;
	IP->Color=(TColor) 0x222222;
	IP->Font->Color=clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TConnectionForm::ConnectButtonClick(TObject *Sender)
{
	Address=IP->Text;
	ShowMessage("IP address '" + Address + AnsiString("' has been set!"));
}
//---------------------------------------------------------------------------
