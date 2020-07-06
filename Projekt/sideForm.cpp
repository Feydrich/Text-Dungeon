//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sideForm.h"
#include "connectForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Inventory.h"
#include "saveLoadXML.h"
#include "playerSettings.h"
#include "mainMenu.h"
#include "mainForm.h"
#include "characterCreation.h"
#include "chatXML.h"
TsideMenu *sideMenu;
//---------------------------------------------------------------------------
__fastcall TsideMenu::TsideMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TsideMenu::Button2Click(TObject *Sender)
{
	  ConnectionForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TsideMenu::Button1Click(TObject *Sender)
{
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TsideMenu::Button4Click(TObject *Sender)
{
	//LOAD GAME
    //inicijalizacija saveLoadXML dokumenta - pohranjuje Plot
	_di_IXMLsaveLoadType rootElement = GetsaveLoad(saveLoadXML);

	for(int i = 0;i<20;i++){
		UnicodeString temp = rootElement->positions->Get_plot(i);
		Grid[i].Contains = temp[1];
	};

	_di_IXMLplayerType playerElement = Getplayer(playerSettingsXML);

	Player1.health = playerElement->health;
	Player1.dexterity = playerElement->dex.ToInt();
	Player1.attack = playerElement->stregth.ToInt();

	Form1->Chat->Items->Add(playerElement->poruka);
	ShowMessage("SAVE LOADED!");
}
//---------------------------------------------------------------------------

void __fastcall TsideMenu::Button3Click(TObject *Sender)
{
	//SAVE GAME

	//inicijalizacija saveLoadXML dokumenta - pohranjuje Plot
	_di_IXMLsaveLoadType rootElement = GetsaveLoad(saveLoadXML);

	//Brisanje Child elementa kako bi se mogli pohraniti novi
	_di_IXMLNode positions = saveLoadXML->DocumentElement;
	positions->ChildNodes->Delete(positions->ChildNodes->Count - 1);

	//Dodavanje novog positions elementa
	_di_IXMLNode newPos = saveLoadXML->DocumentElement->AddChild(UnicodeString("positions"));


	//Pohrana novih vrijednosti plot-a u positions element
	for(int i = 0; i <= 19; i++){
		_di_IXMLNode ValueNode = newPos->AddChild(UnicodeString("plot"));
		ValueNode->Text = UnicodeString(Grid[i].Contains);
	}
	//zapisivanje u xml datoteku
	saveLoadXML->SaveToFile(saveLoadXML->FileName);


	//inicijalizacija playerSettingsXML dokumenta - pohrana health, dex (dexterity), strength
	_di_IXMLplayerType playerElement = Getplayer(playerSettingsXML);

	//brisanje starih vrijednosti elemenata: health, dex, strength
	for(int i=0; i<4; i++){
		_di_IXMLNode allElements = playerSettingsXML->DocumentElement;
		allElements->ChildNodes->Delete(allElements->ChildNodes->Count - 1);
	}

	//dodavanje nove vrijednosti health
	_di_IXMLNode newHealth = playerSettingsXML->DocumentElement->AddChild(UnicodeString("health"));
	newHealth->Text = (UnicodeString)Player1.health;

	//dodavanje nove vrijednosti dex
	_di_IXMLNode newDex = playerSettingsXML->DocumentElement->AddChild(UnicodeString("dex"));
	newDex->Text = (UnicodeString)Player1.dexterity;

	//dodavanje nove vrijednosti strength
	_di_IXMLNode newStrength = playerSettingsXML->DocumentElement->AddChild(UnicodeString("stregth"));
	newStrength->Text = (UnicodeString)Player1.attack;

    //dodavanje poruka u XML
    _di_IXMLNode newPoruka = playerSettingsXML->DocumentElement->AddChild(UnicodeString("poruka"));
	newPoruka->Text = messageHolder;

	//zapisivanje promjena u datoteku
	playerSettingsXML->SaveToFile(playerSettingsXML->FileName);

	ShowMessage("GAME SAVED");
}
//---------------------------------------------------------------------------


void __fastcall TsideMenu::Button5Click(TObject *Sender)
{
	int odgovor = Application->MessageBox(L"All you progress will be lost, make sure to save first!", L"Exit", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
	if (odgovor == IDYES){
		if(Form1->Showing){
		Form1->Close();
		}
		if(Form2->Showing){
			Form2->Close();
		}
		if(Form3->Showing){
			Form3->Close();
		}
		if(Form4->Showing){
			Form4->Close();
		}
		if(sideMenu->Showing){
			sideMenu->Close();
		}
		if(ConnectionForm->Showing){
			ConnectionForm->Close();
		}
	}
	else{
        return;
    }

}
//---------------------------------------------------------------------------

