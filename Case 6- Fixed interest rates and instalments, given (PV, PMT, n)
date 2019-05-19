#include <iostream>

#include <fstream>

#include <ctime>

#include <cstring>

#include <cmath>

#include <cstdlib>

#define epsilon 0.0001



using namespace std;


class Functions

{  public:


double func(double r0, double PVi, double PMTi, int n)
{
return	n*log(1+r0)+ log(PMTi-PVi*r0)-log(PMTi);

}


double  derivfunc(double r0, double PVi,double PMTi,int n)
{
return  (n/(1+r0))- ((PVi)/(PMTi-PVi*r0));
}



void newtonRaphson(double r0, double PVi, double PMTi, int n)
{
      double  h = func(r0, PVi, PMTi, n) / derivfunc(r0, PVi, PMTi, n);
 while (abs(h) >= epsilon)
 {
     h = func(r0, PVi, PMTi, n)/derivfunc(r0, PVi, PMTi, n);

     r0 = r0- h;
 }
	
}

};

		double inval(double PVi, double n, double r)
			{
			return (PVi*r*(1+(1/(pow(1+r,n)-1))));
			}
			
			
int main()



{


    srand (( unsigned ) time (0));


	int n;



    double  PVi,PMTi,freq,monthi,yeari;



cout<<"Input the present value: ";
cin>>PVi;cout<<endl;

cout<<"Input the Installment value: ";
cin>>PMTi;cout<<endl;

cout<<"Input frequency (1=annually, 2=semi-anually,4=quarterly,12=monthly): ";
cin>>freq;cout<<endl;


cout<<"Input number of Periods: ";
cin>>n;cout<<endl;

cout<<"Input your starting month: ";
cin>>monthi;cout<<endl;


cout<<"Input your starting year: ";
cin>>yeari;cout<<endl;

//double r0=0.0001;

 //r1= newtonRaphson(r0, PVi, PMTi, n);

double  PV[n+1], closingbal[n], interest[n], principal[n], r, periodic, per_year[n], per_month[n];

double rlow=0;
double rhigh=1;
double rmid;
double errorr;

do
{
  
{	
rmid=rlow+((rhigh-rlow)/2);
if (inval(PVi,n,rmid)-PMTi>0)
{
	rhigh=rmid;			
}
	else if(inval(PVi,n,rmid)-PMTi<0)
{
        rlow=rmid;
						
}
		
	errorr=abs((inval(PVi,n,rmid)-PMTi)-0);
		
}

}while (errorr>=0.001);
r=rmid;



PV[1]=PVi;



per_month[1]=monthi;


per_year[1]=yeari;




	for (int i=1;i<=n;i++)

  {


  interest[i]=r*PV[i];

  principal[i]= PMTi-interest[i];


  closingbal[i]=PV[i]-principal[i];


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


  myfile3.open ("iheartyassaminCase6.csv");



  myfile3 << "Period#, Date, Opening Balance, Principal, Periodic Interest Rate, Interest, Installment, Closing Balance \n";



  for (int i=1; i<=n;i++)




  {





  myfile3<<i<<","<<per_month[i]<<"/"<<per_year[i]<<","<<PV[i]<<","<<principal[i]<<","<<r*100<<"%"<<","<<interest[i]<<","<<PMTi<<","<<closingbal[i]<<endl;





  }







  myfile3.close();







}

