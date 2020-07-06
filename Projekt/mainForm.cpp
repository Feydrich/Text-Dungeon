#include <vcl.h>
#pragma hdrstop
#include<memory>
#include "mainForm.h"
#include<MMSystem.h>
#include<windows.h>
#include<vector>
#pragma package(smart_init)
#pragma resource "*.dfm"
#include<string>
#include "podaciSobe.h"
#include "connectForm.h"
#include "characterCreation.h"
#include "sideForm.h"
#include "mainMenu.h"
using namespace std;

TForm1 *Form1;

extern "C" int __declspec(dllexport) __stdcall functionSort(string inputedCommand);
extern "C" int __declspec(dllexport) __stdcall dodgeCalculator(int dodgeAtacker, int dodgeDefender);

//Svaki print u Display se broji, ako dodđe do 14 se display briše
int clearCounter = 0;
int roomTracker;
//ovo loada prazne vrijednosti prilikom paljenja, kasnije u timeru se ažurira na ispravne
Player Player1(CharName,1,20.0,0.0,1,Attack,Dexterity), Player2("Program napisali: Filip Vasiljević i Leon Paolović",2,1,1,1,1,1);
//Inventory:
HealingPotion hpotion;
Poison poison;
Gold gold;
int adjuster;
UnicodeString messageHolder;



