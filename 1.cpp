#include<iostream>
#include<fstream>
using namespace std;
 typedef struct {
                    float greutate;
                    float profit;
                    float eficienta;
                } obiect;
obiect M[100];
float profit_total;
float G;
int n, ordi[100];;
ifstream f("input1.dat");
ofstream g("output1.dat");
 int read_data()
 {
     f>>n;
     f>>G;
     for(int i=1; i<=n; i++)
     {
         f>>M[i].greutate;
         f>>M[i].profit;
         ordi[i]=i;
     }
     for(int i=1; i<=n; i++)
     {
         M[i].eficienta=M[i].profit/M[i].greutate;
     }
 }
 int sort_data()
 {
     int terminat=1;
     do{
        terminat=1;
        for(int i=1; i<=n; i++)
        {
            if(M[i].eficienta<M[i+1].eficienta)
            {
                swap(M[i].eficienta,M[i+1].eficienta);
                swap(M[i].greutate,M[i+1].greutate);
                swap(M[i].profit,M[i+1].profit);
                swap(ordi[i],ordi[i+1]);
                terminat=0;
            }
        }
     }while(terminat);

 }
 float greedy_frumushelu()
 {
     int i=1;
     while(G>0 && i<=n)
     {
         if(G>M[i].greutate)
         {
             g<<"obiectul "<<ordi[i]<<" 1"<<endl;
             G-=M[i].greutate;
             profit_total+=M[i].profit;
         }
         else {
            g<<"obiectul "<<ordi[i]<<" "<<G/M[i].greutate;
            profit_total+=G/M[i].profit;
            G=0;
         }
         i++;
     }
     return profit_total;
 }
int main()
{
    read_data();
    sort_data();
    profit_total=greedy_frumushelu();
    g<<endl<<"profit= "<<profit_total;
}
