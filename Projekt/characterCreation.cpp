//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "characterCreation.h"
#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int Attack=0, Dexterity=10;
UnicodeString CharName;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
   	CharacterName->Color=(TColor) 0x222222;
	CharacterName->Font->Color=clWhite;

	Best->Font->Color=clWhite;
	Create->Font->Color=clWhite;
	Dex->Font->Color=clWhite;
	DHolder->Font->Color=clWhite;
	Faster->Font->Color=clWhite;

	SComment->Font->Color=clGreen;
	DComment->Font->Color=clGreen;

	SHolder->Font->Color=clWhite;
	Strength->Font->Color=clWhite;
	Stronger->Font->Color=clWhite;
}



//---------------------------------------------------------------------------
void __fastcall TForm3::ScrollBar1Scroll(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos)
{
	Attack=ScrollBar1->Position;
	Dexterity=10-Attack;
	SHolder->Caption=Attack+10;
	DHolder->Caption=Dexterity;

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	CharName=CharacterName->Text;
	ShowMessage(CharName + AnsiString(", welcome to the Text Dungeon!"));
	Form1->Show();
}
//---------------------------------------------------------------------------