//Srodno pozicijama u sobama na .bmp slici karte - Nije se moglo automatski generirati zbog uporabe ručno nacrtane karte
	Plot Grid[20] = {
	//Zakomentirane pozicije na dogovorenoj karti, i+1 unutar polja je ujedno indikator pozicije igraca i to se povezuje s index atributom u objektima Player
	/*1*/Plot('n', 1), /*2*/Plot('n', 2), /*3*/Plot('n', 3), /*4*/Plot('n', 3), /*5*/Plot('y', 4),
	/*6*/Plot('n', 5), /*7*/Plot('y', 6), /*8*/Plot('n', 14), /*9*/Plot('n', 7), /*10*/Plot('n', 7),
	/*11*/Plot('n', 7), /*12*/Plot('n', 7), /*13*/Plot('n', 13), /*14*/Plot('y', 16), /*15*/Plot('y', 8),
	/*16*/Plot('n', 9), /*17*/Plot('n', 15), /*18*/Plot('n', 10), /*19*/Plot('n', 12), /*20*/Plot('y', 11)
	};

	//Enemy *dungeon[5] = {&Human(5), &Human(7), &Human(14), &Dog(15), &Dog(20)};
	//Name, Player number, Health, Position index
	Human First(5), Second(7), Third(14);
	Dog Forth(15), Fifth(20);




	void TForm1::Use(Player *x, Item *y){
		double hp=x->health;
		y->Use(x);
		Display->Clear();
		if(Change==False){
		if(y->Name=="Healing potion")
			Display->Items->Add("You've used a " + y->Name);
		else
			Display->Items->Add("You've used " + y->Name);
		if(y->Name=="Gold")
			Display->Items->Add("Not much can be done with this here");
		else
			Display->Items->Add("Your health went from: " + (UnicodeString)hp + AnsiString(" to ") + (UnicodeString)x->health);
		Display->Items->Add("");
		}
		else{
		if(y->Name=="Healing potion")
			Display->Items->Add("Iskoristio si napitak zdravlja");
		if(y->Name=="Poison")
			Display->Items->Add("Popio si otrov...");
		if(y->Name=="Gold")
			Display->Items->Add("Nemože se puno s ovime napraviti...");
		else
			Display->Items->Add("Životni bodovi su ti se izmjenili iz: " + (UnicodeString)hp + AnsiString(" u ") + (UnicodeString)x->health);
		Display->Items->Add("");

		}
	}




	int TForm1::move(Player temp, int direction){
	//limitacija ovog rješenja je to što move funkcija nije bila ponovno uporabljiva drugdje
	//bolje rješenje bi bilo u grid enkodirat limitacije kreatanja ali radi jednostavnosti
	//smo se odlučili za ovo rješenje

	TShape *holder;
	int alignment;

		if(Address != "127.0.0.1"){
            if(temp.PlayerNumber == 1){
                alignment = 0;
                holder = PlayerDot1;
            }
            else{
                alignment = 16;
                holder = PlayerDot2;
            }
        }else{
           if(temp.PlayerNumber == 1){
                alignment = 0;
                holder = PlayerDot1;
            }
            else{
                alignment = 0;
                holder = PlayerDot2;
            }
		}

		//glavni switch-case prati koji upit smjera je dan up = 1, right = 2, down = 3, left = 4
		switch(direction){
			//up
			case 1:
				//sekundarni switch-case-ovi prate koje pozicije imaju opciju tog smjera
				switch(temp.index){
				//svaki case je jedna pozicija koja smije ici prema gore, ako pozicija nije među case opcijama nista se ne dogada (vraca istu vrijednost)
					case 1:
						holder->Top=180;
						holder->Left=1095+alignment;
						//returna vrijednost sobe u koju ulazi
						return 2;
						break;
					case 3:
						holder->Top=123+alignment;
						holder->Left=987;
						return 4;
						break;
					case 4:
						holder->Top=66+alignment;
						holder->Left=959;
						return 6;
						break;
					case 9:
						holder->Top=80;
						holder->Left=892+alignment;
						return 8;
						break;
					case 10:
						holder->Top=138;
						holder->Left=900+alignment;
						return 9;
						break;
					case 11:
						holder->Top=138+alignment;
						holder->Left=851;
						return 12;
						break;
					case 17:
						holder->Top=82;
						holder->Left=751+alignment;
						return 16;
						break;
					case 18:
						holder->Top=123;
						holder->Left=763+alignment;
						return 17;
						break;
					case 19:
						holder->Top=170;
						holder->Left=764+alignment;
						return 18;
						break;
					case 20:
						holder->Top=249;
						holder->Left=747+alignment;
						return 19;
						break;
					default:
						//bez ovog će i drugog igrača obaviještavat o sudaru sa zidom
						if(temp.PlayerNumber==1){
							if(Change==False)
								Display->Items->Add("You hit a wall!");
							else
								Display->Items->Add("Sudario si se sa zidom!");
						}
						return temp.index;
						break;
				}
			//right
			case 2:
				switch(temp.index){
					case 3:
						holder->Top=180;
						holder->Left=1095+alignment;
						return 2;
						break;
					case 4:
						holder->Top=106;
						holder->Left=1040+alignment;
						return 5;
						break;
					case 6:
						holder->Top=66+alignment;
						holder->Left=987;
						return 7;
						break;
					case 8:
						holder->Top=66+alignment;
						holder->Left=959;
						return 6;
						break;
					case 10:
						holder->Top=298;
						holder->Left=979+alignment;
						return 13;
						break;
					case 11:
						holder->Top=250+alignment;
						holder->Left=899+alignment;
						return 10;
						break;
					case 12:
						holder->Top=138;
						holder->Left=900+alignment;
						return 9;
						break;
					case 14:
						holder->Top=258;
						holder->Left=1100+alignment;
						return 1;
						break;
					case 16:
						holder->Top=74;
						holder->Left=811+alignment;
						return 15;
						break;
					case 17:
						holder->Top=138+alignment;
						holder->Left=851;
						return 12;
						break;
					case 19:
						holder->Top=250;
						holder->Left=827+alignment;
						return 11;
						break;

					default:
						if(temp.PlayerNumber==1){
							if(Change==False)
								Display->Items->Add("You hit a wall!");
							else
								Display->Items->Add("Sudario si se sa zidom!");
						}
						return temp.index;
						break;
				}
			//down
			case 3:
				switch(temp.index){
					case 2:
						holder->Top=258;
						holder->Left=1100+alignment;
						return 1;
						break;
					case 4:
						holder->Top=170;
						holder->Left=980+alignment;
						return 3;
						break;
					case 6:
						holder->Top=123+alignment;
						holder->Left=987;
						return 4;
						break;
					case 8:
						holder->Top=138;
						holder->Left=900+alignment;
						return 9;
						break;
					case 9:
						holder->Top=250+alignment;
						holder->Left=899+alignment;
						return 10;
						break;
					case 12:
						holder->Top=250;
						holder->Left=827+alignment;
						return 11;
						break;
					case 16:
						holder->Top=123;
						holder->Left=763+alignment;
						return 17;
						break;
					case 17:
						holder->Top=170;
						holder->Left=764+alignment;
						return 18;
						break;
					case 18:
						holder->Top=249;
						holder->Left=747+alignment;
						return 19;
						break;
					case 19:
						holder->Top=281;
						holder->Left=747+alignment;
						return 20;
						break;
					 default:
                        if(temp.PlayerNumber==1){
							if(Change==False)
								Display->Items->Add("You hit a wall!");
							else
								Display->Items->Add("Sudario si se sa zidom!");
						}
						return temp.index;
						break;
				}
			//left
			case 4:
				switch(temp.index){
				   case 1:
						holder->Top=236;
						holder->Left=980+alignment;
						return 14;
						break;
				   case 2:
						holder->Top=170;
						holder->Left=980+alignment;
						return 3;
						break;
				   case 5:
						holder->Top=123+alignment;
						holder->Left=987;
						return 4;
						break;
				   case 6:
						holder->Top=80;
						holder->Left=892+alignment;
						return 8;
						break;
				   case 7:
						holder->Top=66+alignment;
						holder->Left=959;
						return 6;
						break;
				   case 9:
						holder->Top=138+alignment;
						holder->Left=851;
						return 12;
						break;
				   case 10:
						holder->Top=250;
						holder->Left=827+alignment;
						return 11;
						break;
				   case 11:
						holder->Top=249;
						holder->Left=747+alignment;
						return 19;
						break;
				   case 12:
						holder->Top=123;
						holder->Left=763+alignment;
						return 17;
						break;
				   case 13:
						holder->Top=250+alignment;
						holder->Left=899+alignment;
						return 10;
						break;
				   case 15:
						holder->Top=82;
						holder->Left=751+alignment;
						return 16;
						break;
				   default:
                        if(temp.PlayerNumber==1){
							if(Change==False)
								Display->Items->Add("You hit a wall!");
							else
								Display->Items->Add("Sudario si se sa zidom!");
						}
						return temp.index;
						break;
				}
			default:
				ShowMessage("Došlo je do greške...");
				break;
		}
	}

	double TForm1::Strike(Entity *x, Entity *y){
		//x napada y
		int dodge = dodgeCalculator(x->dexterity, y->dexterity);
		if(dodge>=0){
			//ovdje bi također zbrojili nekakvu vrijednost oružija, no u našoj izvedbi igrice smo to preskocili (lako za implementirat, služilo bi samo kao proof of concept)
			double damage = x->attack - y->armor;
			//ako je dodge pozitivan broj to znaci da je napadac brzi, ako je negativan onda se suparnik uspio izmaknut, ovo je alternativni sorting logika onome u Combat funkciji
			if(Change == False){
				Display->Items->Add(x->Name + AnsiString(" succesfully hit ") + y->Name + AnsiString(" doing ") + damage + AnsiString(" damage!"));
				Display->Items->Add("");
			}
			else{
				Display->Items->Add(x->Name + AnsiString(" je uspješno pogodio ") + y->Name + AnsiString(" i s time napravio ") + damage + AnsiString(" bodova štete!"));
				Display->Items->Add("");
			}
			return y->health-damage;
		}

		else{

			if(Change == False){
			Display->Items->Add(x->Name + AnsiString(" missed "));
			Display->Items->Add("");
			}

			else{
				Display->Items->Add(x->Name + AnsiString(" je promašio "));
				Display->Items->Add("");
			}

			//regenerirao je 1 za kaznu promašaja
			return y->health+1;
		}
	}


	void TForm1::Combat(Player *x, Enemy* y){
		Display->Items->Clear();
		if(Change == False){
			Display->Items->Add("You're fighting a " + y->Name + AnsiString("!"));
			Display->Items->Add("");
		}

		else{
		   Display->Items->Add("Boriš se protiv  " + y->Name + AnsiString("!"));
		   Display->Items->Add("");
		}
		UnicodeString playerInput;
		int i=0, doTracker=0, positionTracker = x->index;
		double hpTracker1=x->health, hpTracker2=y->health;
		srand (time(NULL));
		//initiative je broj koji diktira redoslijed poteza, računa se D20 + Dexterity (D20 = nasumično generiran broj od 1 do 20)
		int PlayerInitiative = x->dexterity + (rand()%20+1), EnemyInitiative = y->dexterity + (rand()%20+1);


		if(PlayerInitiative > EnemyInitiative)
			i = 0;
		if(PlayerInitiative < EnemyInitiative)
			i = 1;


		while((x->health > 0 && y->health > 0)){
		//ShowMessage(x->health);
			if(i==0){
				if(doTracker==0){
					//Ako je igracev red
					if(Change == False){
						Display->Items->Add("It's your turn, what will you do?   [Options: !Strike, !Use, !Surrender]");
						Display->Items->Add("Your hp: " + (UnicodeString)x->health + AnsiString("      Enemy hp: " + (UnicodeString)y->health));
						Display->Items->Add("");

						while(playerInput!="!Strike" && playerInput!="!Surrender" && playerInput!="!Use" && x->health>0 && y->health>0){
							playerInput=InputBox("Input Command", "!Stike, !Use, !Surrender:", "!Strike");
						}
					}

					else{

						Display->Items->Add("Tvoj je potez!   [Izbori: !Napadni, !Iskoristi, !Predaja]");
						Display->Items->Add("Tvoji životni bodovi: " + (UnicodeString)x->health + AnsiString("      Neprijateljski životni bodovi: " + (UnicodeString)y->health));
						Display->Items->Add("");

						while(playerInput!="!Napadni" && playerInput!="!Iskoristi" && playerInput!="!Predaja" && x->health>0 && y->health>0){
							playerInput=InputBox("Unesite naredbu", "!Napadni, !Iskoristi, !Predaja:", "!Napadni");
						}

					}
					doTracker=1;
				}
			}

			if(i==1){
				x->health=Strike(y,x);
			}

			if(playerInput=="!Strike" || playerInput=="!Napadni"){
				playerInput="reset";
				y->health=Strike(x,y);
			}

			if(playerInput=="!Use" || playerInput=="!Iskoristi"){
				playerInput="reset";
				UnicodeString usedItem;
				if(Change == False){
					do{
						usedItem = InputBox("Input Command", "Options: Healing potion, Poison or Gold:", "Healing potion");
					}while(usedItem!="Healing potion" && usedItem!="Poison"  && usedItem!="Gold");
				}
				else{
					do{
						usedItem = InputBox("Odaberi predmet", "Izbori: Napitak zdravlja, Otrov ili Zlato:", "Napitak zdravlja");
					}while(usedItem!="Napitak zdravlja" && usedItem!="Otrov"  && usedItem!="Zlato");
				}

				if(usedItem=="Healing potion" || usedItem=="Napitak zdravlja")
					Use(x, &hpotion);
				if(usedItem=="Poison" || usedItem=="Otrov")
					Use(x, &poison);
				if(usedItem=="Gold" || usedItem=="Zlato")
					Use(x, &gold);
			}

			if(x->health!=hpTracker1 || y->health!=hpTracker2){
				hpTracker1 = x->health;
				hpTracker2 = y->health;
				//svakom rotacijom ce se i povecat za jedan i modulirat sa dva, tako osiguram da scrollam između 2 objekta u polju entity
				//logika: ako i = 1, onda i%2 == 1; ako i = 2, onda i%2 == 0; i tako beskonacno u while petlji
				i=(i+1)%2;
				doTracker=0;
			}

			if(x->health <= 0  || playerInput=="!Surrender" || playerInput=="!Predaja"){
				x->health = 0;
				if(Change == False){
					ShowMessage("You've lost! GAME OVER");
				}
				else{
					ShowMessage("Izgubili ste igru... GAME OVER");
				}

				Form1->Close();
                Form2->Close();
                Form3->Close();
			}
		}
		if(y->health <= 0){
			Display->Items->Clear();

            if(Change == False){
					Display->Items->Add("You've won the fight!");
			}
			else{
				Display->Items->Add("Pobjedili ste!");
			}
			Display->Items->Add("");
		}
	}




	void TForm1::serverCom(UnicodeString IP, int indicator){
		TCPClient->Host = IP;
		TCPClient->Connect();
		switch (indicator) {
			case 1:
				TCPClient->Socket->Write(Command->Text.Length());
				TCPClient->Socket->Write(Command->Text);
				break;
			case 2:
				TCPClient->Socket->Write(20);
				TCPClient->Socket->Write("2mYrJwmSGRQY1PywIWll");
				break;
			case 3:
				TCPClient->Socket->Write(20);
				TCPClient->Socket->Write("h5pIFAWl6cHcSk4GYvEX");
				break;
			case 4:
				TCPClient->Socket->Write(20);
				TCPClient->Socket->Write("n4xyH0CqLu3m1aIlKbpP");
				break;
			case 5:
				TCPClient->Socket->Write(20);
				TCPClient->Socket->Write("HfyjOxUMKTcvAf8y15El");
				break;
		default:
			ShowMessage("Kriva vrijednost indikatora unesena!");
			break;
		}
		TCPClient->Disconnect();
	}



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

	_di_IXMLrootType rootElement = Getroot(XMLDocument1);

	for(int i = 0; i < 32; i++){
		opisSobe[i] = rootElement->Sobe[i]->Soba;
	}

}


