	
    #include <iostream>
    
    using namespace std;

    int main() {
		int n = 5;

		cout << endl;

	// Cuadrado
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << "*";
			}
			cout << endl;
		}

		cout << endl;

	// Triangulo rectangulo 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cout << "*";
			}
			cout << endl;
		}

		cout << endl;

	// Triangulo rectangulo invertido
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				cout << "*";
			}
			cout << endl;
		}

		cout << endl;

	// Piramide hueca
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= (n * 2) - 1; j++) {
				if (j == n - (i - 1) || j == n + (i - 1) || i == n) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}

			cout << endl;
    }

    system("pause>0");
    return 0;
    }