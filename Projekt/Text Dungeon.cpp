//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("sideForm.cpp", sideMenu);
USEFORM("connectForm.cpp", ConnectionForm);
USEFORM("characterCreation.cpp", Form3);
USEFORM("Inventory.cpp", Form4);
USEFORM("mainMenu.cpp", Form2);
USEFORM("mainForm.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TsideMenu), &sideMenu);
		Application->CreateForm(__classid(TConnectionForm), &ConnectionForm);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