void __fastcall TForm1::CommandKeyPress(TObject *Sender, System::WideChar &Key)
{
	//https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	if(Key == VK_RETURN && Command->Text!=""){
		//AnsiString dText = Chat->Caption;       //Brise space sa pocetka stringa
		AnsiString sText = TrimLeft(Command->Text);
		char firstLetter = sText[1];
		if (firstLetter == '!') {
		UnicodeString usedItem;
			switch (functionSort(sText.c_str())) {
				case 1:
					if(Change == False){
						Display->Items->Clear();
						Display->Items->Add("You strike at the air, doing nothing.");
						Display->Items->Add("");
					}
					else{
                        Display->Items->Clear();
						Display->Items->Add("Zamahnuo si u prazno, ništa se ne dogodi");
						Display->Items->Add("");
					}
					break;
				case 2:
					if(Change == False){
						do{
							usedItem = InputBox("Input Command", "Options: Healing potion, Poison or Gold:", "Healing potion");
						}while(usedItem!="Healing potion" && usedItem!="Poison"  && usedItem!="Gold");
					}
					else{
						do{
							usedItem = InputBox("Odaberi predmet", "Izbori: Napitak zdravlja, Otrov ili Zlato:", "Napitak zdravlja");
						}while(usedItem!="Napitak zdravlja" && usedItem!="Otrov"  && usedItem!="Zlato");
					}
                    if(usedItem=="Healing potion" || usedItem=="Napitak zdravlja")
						Use(&Player1, &hpotion);
					if(usedItem=="Poison" || usedItem=="Otrov")
						Use(&Player1, &poison);
					if(usedItem=="Gold" || usedItem=="Zlato")
						Use(&Player1, &gold);
					break;
				case 3:
					if(Change == False){
						Display->Items->Clear();
						Display->Items->Add("You are: " + Player1.Name);
						Display->Items->Add("Health: " + (UnicodeString)Player1.health);
						Display->Items->Add("Dexterity: " + (UnicodeString)Player1.dexterity);
						Display->Items->Add("Strength: " + (UnicodeString)Player1.attack);
						Display->Items->Add("");
					}

					else{
                        Display->Items->Clear();
						Display->Items->Add("Vi ste: " + Player1.Name);
						Display->Items->Add("Životni bodovi: " + (UnicodeString)Player1.health);
						Display->Items->Add("Brznina: " + (UnicodeString)Player1.dexterity);
						Display->Items->Add("Snaga: " + (UnicodeString)Player1.attack);
						Display->Items->Add("");
					}
					break;
				default:
					if(Change == False)
						ShowMessage("This command is not supported!");
					else
						ShowMessage("Ova naredba nije podržana");
			}
		}
		else{
			 serverCom(Address,1);
			 Chat->Items->Add(Command->Text);
             messageHolder = Chat->Items->Text;

		}
		Command->Text="";
		Command->SetFocus();
		Key=0;
		//Potrebno da IDE ne zasvira kad se pritisne enter
	}
}

