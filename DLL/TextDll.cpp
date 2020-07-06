//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you

#pragma hdrstop
#pragma argsused

#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;


//glavni sorter, svaku pojedinacnu naredbu koju korisnik može unjeti ovdje razvrstava
extern "C" int __declspec(dllexport) __stdcall functionSort(string inputedCommand){
		if(inputedCommand=="!Strike" || inputedCommand=="!Napadni"){
			return 1;
		}

		if (inputedCommand=="!Use" || inputedCommand=="!Iskoristi") {
			return 2;
		}

		if (inputedCommand=="!Me" ||  inputedCommand=="!Opis"){
			return 3;
		}

		else{
		   return 0;
		}
	}
	
//povezano sa funkcijom strike
extern "C" int __declspec(dllexport) __stdcall dodgeCalculator(int dodgeAtacker, int dodgeDefender){
	srand (time(NULL));
	return (dodgeAtacker + (rand()%20+1)) - (dodgeDefender + (rand()%20+1));
}
	

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

