//---------------------------------------------------------------------------

#ifndef characterCreationH
#define characterCreationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TScrollBar *ScrollBar1;
	TLabel *Faster;
	TLabel *Stronger;
	TLabel *Best;
	TEdit *CharacterName;
	TLabel *Strength;
	TLabel *Dex;
	TLabel *SHolder;
	TLabel *DHolder;
	TLabel *Create;
	TLabel *SComment;
	TLabel *DComment;
	TButton *Button1;
	void __fastcall ScrollBar1Scroll(TObject *Sender, TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