//Timer na intervalu od 70 uzima input strelica (Hvala profesoru Kovačeviću :) )
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

	if(Change==False){
		adjuster = 0;
	}
	else{
		adjuster = 16;
	}


	if(Grid[4].Contains=='n'){
		Enemy1->Left=5000;
	}
	if(Grid[6].Contains=='n'){
		Enemy2->Left=5000;
	}
	if(Grid[13].Contains=='n'){
		Enemy3->Left=5000;
	}
	if(Grid[14].Contains=='n'){
		Enemy4->Left=5000;
	}
	if(Grid[19].Contains=='n'){
		Enemy5->Left=5000;
	}



	bool keyUp = GetAsyncKeyState(VK_UP)& 0x8000;
	bool keyDown = GetAsyncKeyState(VK_DOWN)& 0x8000;
	bool keyLeft = GetAsyncKeyState(VK_LEFT)& 0x8000;
	bool keyRight = GetAsyncKeyState(VK_RIGHT)& 0x8000;

	if(keyUp == true){
		roomTracker=Grid[Player1.index-1].Soba;
		Player1.index=move(Player1,1);
		serverCom(Address,2);
	}

	if(keyRight == true){
		roomTracker=Grid[Player1.index-1].Soba;
		Player1.index=move(Player1,2);
		serverCom(Address,3);
	}

	if(keyDown == true){
		roomTracker=Grid[Player1.index-1].Soba;
		Player1.index=move(Player1,3);
		serverCom(Address,4);
	}

	if(keyLeft == true){
		roomTracker=Grid[Player1.index-1].Soba;
		Player1.index=move(Player1,4);
		serverCom(Address,5);
	}

	if(Grid[Player1.index-1].Soba!=roomTracker){
		//Riječ je o timer-u, bitno je da se prva linija koda postavi da se if nebi beskonacno izvršavao
		roomTracker = Grid[Player1.index-1].Soba;
		if(clearCounter == 14){
			Display->Items->Clear();
			clearCounter=0;
		}
		Display->Items->Add("");
		Display->Items->Add(getOpisSobe(Grid[Player1.index-1].Soba-1 + adjuster));
		clearCounter++;

	//Loše rješenje, htio sam ih stavit u vektor ili polje Enemy* ali je C++ builder bacao grešku na ispravnu sintaksu (provjereno u Visual studiju)
		if(Grid[Player1.index-1].Contains=='y'){
			if(Player1.index==5){
				Combat(&Player1, &First);
			}
			if(Player1.index==7){
				Combat(&Player1, &Second);
			}
			if(Player1.index==14){
				Combat(&Player1, &Third);
			}
			if(Player1.index==15){
				Combat(&Player1, &Forth);
			}
			if(Player1.index==20){
				Combat(&Player1, &Fifth);
			}

			Grid[Player1.index-1].Contains='n';
		}
	}
}



void __fastcall TForm1::MenuClick(TObject *Sender)
{
  sideMenu->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TCPServerExecute(TIdContext *AContext)
{
	int size = AContext->Connection->Socket->ReadLongInt();
	UnicodeString message = AContext->Connection->Socket->ReadString(size);
	AContext->Connection->Disconnect();

	if(message == "2mYrJwmSGRQY1PywIWll")
		Player2.index=move(Player2,1);
	else if(message == "h5pIFAWl6cHcSk4GYvEX")
		Player2.index=move(Player2,2);
	else if(message == "n4xyH0CqLu3m1aIlKbpP")
		Player2.index=move(Player2,3);
	else if(message == "HfyjOxUMKTcvAf8y15El")
		Player2.index=move(Player2,4);
	else
		Chat->Items->Add(message);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender){
	Player1.Name = CharName;
	Player1.attack=Attack+10;
	Player1.dexterity=Dexterity;


	//Prvi load
	Display->Items->Add(getOpisSobe(Grid[Player1.index-1].Soba-1 + adjuster));
	roomTracker = Grid[Player1.index-1].Soba;
}
//---------------------------------------------------------------------------

