//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mainMenu.h"
#include <idhashmessagedigest.hpp>
#include <IdHashSha.hpp>
#include "podaciXML.h"
#include "characterCreation.h"
#include "reinit.hpp"
#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

bool Change = False;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormActivate(TObject *Sender)
{
	Label1->Font->Color=clWhite;
	Label2->Font->Color=clWhite;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnOKClick(TObject *Sender)
{
	if(textUsername->Text == "" || textPassword->Text == "")
	{
		if(Change == False)
			ShowMessage("Fill out every field!");
		else
			ShowMessage("Unesite sve podatke!");
		textPassword->Clear();
		return;
	}

	TIdHashSHA1* sha1 = new TIdHashSHA1;
	_di_IXMLpodaciType rootElement = Getpodaci(XMLDocument2);

	UnicodeString password = sha1->HashStringAsHex(textPassword->Text);
    password = password.LowerCase();

	UnicodeString users[500];
	UnicodeString pass[500];

	for(int i = 0; i < rootElement->Count; i++){
		for(int j=0; j<rootElement->Count; j++){
			users[j] = rootElement->User[j]->Get_name();
			pass[j] = rootElement->User[j]->Get_password();
			if(textUsername->Text == users[j] && password == pass[j].LowerCase()){
				if(Change == False){
					int odgovor1 = Application->MessageBox(L"Succes! Continue?", L"Continue", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
					if (odgovor1 == IDYES){
						Form3->Show();
						return;
					}else if (odgovor1 == IDNO) {
						return;
					}
				}
				else{
					int odgovor1 = Application->MessageBox(L"Uspjeh! Želite li nastaviti?", L"Nastavak", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
                    if (odgovor1 == IDYES){
						Form3->Show();
						return;
					}else if (odgovor1 == IDNO) {
						return;
					}
				}
			}
		}
		if(textUsername->Text != users[i]){
			if(Change == False){
				int odgovor2 = Application->MessageBox(L"User not found. Would you rather like to register with the given information?", L"New registration", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
				if (odgovor2 == IDYES){
					_di_IXMLUserType newUser = rootElement->Add();
					newUser->name = textUsername->Text;
					newUser->password = password;
					newUser->ip = "";

					XMLDocument2->SaveToFile(XMLDocument2->FileName);
					Form3->Show();
					return;
				}
				else{
					return;
				}
			}
			else{
				int odgovor2 = Application->MessageBox(L"Korisnik nije pronaðen. Želite li se registrirati sa unesenim podacima?", L"Nova registracija", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
                if (odgovor2 == IDYES){
					_di_IXMLUserType newUser = rootElement->Add();
					newUser->name = textUsername->Text;
					newUser->password = password;
					newUser->ip = "";

					XMLDocument2->SaveToFile(XMLDocument2->FileName);
					Form3->Show();
					return;
				}
				else{
					return;
				}
			}


		}

	}


	delete sha1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnCancelClick(TObject *Sender)
{
	if(Change == False){
		int odgovor = Application->MessageBox(L"Exit the application?", L"Exit", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
		if (odgovor == IDYES){
			TForm2::Close();
		}
	}
	else{
		int odgovor = Application->MessageBox(L"Izlaz iz aplikacije?", L"Izlaz", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
		if (odgovor == IDYES){
			TForm2::Close();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnCroClick(TObject *Sender)
{
	Form1->TCPServer->Active=False;
	ShowMessage("Cro");
	const CROATIAN = (SUBLANG_CROATIAN_CROATIA << 10) | LANG_CROATIAN;
	if(LoadNewResourceModule(CROATIAN)){
		ReinitializeForms();
	}
	Change=True;
	Form1->TCPServer->Active=True;
    adjuster = 16;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnUsClick(TObject *Sender)
{
	Form1->TCPServer->Active=False;

	const ENGLISH = (SUBLANG_ENGLISH_US << 10) | LANG_ENGLISH;
	if(LoadNewResourceModule(ENGLISH)){
		ReinitializeForms();
	}
	Change=False;
	Form1->TCPServer->Active=True;
	adjuster = 0;



}
//---------------------------------------------------------------------------

