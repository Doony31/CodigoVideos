	
    #include <iostream>
    
    using namespace std;

    int main() {

        int n = 5;
        int repetir = 4;

        for (int k = 1; k <= repetir; k++) {
            for (int i = 1; i <= n; i++) {
                for (int l = 1; l <= (n) * (k - 1); l++) {
                    cout << " ";
                }
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
        }

    system("pause>0");
    return 0;
    }