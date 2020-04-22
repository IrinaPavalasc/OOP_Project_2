#include<iostream>
#include<fstream>
#include<algorithm>
#include<exception>
using namespace std;
ifstream f("Text.txt");
class Vector
{
    int* V;
    int len;
    public:
        ///constructor initializare
        Vector() {
            len = 0;
            V = new int[100];
           
            }
        ///Constructor paramentrizat
        Vector(int n, int* a) {
            V = new int[100];
            len = n;
            for (int i = 0; i < len; i++)
                V[i] = a[i];
            
        }
        ///constructor de copiere
        Vector(const Vector& a)
        {
            V = new int[100];
            len = a.len;
            for (int i = 0; i < len; i++)
                V[i] = a.V[i];
        }
        int get(int i) {
            return V[i];
        }
        int getlen() {
            return len;
        }
        void setlen(int x) {
            len = x;
        }
        void add(int x) {
            V[len++] = x;
        }
        ///supraincarcarea =;
        Vector& operator = (const Vector& W)
        {
            if (this != &W)
             len = W.len;
              
         for (int i = 0; i < W.len; i++)
              V[i] = W.V[i];
            
            return *this;
        }
     
        ///supraincarcarea []
         int& operator [] (int i) const {
            return V[i];
        }
        
        ///supraincarcarea >>
        friend istream& operator >> (istream& os, Vector& W)
        {
            cout << "len= ";
            os >> W.len;
            for (int i = 0; i < W.len; i++)
                os >> W.V[i];
            return os;
        }

        ///supraincarcarea <<
        friend ostream& operator << (ostream& os, Vector& W)
        {
            
            for (int i = 0; i < W.len; i++)
                os << W.V[i];
            return os;
        }
        ///destructor
        ~Vector()
        {
            delete[]V;
        }
};

class Nr_Natural_Mare {
    protected:
    int nrcif;
    Vector T;
    public:
        ///constructor de initializare
        Nr_Natural_Mare() {
            nrcif = 0;
            
        }
        ///constructor cu paramentrii
        Nr_Natural_Mare(int nr, Vector v) {
            nrcif = nr;
            int i;
            for(i=0;i<nrcif;i++)
                T[i] = v[i];
          
         }
        
        ///supraincarcarea =;
        Nr_Natural_Mare operator = ( const Nr_Natural_Mare& W)
        {
            nrcif = W.nrcif;

            for (int i = 0; i < W.nrcif; i++)
                T[i] = W.T[i];

            return *this;
        }
        ///supraincarcarea []
        int& operator [] (int i){
            return T[i];
        }
  
        ///constructor de copiere
          Nr_Natural_Mare( Nr_Natural_Mare& A)
          {
             
            nrcif = A.nrcif;
            
         
            for (int i = 0; i < nrcif; i++)
                T[i] = A.T[i];
            
        }
    
       
        ///supraincarcarea >>
        friend istream& operator >> (istream& os, Nr_Natural_Mare &W)
        {
            cout << "nrcif= ";
            os >> W.nrcif;
            for (int i = 0; i < W.nrcif; i++)
                os >> W.T[i];
            return os;
        }

        ///supraincarcarea <<
        friend ostream& operator << (ostream& os, Nr_Natural_Mare& W)
        {
           
            for (int i = 0; i < W.nrcif; i++)
                os << W.T[i];
            return os;
        }
        virtual void afisare() {
            cout << "Numar Natural Mare:" << *this <<endl;
        }
        ///destructor
        ~Nr_Natural_Mare()
        {
            nrcif = 0;
            
        }
};
class Nr_Fibonacci_Mare : public Nr_Natural_Mare {
public:
    ///contructor fara parametrii
    Nr_Fibonacci_Mare():Nr_Natural_Mare(){}
    ///constructor cu parametrii
    Nr_Fibonacci_Mare(int nr, Vector v) :Nr_Natural_Mare(nr, v) {}
    ///contructor de copiere
    Nr_Fibonacci_Mare( Nr_Fibonacci_Mare& W) :Nr_Natural_Mare(W) { }
    ///supraincarcarea lui =
    Nr_Fibonacci_Mare& operator =(const Nr_Fibonacci_Mare& W) {
        if (this != &W)
            Nr_Natural_Mare::operator =(W);
        return *this;

    }
    ///supraincarcarea >>
    friend istream& operator >> (istream& os, Nr_Fibonacci_Mare& W)
    {
        cout << "nrcif= ";
        os >> W.nrcif;
        for (int i = 0; i < W.nrcif; i++)
            os >> W.T[i];
        return os;
    }

