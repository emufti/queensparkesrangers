#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include<cstdlib>

using namespace std;

int main()
{
	srand (( unsigned ) time (0));
	double PVi,freq,marg,monthi,yeari,sigma,mu;
	int n;
	cout<<"Input the Present Value: ";
	cin>>PVi;cout<<endl;
	cout<<"Input frequency (1=annually, 2=semi-anually,4=quarterly,12=monthly): ";
	cin>>freq;cout<<endl;
	cout<<"Input number of Periods: ";
	cin>>n;cout<<endl;
	cout<<"Input Margin: ";
	cin>>marg;cout<<endl;
	cout<<"Input mean of the floating rate = ";
	cin>>mu;cout<<endl;
	cout<<"Input Standard deviation of the floating rate: ";
	cin>>sigma;cout<<endl;
	cout<<"Input your starting month: ";
	cin>>monthi;cout<<endl;
	cout<<"Input your stating year: ";
	cin>>yeari;cout<<endl;

	double PV[n+1],closingbal[n],install[n],floatingrate[n], interest[n], principal,periodic[n],per_year[n],per_month[n];
	PV[1]=PVi;
	per_month[1]=monthi;
	per_year[1]=yeari;
	principal=PVi/n;
	double u1,u2,z;


	for (int i=1;i<=n;i++)
  {
   u1 = rand()*(1.0 / RAND_MAX);
   u2 = rand()*(1.0 / RAND_MAX);
  z= sqrt(-2.0*log(u1))*cos(( 2.0 * (3.14159265358979323846))*u2);
  floatingrate[i]=mu+(sigma*z);

  cout<<floatingrate[i]<<endl;

  periodic[i]=(marg+floatingrate[i])/freq;
  interest[i]=periodic[i]*PV[i];
  install[i]=interest[i]+principal;
  closingbal[i]=PV[i]-principal;
	PV[i+1]=closingbal[i];

	per_year[i+1]=per_year[i];
	per_month[i+1]=per_month[i]+(12/freq);

	if (per_month[i+1]>12)
	{
		per_month[i+1]=per_month[i+1]-12;
		per_year[i+1]=per_year[i+1]+1;
	}
}


ofstream myfile3;
myfile3.open ("iheartrichardCase2.csv");
  myfile3 << "Period#, Date, Opening Balance, Principal, Floating Rate, Periodic Interest Rate, Interest, Installment, Closing Balance \n";
  for (int i=1; i<=n;i++)
  {

  	myfile3<<i<<","<<per_month[i]<<"/"<<per_year[i]<<","<<PV[i]<<","<<principal<<","<<floatingrate[i]<<","<<periodic[i]<<","<<interest[i]<<","<<install[i]<<","<<closingbal[i]<<endl;

  }
  myfile3.close();
}
