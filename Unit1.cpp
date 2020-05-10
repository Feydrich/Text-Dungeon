#include <vcl.h>
#pragma hdrstop
#include <memory>
#include "Unit1.h"
#include<MMSystem.h>
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

class Plot{
public:
	//f - floor, w - wall (drugo slovo smjer zabrane up down left right), d - door, ld - locked door
	char* Type;
	//[Y/S] da li tile sadrži išta
	char Contains;
	//Naziv predmeta ako ga ima, ponašanje objekta objašnjeno nakon uzimanja
	char* Item;
	//broj sobe kojoj pripada Tile
	int Soba;
	Plot(){};
	Plot(char* Type, char Contains, int Soba): Type(Type), Contains(Contains), Soba(Soba){};
	Plot(char* Type, char Contains, char *Item, int Soba): Type(Type), Contains(Contains), Item(Item), Soba(Soba){};

};



__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	//Svira dungeon muziku - zakomentirano jer me smetalo
	//PlaySound(TEXT("1.wav"),NULL,SND_FILENAME|SND_ASYNC);

	//Mijenjam boje u custom vrijednosti
	Display->Color=(TColor) 0x222222;
	Chat->Color=(TColor) 0x222222;
	Command->Color=(TColor) 0x222222;
	Display->Font->Color=clWhite;
	Chat->Font->Color=clWhite;
	Command->Font->Color=clWhite;
	ChatLabel->Font->Color=clWhite;
	P1Legend->Font->Color=clWhite;
	P2Legend->Font->Color=clWhite;
	FLegend->Font->Color=clWhite;
	ELegend->Font->Color=clWhite;


	//Srodno dimenzijama na .bmp slici karte, 16x26 - Nije se moglo automatski generirati zbog uporabe ručno nacrtane karte u igri
	Plot Grid[16][26] = {
		{Plot("wtl",'n',9), Plot("wt",'n',9), Plot("wt",'n',9), Plot("wtr",'n',9), Plot("wtl",'n',8), Plot("wt",'n',8), Plot("wt",'n',8), Plot("wtr",'n',8), Plot("x",'n',0), Plot("wtl",'n',14), Plot("wt",'n',14), Plot("wt",'n',14), Plot("wt",'n',14), Plot("wtdr",'n',14), Plot("ld",'n',5), Plot("wt",'n',6), Plot("wtl",'n',6), Plot("x",'n',0), Plot("wtl",'n',4), Plot("wt",'n',4), Plot("wtr",'n',4), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0)},

		{Plot("wl",'n',9), Plot("x",'n',9), Plot("f",'n',9), Plot("d",'n',9), Plot("d",'n',8), Plot("f",'n',8), Plot("f",'n',8), Plot("wr",'n',8), Plot("x",'n',0), Plot("wl",'n',14), Plot("f",'n',14), Plot("f",'n',14), Plot("wr",'n',14), Plot("x",'n',0), Plot("wlr",'n',5), Plot("wl",'n',6), Plot("wr",'n',6), Plot("x",'n',0), Plot("wl",'n',4), Plot("wd",'n',4), Plot("wr",'n',4), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0)},

		{Plot("wl",'n',9), Plot("x",'n',9), Plot("f",'n',9), Plot("wr",'n',9), Plot("wld",'n',8), Plot("wd",'n',8), Plot("x",'n',8), Plot("x",'n',8), Plot("x",'n',0), Plot("wld",'n',14), Plot("f",'n',14), Plot("x",'n',14), Plot("x",'n',0), Plot("wlr",'n',5), Plot("wl",'n',6), Plot("wr",'n',6), Plot("x",'n',0), Plot("wlt",'n',4), Plot("wt",'n',4), Plot("wtr",'n',4), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0)},

		{Plot("wld",'n',9), Plot("wd",'n',9), Plot("f",'n',9), Plot("wdr",'n',9), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("wl",'n',7), Plot("wr",'n',7), Plot("x",'n',0), Plot("x",'n',0), Plot("wl",'n',3), Plot("wtd",'n',3), Plot("wt",'n',3), Plot("wtd",'n',3), Plot("f",'n',4), Plot("f",'n',4), Plot("wr",'n',4), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0)},

		{Plot("x",'n',0), Plot("x",'n',0), Plot("wl",'n',15), Plot("wtd",'n',15), Plot("wtd",'n',15), Plot("wtd",'n',15), Plot("wtr",'n',15), Plot("x",'n',0), Plot("x",'n',7), Plot("x",'n',7), Plot("f",'n',7), Plot("f",'n',7), Plot("wtr",'n',7), Plot("x",'n',0), Plot("x",'n',3), Plot("wl",'n',3), Plot("wr",'n',3), Plot("x",'n',3), Plot("wld",'n',4), Plot("wd",'n',4), Plot("wdr",'n',4), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0)},

		{Plot("wtl",'n',10), Plot("wtd",'n',10), Plot("f",'n',10), Plot("wtl",'n',10), Plot("x",'n',10), Plot("x",'n',0), Plot("wld",'n',15), Plot("wtd",'n',5), Plot("wtr",'n',7), Plot("x",'n',7), Plot("wl",'n',7), Plot("f",'n',7), Plot("wr",'n',7), Plot("x",'n',0), Plot("x",'n',3), Plot("wl",'n',3), Plot("wr",'n',3), Plot("x",'n',3), Plot("wl",'n',4), Plot("wt",'n',4), Plot("wr",'n',4), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0), Plot("x",'n',0)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)},

		{Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1), Plot("f",'n',1)}

	};

}

//Sve komande pocinju sa ! znaci ovo je samo sorter koji poziva ispravnu komandu
//Ove sve funkcije kaj sad u globalno podrucije stavljamo ce ici u DLL kasnije
void functionSort(AnsiString Holder){
//To do
}





void __fastcall TForm1::CommandKeyPress(TObject *Sender, System::WideChar &Key)
{
	//https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	if(Key == VK_RETURN && Command->Text!=""){
		AnsiString dText = Chat->Caption;       //Brise space sa pocetka stringa
		AnsiString sText = TrimLeft(Command->Text);
		char firstLetter = sText[1];
		if (firstLetter == '!') {
			//TODO
			ShowMessage("Komanda primljena");
		}
		else{
			dText+=sText + '\n';
			Chat->Caption = dText;
        }
		Command->Text="";
		Command->SetFocus();
		Key=0;
		//Potrebno da IDE ne zasvira kad se pritisne enter
	}


}



