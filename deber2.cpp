#include <iostream>

//[IA START]
#include <iomanip>
#include <string>
#include <locale>
//[IA END]
//[ Es Para poder añadir las cosas faltantes al proyecto que no lo conseguia y segun la IA solo se puede hacer incluyendo estas librerias]
//[acepte todo lo que me sugirio en cuanto al contenido al uso de las nuevas librerias]

using namespace std;

int main() {
	
	char repetir = 's';
	
	while (repetir == 's' or repetir == 'S') {
		
		string divisa;
		cout<<"Ingrese la divisa base (3 letras solamente): ";
		cin>>divisa;
		
		while (divisa.length() != 3 or
		      !isalpha(divisa[0]) or
		      !isalpha(divisa[1]) or
		      !isalpha(divisa[2])) {
		    cout<<" Valor no valido ingrese exactamente 3 letras: ";
		    cin>>divisa;
		}
		
		string divisa_cotizada;
		cout<<"Ingresa la divisa a la que quieres transformar (3 letras): ";
		cin>>divisa_cotizada;
		    
		while (divisa_cotizada.length() != 3 or
		      !isalpha(divisa_cotizada[0]) or
		      !isalpha(divisa_cotizada[1]) or
		      !isalpha(divisa_cotizada[2])) {
		    cout<<" Valor no valido ingrese exactamente 3 letras: ";
		    cin>>divisa_cotizada;
		}
		
		double tasa;
		cout<<"Ingrese la tasa de cambio: ";
		cin>>tasa;
		    
		while (tasa <= 0 or cin.fail()) {
		    if (cin.fail()) {
		        cout<<"La tasa tiene que ser un numero"<<endl<<"Escriba de nuevo: ";
		    }
		    else if (tasa <= 0) {
		        cout<<"La tasa no puede ser cero o negativa"<<endl<<"Escriba de nuevo: ";
		    }
		    cin.clear();
		    cin.ignore(1000, '\n');
		    cin>>tasa;
		}
		
		double divisa_base;
		cout<<"Ingrese su monto: ";
		cin>>divisa_base;
		    
		while (divisa_base <= 0 or cin.fail()) {
		        
		    if (cin.fail()) {
		        cout<<"El valor tiene que ser un numero"<<endl<<"Escriba de nuevo: ";
		    }
		    else if (divisa_base <= 0) {
		        cout<<"El valor no puede ser cero o negativo"<<endl<<"Escriba de nuevo: ";
		    }
		        
		    cin.clear();
		    cin.ignore(1000, '\n');
		    cin>>divisa_base;
		}
		
		//[IA START]
		string timestamp;
		cout << "Ingrese el timestamp (ej: 2026-01-19 14:30:00): ";
		cin.ignore();
		getline(cin, timestamp);
		//[IA END]
		//[ usada en base a las librerias para pedir el tiempo]
		    
		long double resultado;
		resultado = divisa_base * tasa;
		
		cout << endl;
		cout << "=== CONVERSION DE DIVISAS ===" << endl;
		cout << "Par: " << divisa << "/" << divisa_cotizada << endl;
		
		cout << fixed << setprecision(6);
		cout << "Tasa: " << tasa << endl;
		
		cout << fixed << setprecision(2);
		cout.imbue(locale(""));
		cout << "Monto base: " << divisa_base << " " << divisa << endl;
		cout << "Monto convertido: " << resultado << " " << divisa_cotizada << endl;
		
		cout << "Timestamp: " << timestamp << endl;
		cout << "================================" << endl;
		
		cout<<"Desea realizar otro cambio? (s/n): ";
		cin>>repetir;
	}
	
	return 0;
}
