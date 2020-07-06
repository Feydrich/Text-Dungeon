//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Inventory.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	NameLabel->Font->Color=clWhite;
	StatLabel->Font->Color=clWhite;

}
//---------------------------------------------------------------------------



void __fastcall TForm4::FormShow(TObject *Sender)
{
	UnicodeString stats;
	PlayerName-> Caption = Player1.Name;
    PlayerName2-> Caption = Player1.Name;
	stats = "You have: " + (UnicodeString)Player1.health + AnsiString(" health, ") + Player1.dexterity + AnsiString(" dexterity and ") + Player1.attack + AnsiString(" strength.");
	StatLabel->Caption = stats;

}
//---------------------------------------------------------------------------

