//---------------------------------------------------------------------------

#ifndef mainFormH
#define mainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <vector>
#include "characterCreation.h"
#include "mainForm.h"

using namespace std;
//---------------------------------------------------------------------------

class Plot{
public:
	//[Y/S] da li tile sadrži išta
	char Contains;
	//broj sobe kojoj pripada Tile
	int Soba;
	Plot(){};
	Plot(char Contains, int Soba): Contains(Contains), Soba(Soba){};
};


class Entity {
public:
	UnicodeString Name;
	double health, armor;
	int attack,dexterity;
	//index lokacija na gridu
	int index;
	Entity(UnicodeString Name, double health, double armor, int index, int attack, int dexterity) : Name(Name), health(health), armor(armor), index(index), attack(attack), dexterity(dexterity) {};
};

class Item{
public:
	UnicodeString Name;
	virtual void Use(Entity *x){
		ShowMessage("Ovo je primjer polimorfizma");
	};
	Item(UnicodeString Name): Name(Name){}
};


class Player : public Entity {
public:
	int PlayerNumber;
	Player(UnicodeString Name, int PlayerNumber, double health, double armor, int index, int attack, int dexterity) : PlayerNumber(PlayerNumber), Entity(Name, health, armor, index, attack, dexterity) {};
};

class Enemy : public Entity {
public:
	UnicodeString item;
	Enemy(UnicodeString Name, UnicodeString Item, double health, double armor, int index, int attack, int dexterity) : item(item), Entity(Name, health, armor, index, attack, dexterity) {};
	virtual void Say()=0;
};


class Human : public Enemy {
public:
	void Say() {
		ShowMessage("You came to the wrong place!");
	}
	Human(int index): Enemy("Human", "Gold", 20, 2.0, index, 5, 1) {};
};

class Dog : public Enemy {
public:
	void Say() {
		ShowMessage("Woof Woof!");
	}
	Dog(int index): Enemy("Dog", "Gold", 10, 0.0, index, 7, 7) {};
};

class HealingPotion : public Item{
public:
	HealingPotion(): Item("Healing potion"){}
	void Use(Entity *x){
		x->health+=20;
	}
};

class Poison : public Item{
public:
	Poison(): Item("Poison"){}
	void Use(Entity *x){
		x->health-=10;
		if (x->health<=0) {
			ShowMessage("You died, GAME OVER");
			Form3->Close();
		}
	}
};


class Gold : public Item{
public:
	Gold(): Item("Gold"){}
	void Use(Entity *x){
			ShowMessage("Not much can be done with this here...");
		}
	};



AnsiString opisSobe[32];



class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Command;
	TButton *Menu;
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
	TTimer *Timer1;
	TXMLDocument *XMLDocument1;
	TIdTCPClient *TCPClient;
	TIdTCPServer *TCPServer;
	TListBox *Chat;
	TShape *PlayerDot2;
	TListBox *Display;
	TShape *Enemy1;
	TShape *Enemy2;
	TShape *Enemy4;
	TShape *Enemy5;
	TShape *Enemy3;
	TXMLDocument *XMLLOKALIZACIJA;

	void __fastcall CommandKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall MenuClick(TObject *Sender);
	void __fastcall TCPServerExecute(TIdContext *AContext);
	void __fastcall FormShow(TObject *Sender);


private:
public:
	__fastcall TForm1(TComponent* Owner);

	int move(Player temp, int direction);
	// 1 - Chat, 2 - move up, 3 - move right, 4 - move down, 5 - move left
	void serverCom(UnicodeString IP, int indicator);

	void Combat(Player *x, Enemy* y);
	double Strike(Entity *x, Entity *y);
	void Use(Player *x, Item *y);


	AnsiString getOpisSobe(int position){
		return opisSobe[position];
	}

};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//connectForm
extern UnicodeString Address, CharName;
extern int Attack, Dexterity;
extern bool Change;
//---------------------------------------------------------------------------
#endif