    ///supraincarcarea <<
    friend ostream& operator << (ostream& os,Nr_Fibonacci_Mare& W)
    {

        for (int i = 0; i < W.nrcif; i++)
            os << W.T[i];
        return os;
    }
    ///supraincarcarea lui +
   
    Nr_Fibonacci_Mare operator +(Nr_Fibonacci_Mare& W)
    {
        Nr_Fibonacci_Mare VV;
        
        VV.nrcif = max(W.nrcif, nrcif);
            int n, p;
            int k = VV.nrcif-1;
            int i = W.nrcif-1;
            int j = nrcif-1;

            
            while (k >= 0)
            {
                if (i >= 0 && j >= 0)
                {
                    VV.T[k] = W.T[i] + T[j];
                    
                    i--; j--; k--;
                }
                else
                if (i < 0 && j >= 0)
                {
                    VV.T[k] = T[j];
                    j--; k--;
                }
                else
                if (i >= 0 && j < 0)
                {
                    VV.T[k] = W.T[i];
                    i--; k--;
                }
            }
           
          
            k = nrcif - 1; 
            p = W.nrcif - 1;
            
            if (k > 0 || p > 0)
            {
                for (n = max(k,p); n > 0; n--)
                    if (VV.T[n] >= 10)
                    {
                        VV.T[n - 1]++;
                        VV.T[n] = VV.T[n] % 10;
                    }
               
                if (VV.T[0] >= 10)
                {
                    VV.nrcif++;
                    
                    for (j = VV.nrcif - 1; j > 0; j--)
                        VV.T[j] = VV.T[j - 1];
                  
                    VV.T[0] = 1;
                    VV.T[1] = VV.T[1] % 10;
                }
            }
            else if (k == 0 && p == 0 && VV.T[0] >= 10){
                
                    VV.T[k + 1] = VV.T[k] % 10;
                    VV.T[k] = VV.T[k] / 10;
                    VV.nrcif = 2;
                
            }
       return VV; 

    }
    int getnrcif() {
        return nrcif;
    }
    ///supraincarcarea lui <
    int operator <(Nr_Fibonacci_Mare& W) {
        if (nrcif > W.nrcif)
            return 0;
        else if (nrcif < W.nrcif)
            return 1;
        int i=0;
        while(i<nrcif)
        {
            if (T[i] > W.T[i])
            
                return 0;
            
            else if (T[i] < W.T[i])
            
            
                return 1;
            
            else if (T[i] == W.T[i])
                i++;
        }
        return 0;
    }
    

   void afisare() {
        int* v1=new int[1];
        v1[0] = 0;
        int* v2=new int[1];
        v2[0] = 1;
        Vector a(1, v1);
        Nr_Fibonacci_Mare A(1, a);
    
        Vector b(1, v2);
        Nr_Fibonacci_Mare B(1, b);
        Nr_Fibonacci_Mare C;
        Nr_Fibonacci_Mare D;
        Nr_Fibonacci_Mare E;
        
        
        while(A+B<*this){
            
            D = C;
           
            C = A + B;
            
            A = B;
            
            B = C;
          
        }

        E = A + B;
        try{
            if (*this < E)
                throw int();

            cout << D << "+" << C << "=" << E << endl;
        }
        catch (int) {
            cout << "Numarul nu este fibonacci";
        }
        
    }

};
int n,m,i,j,k,p;
Vector V;
int main()
{   
    cin >> n;
    for(i=0;i<=n;i++)
    { 
        cin >> m;
            V.setlen(m);

            try {
                for (j = 0; j < m; j++)
                {
                    cin >> V[j];

                    if (V[j] < 0)
                        throw int();
                    if (V[j] >= 10)
                        throw 'a';
                    if (V[j] != int(V[j]))
                        throw int();

                }

                Nr_Fibonacci_Mare W(m, V);
                W.afisare();
            }

            catch (int) {
                cout << "Se pot introduce doar numere naturale";

            }
            catch (char) {
                cout << "Se pot introduce doar cifre";
            }
        
    }

    
    
}

