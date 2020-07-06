//---------------------------------------------------------------------------

#ifndef connectFormH
#define connectFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TConnectionForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *IP;
	TButton *ConnectButton;
	TLabel *HostLabel;
	void __fastcall ConnectButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TConnectionForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConnectionForm *ConnectionForm;
//---------------------------------------------------------------------------
#endif
