#include <iostream>
#include <stdlib.h>

using namespace std;

//funcao menu
char menu() 
{
	char op;
    cout << "\n----- Menu -----\n";
    cout << "X- Sair do programa\n";
    cout << "1- Converter binario para decimal.\n";
    cout << "2- Converter decimal para binario. \n";
    cout << "3- Converter velocidade em km/h para m/s. \n";
	cout << "4- Tabuada. \n";
	cout << "Insira a sua opcao: ";
	cin >> op;
	system("cls");
	return op;
}
//funcao submenu
double submenu()
{
	char tabu;
	cout << "\n----- SubMenu Tabuada -----\n";
	cout << "X- Sair do programa\n";
	cout << "1- Adicao\n";
	cout << "2- Subtracao\n";
	cout << "3- Divisao\n";
	cout << "4- Multiplicacao\n";
	cout << "Insira a sua opcao: ";
	cin >> tabu;
	system("cls");
	return tabu;
}

//funcao expoente
long long int expoente(int b,int e)
{ 
	long long int resultado = 1;
	if(e != 0){
		for(int i = 1; i <= e; i++)
		{
			resultado = resultado * b;
		}
	}
	return resultado;
}

//funcao converte Binario Para Decimal
int converteBinarioParaDecimal(long long int numbinario)
{
	int decimal = 0, i = 0, digito;
	while(numbinario != 0)
	{
		digito = numbinario % 10;
		numbinario = numbinario / 10;
		decimal = decimal + digito * expoente(2,i);
		i++;
	}
	return decimal;
}

//funcao converte Decimal Para binario
int decimalParaBinario(int deci){
    int binario = 0;
    int i = 0;
	int resto;
    while (deci > 0) {
		resto = deci % 2;
		deci = deci / 2;
        binario += resto * expoente(10,i);
        i++;
    }
	return binario;
}

//Funcao para verificar se o numero e binario
bool verificarBinario(long long int numbinario) {
	int digito;
	bool r = true;
    while (numbinario > 0) {
		digito = numbinario % 10;
        if (digito != 0 || digito != 1) {
            r = false;
        }
		cout << r << endl;
        numbinario = numbinario / 10;
    }
    return r;
}

//funcao converte km para m/s
double Kmh(double km){
	return km / 3.6;
}

//funcao para somar numeros inseridos
int soma(int num1, int num2){
	return num1 + num2;
}

//funcao para subtrair numeros inseridos
int retirar(int num3, int num4){
	return num3 - num4;
}

//funcao para dividir numeros inseridos
float divisao(float num5, float num6){
	return num5 / num6;
}

//funcao para multiplicar numeros inseridos
int multiplicar(int num7, int num8){
	return num7 * num8;
}

int main(){
	char op;
	char tabu;
	long long int numbinario;
	int deci;
	double velo;
	int tabua;
    do{
		op = menu();
        switch(op) {
            case 'x':
				cout << "Adeus!!\n";
                break;
				
            case 'X':
                cout << "Adeus!!\n";
                break;
				
            case '1':
                cout << "Insira um numero binario: ";
				cin >> numbinario;
				cout << "\nO numero binario inserido convertido para decimal e: " << converteBinarioParaDecimal(numbinario) << "\n";
                break;
				
            case '2':
                cout << "Digite numero decimal:";
				cin >> deci;
				cout << "\nO numero decimal inserido convertido para binario e: " << decimalParaBinario(deci) << "\n";
				break;
				
            case '3':
                cout << "Insira a velocidade em Km/h: ";
				cin >> velo;
				cout << "\nA velocidade inserida em km/h convertido fica: " << Kmh(velo) << " M/s \n";
                break;
				
			case '4':
				do{
					tabu = submenu();
					int num1, num2;
					int num3, num4;
					float num5, num6;
					int num7, num8;
					switch(tabu){
						case 'x':
							cout << "Adeus!!\n";
							break;
				
						case 'X':
							cout << "Adeus!!\n";
							break;
			
						case '1':
							cout << "Insira o 1 numero que quer somar : ";
							cin >> num1;
							cout << "Insira o 2 numero : ";
							cin >> num2;
							cout << "A soma dos numeros inseridos e " << soma(num1, num2);
							break;
						
						case '2':
							cout << "Insira o 1 numero que quer subtrair : ";
							cin >> num3;
							cout << "Insira o 2 numero : ";
							cin >> num4;
							cout << "A subtracao dos numeros inseridos e " << retirar(num3, num4);
							break;
							
						case '3':
							cout << "Insira o 1 real numero que quer dividir : ";
							cin >> num5;
							cout << "Insira o 2 numero real : ";
							cin >> num6;
							cout << "A divisao dos numeros inseridos e " << divisao(num5, num6);
							break;
							
						case '4':
							cout << "Insira o 1  numero que quer multiplicar : ";
							cin >> num7;
							cout << "Insira o 2 numero real : ";
							cin >> num8;
							cout << "A multiplicao dos numeros inseridos e " << multiplicar(num7, num8);
				    }
				} while (tabu != 'X' && tabu != 'x');
		}		
	} while (op != 'X' && op != 'x');
	return 0;
}