#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    int n, i, j, t, r;
    string s;
    bool scambi;

    scambi=true;
    i=0;
    
    do {
        cout<<"Inserire il numero di automobili"<<endl;
        cin>>n;
    } while(n<=0);

    vector<string> nomi(n);
    vector<float> pos(n);

    for (i=0; i<n; i++) {
        
        cout<<"Inserisci nomi"<<endl;
        cin>>nomi[i];

        pos[i]= 1+rand() % n+1;
        r=pos[i];

        j=0;
        while (j<=i-1) {
            if (r=pos[j]) {
                r=r+1;
            }
            else
            {
                j=j+1;
            }
            
            if (r>n) {
                r=1;
            }
            j=0;
        }
        pos[i]=r;
    }
    
    i=0;
    while (i<n-1 and scambi==true) {
        scambi=false;
        j=0;

        while (j<=(n-2)-i) {
            
            if (pos[j]<pos[j+1]) {
                
                t=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=t;

                s=nomi[j];
                nomi[j]=nomi[j+1];
                nomi[j]=s;

                scambi=true;
            }

            j=j+1;
        }
        
        i=i+1;
    }

    cout<<"Nomi:";
    for (i=0; i<n; i++) {
        cout<<nomi[i]<<"; ";
    }

    cout<<"Posizione: ";
    for (i=0; i<n; i++) {
        cout<<pos[i]<<"; ";
    }
}

//LEGGERE LE ISTRUZIONI NEL FILE README.md
