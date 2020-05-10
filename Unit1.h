//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Command;
	TButton *ItemButton;
	TStaticText *Display;
	TStaticText *Chat;
	TImage *Map;
	TShape *PlayerDot1;
	TLabel *ChatLabel;
	TLabel *P1Legend;
	TLabel *P2Legend;
	TLabel *ELegend;
	TLabel *FLegend;
	TShape *P1LDot;
	TShape *P2LDot;
	TShape *FLDot;
	TShape *ELDot;
	TLabel *Label1;

	void __fastcall CommandKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
