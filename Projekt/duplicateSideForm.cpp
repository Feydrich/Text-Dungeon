//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "duplicateSideForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	ShowMessage(Grid[0].Contains);
}
//---------------------------------------------------------------------------