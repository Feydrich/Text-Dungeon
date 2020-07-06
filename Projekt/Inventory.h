//---------------------------------------------------------------------------

#ifndef InventoryH
#define InventoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "mainForm.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *StatLabel;
	TLabel *NameLabel;
	TLabel *PlayerName;
	TLabel *PlayerName2;
	TLabel *Label1;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label5;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
extern Player Player1;
//---------------------------------------------------------------------------
#endif
