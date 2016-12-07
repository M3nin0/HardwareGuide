/*
###########################################
# Criador original: Mazitek               #
# Adaptado por: Grupo nº 2 - Hardware     #
# Versão 0.4 							  #
# Ultima modificação: 12/11/2016          #
###########################################

# Requisitos:

	*inpout32.dll

# Importante:

	*Leia sobre as portas paralelas antes de utilizar o programa

*/

#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;
unsigned int microseconds = 199519;
unsigned int sequencia = 999999;

typedef short _stdcall (*inpfuncPtr)(short portaddr);
typedef void _stdcall (*oupfuncPtr)(short portaddr, short datum);

int main()
{
    HINSTANCE hLib;
    inpfuncPtr in;
    oupfuncPtr out;


hLib = LoadLibrary("inpout32.dll");
if (hLib == NULL) {
cout<<"Falha!A biblioteca não foi carregada.\n";
cin.get();
return -1;
}
in = (inpfuncPtr) GetProcAddress(hLib, "Inp32");
if (in == NULL) {
cout<<"Inp32 Falhou!Erro no GetProcAddress\n";
cin.get();
return -1;
}
out = (oupfuncPtr) GetProcAddress(hLib, "Out32");
if (out == NULL) {
cout<<"Out32 Falhou!Erro no GetProcAddress\n";
cin.get();
return -1;
}
int x,i;

do
{
cout<<">=>                     >=>" << endl; 
cout<<">=>                     >=>" << endl;
cout<<">=>         >==>        >=>"	<< endl; 
cout<<">=>       >>   >=>   >=>>=>"	<< endl;
cout<<">=>       >>===>>=> >>  >=>"	<< endl;
cout<<">=>       >>        >>  >=>"	<< endl; 
cout<<">=======>  >====>    >=>>=>"	<< endl;
cout<<"" << endl;
cout<<"\nFaça sua escolha\n";
cout<<"0. Sair\n";
cout<<"1. Acende todos os LEDs \n";
cout<<"2. Apaga todos os LEDs\n";
cout<<"3. Acende LED D0\n";
cout<<"4. Acende LED D1\n";
cout<<"5. Acende LED D2\n";
cout<<"6. Acende LED D3\n";
cout<<"7. Acende LED D4\n";
cout<<"8. Acdende LED D5\n";
cout<<"9. Acende LED D6\n";
cout<<"10. Acende LED D7\n";
cout<<"11. Pisca-Pisca\n";
cout<<"12. Sequencial\n";
cin>>x;
if (x==1)
{
    out(0x378,0xFF);   //Liga todos os leds, HEX(0xFF) == DEC(255)
    cout<<"Todas as LEDs foram acionadas\n";
}

else if(x==2)
{
    out(0x378,0);   //Desliga todas as portas, enviando um valor 0
    cout<<"Todos os LEDs foram desligados\n";
}

else if(x==3){
	
	out(0x378,1);
	cout<<"LED: D0 Ativado!\n";
}


else if(x==4){
	
	out(0x378,2);
	cout<<"LED: D1 Ativado!\n";
}


else if(x==5){
	
	out(0x378,4);
	cout<<"LED: D2 Ativado!\n";;
}

else if(x==6){

	out(0x378,8);
	cout<<"LED: D3 Ativado!\n";
}

else if(x==7){
	
	out(0x378,16);
	cout<<"LED: D4 Ativado!\n";
}

else if(x==8){
	
	out(0x378,32);
	cout<<"LED: D5 Ativado!\n";
}

else if(x==9){
	
	out(0x378,64);
	cout<<"LED: D6 Ativado!\n";
}

else if(x==10){
	
	out(0x378,128);
	cout<<"LED: D7 Ativado!\n";
}

else if(x==11){
	cout<<"Modo Pisca-Pisca\n";
	for (i=0; i<=128; i++){
		
		out(0x378,i);
		usleep(microseconds);
	}
}

else if(x==12){
	cout<<"Modo Sequencial\n";
	for (i=0;i<=128; i++){
		
		out(0x378,i);
		usleep(sequencia);
	}
}
}
while (x != 0);

return 0;
}
