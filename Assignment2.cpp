//A complete program 
/*ID block  ---------------------------------------+ 
+ Programmer : 	Davis Yi  	           	+ 
+ Course     : 	Computer Science 1    	+ 
+ Assignment : 	Assignment 2	      	+ 
+ Due Date   : 	March 17 2009          	+ 
+----------------------------------------------------*/
 /*              
 Program statement *  This program will calculate salary for four different types of hourly employee. * 
 ************************ Analysis *****************************	  
 1. Data needed 	
	 Name (Full name first and last) 	
	 ddress (street, City, states, zip code) 	
	 SSN (No – needed read it as a long number) 	
	 Hours worked 	Hourly pay rate 	
	 Type of Benefit 	
	 Skill level  

 2. Constants given Skill level  
	 1 – $15.00
	 2 – $25.00 
	 3 – $72.00 
	 4 – $125.00  

	 Type of Benefits
	 0 - $0 
	 1 - $32.50 
	 2 - $52.50 
	 3 - $62.50  

	 Overtime rate 
	 40 ~ 50 – 1.5*(Pay rate*Hour) 
	 50 ~ 60 – 2*(Pay rate*Hour)  

	 Retirement plan for only Skill level 4 Up to 5% from original salary(2digit)  

	 Tax rate  
	 0 – 2000 = 0% 
	 2000.01 – 3000.00 = 3% of amount 
	 over $2000 3000.01 – 4000.00 = 1% of first $3000 + 5% of the remainder 
	 4000.01 – 5000.00 = 1% of first $3000 + 5% of the next $1000 + 7% of the remainder Over 
	 5000.01 =1% of first $3000 + 5% of the next $1000 + 7% of the next $1000 + 1% for every $1000 over $5000 
	 
3. Calculations 	
	 Overtime rate 	
	 	IF (Hour > 40) -> Hour – 40= Hour_2
		If (Hour_2 =< 10 ) -> 1.5*Hour_2
	    if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)
	 	Pay_rate = ((Original Hour-Over hour)*Payment of the skill rate) + Overtime rate 	

	 Retirement plan 	
	 If skill level 4 only 		   
	 	Pay rate * retirement rate = Retire contribution 	


	Subtotal = Pay rate - Benefit – Retire contribution 	 	
	Tax Calculation 	
		if Sub total is.. 	
			less than 2000 - skip 	
			2000.01 - 3000.00 = (sub total - 2000.01)*3% 	
			3000.01 - 4000.00 = (3000*1%) + {(sub total -3000)*5%} 	
			4000.01 - 5000.00 = (3000*1%) + (1000*5%) +{(sub total -4000)*7%} 	
			Over 5000.01 =  (3000*1%) + (1000*5%) +{1000*7%} + {X(1000*1%)} X= Pay_rate-5000 for over 5000.01 only, X must drop the decimals.  	  


4. Print results 	Full name of the Employee
	Tax ID(SSN)
	Adress
	Skill level
	Type of Benefit
	Tax amount owed
	Gross Salary
	Net Salary
	Retirement Contribution percentage(0 if not participating)
 
************************ Algorithm *****************************	
Step 1
Input
Prompt worker for Name (string)
First name Last name
Prompt worker for Social Security Number with no dashes (long)
Prompt worker for Address[street, zip, city, state] (string) Prompt worker for Hours Worked (float) Prompt worker for Pay Rate by skill level(float)
Prompt worker for Type of benefit (int)
Prompt worker for Type of skill level (int)
Prompt worker for rate of Retirement Contribution[level 4 only](float)
Step 2
Process
Overtime rate(Over_Pay) 		for over 40 hour -> (Hour – 40)= Hour_2
		If (Hour_2 =< 10 ) -> 1.5*Hour_2
     	if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)
	
Gross Salary
Gross_Sal = ((Hour-Hour_2)*Pay_rate) + Over_Pay
   	Retirement plan 	If skill level 4 only 		   Gross_Sal * rate_retire_con = retire_con_pay
	
Subtotal
Sub_tot = Gross_Sal – benefit – Retire_con_pay 
Tax Calculation if Sub total is.. less than 2000 = 0 2000.01 - 3000.00 = (sub_tot - 2000.01)*.03 3000.01 - 4000.00 = (3000*.01) + {(sub_tot -3000)*.05} 4000.01 - 5000.00 = (3000*.01) + (1000*.05) +{( sub_tot -4000)*.07} Over 5000.01 =  (3000*.01) + (1000*.05) +{1000*.07} + {X(1000*.01)}	 {X= Pay_rate-5000} - for over 5000.01 only, X must drop the decimals. 	




Step 3
Output
Print Full Name with an informative label on line 1 Print Social Security # with an informative label on line 2 Print Adress with an informative label on line 3  Print Skill level with an informative label on line 4
Print Type of benefit with an informative label on line 5 Print Tax amount owed with an informative label on line 6
Print Gross salary an informative label on line 7 Print Net salary with an informative label on line 8  Print retirement contribution percentage with an informative label on line 9
************************ End of Algorithm *****************************/	 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
//*declaration of variables*//
	int skill_lvl, type_ben;
	float hour, hour_2, pay_rate, benefit, over_pay, net_sal, tax_owed, gross_sal, gross_sal_retire, retire_con_pay,rate_retire_con;
	string fst_name, las_name, address, typ_ben, pay_rate_string;
	long ssn;
	cout<<left<<fixed<<setprecision(2);
	//*Input*//
	cout<<setw(20)<<"*****Welcome to Auto Salary Calculator*****"<<endl;
	cout<<setw(20)<<"What is your first name?"<<":";
	cin>>fst_name;
	cout<<setw(20)<<"What is your last name?"<<":";
	cin>>las_name;
	cout<<setw(20)<<"What is your adress?(Street, City, State, zipcode)"<<":";
	cin.ignore();
	getline(cin, address);
	cout<<setw(20)<<"what is your Social security number?(without dash)"<<":";
	cin>>ssn;
	cout<<endl;
	cout<<setw(20)<<"** Pay rate for each skill level **"<<endl;
	cout<<setw(20)<<"1 : $15.00/hr"<<endl;
	cout<<setw(20)<<"2 : $25.00/hr"<<endl;
	cout<<setw(20)<<"3 : $72.00/hr"<<endl;
	cout<<setw(20)<<"4 : $125.00/hr"<<endl;
	cout<<setw(20)<<"** Pay rate for each skill level **"<<endl;
	cout<<endl;
	cout<<setw(20)<<"what is your current skill level?(1~4)"<<":";
	cin>>skill_lvl;

	if(skill_lvl>4 || skill_lvl<1)
	{cout<<"Wrong interger please try again!!"<<endl;
	return 0;}




	//*Processing*//

	switch(skill_lvl){
		
		//*skill level is 1(no benefits, no retirement plan)*//
		case 1:{
			pay_rate=15.00;
			pay_rate_string="$15.00/hr";
			cout<<setw(20)<<"How many hours did you work?(0~60hr):";
			cin>>hour;			
			if(hour>60 || hour<0)
			{cout<<"\n\nThe Hour is out of range, please do it again\n"<<endl;
			return 0;};
					//**Overtime rate(Over_Pay)**//
			if (hour > 40)
			{hour_2=hour-40;
				if (hour_2 <= 10 )
				over_pay=(1.5*pay_rate)*hour_2;
				else
				if(hour_2 <=20)
					over_pay=((1.5*pay_rate)*10) + ((hour_2-10)*(pay_rate*2));}//end of overpay
						//*gross salary*//
			if(hour > 40)
				gross_sal=((hour-hour_2)*pay_rate)+(over_pay);
			else
			if(hour < 40)
				gross_sal=(hour*pay_rate);
			//*Tax Calculation*//
	if(gross_sal>=0 && gross_sal<=2000)
		{tax_owed=0;}
	else
	if(gross_sal>=2000.01 && gross_sal<=3000.00)
		{tax_owed=(.03*gross_sal);}
	else
	if(gross_sal>=3000.01 && gross_sal<=4000.00)
		{tax_owed=(.01*3000)+(.05*(gross_sal-3000));}
	else
	if(gross_sal>=4000.01 && gross_sal<=5000.00)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*(gross_sal-4000));}
	else
	if(gross_sal>=5000.01)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*1000)+(.01*(1000*static_cast<int>((gross_sal-5000)/1000)));};
	net_sal=gross_sal-tax_owed;

				 };
		break;

		//*skill level is 2(no retirement plan)*//
		case 2:{
			pay_rate=25.00;
			pay_rate_string="$25.00/hr";
			cout<<setw(20)<<"How many hours did you work?(0~60hr):";
			cin>>hour;
			if(hour>60 || hour<0)
			{cout<<"\n\nThe Hour is out of range, please do it again\n"<<endl;
			return 0;};
			//**Overtime rate(Over_Pay)**//
			if (hour > 40)
			{hour_2=hour-40;
				if (hour_2 <= 10 )
				over_pay=(1.5*pay_rate)*hour_2;
				else
				if(hour_2 <=20)
					over_pay=((1.5*pay_rate)*10) + ((hour_2-10)*(pay_rate*2));}//end of overpay
			//*benefit*//
		cout<<endl;
		cout<<setw(20)<<"** Pay rate for each benefit **"<<endl;
		cout<<setw(20)<<"0 : None"<<endl;
		cout<<setw(20)<<"1 : Medical Insurance($32.50)"<<endl;
		cout<<setw(20)<<"2 : Dental and Medical($52.50)"<<endl;
		cout<<setw(20)<<"3 : Dental, Medical, and long term care($62.50)"<<endl;
		cout<<setw(20)<<"** Pay rate for each benefit **"<<endl;
		cout<<endl;
			cout<<setw(20)<<"What is your current benefit code?(0~3):";
			cin>>type_ben;
				if(type_ben>3 || type_ben<0)//benefit correction
				{cout<<"Wrong interger please try again!!"<<endl;
				return 0;}
					switch(type_ben)
					{
					case 0:benefit=0;
						typ_ben="None";
						break;
					case 1:benefit=32.50;
						typ_ben="Medical Insurance";
						break;
					case 2:benefit=52.50;
						typ_ben="Dental & Medical Insurance";
						break;
					case 3:benefit=62.50;
						typ_ben="Dental, Medical, and long term Insurance";
					break;}

			//*gross salary*//
			if(hour > 40)
				gross_sal=(((hour-hour_2)*pay_rate)+(over_pay))-benefit;
			else
			if(hour < 40)
				gross_sal=(hour*pay_rate)-benefit;
			//*Tax Calculation*//
	if(gross_sal>=0 && gross_sal<=2000)
		{tax_owed=0;}
	else
	if(gross_sal>=2000.01 && gross_sal<=3000.00)
		{tax_owed=(.03*gross_sal);}
	else
	if(gross_sal>=3000.01 && gross_sal<=4000.00)
		{tax_owed=(.01*3000)+(.05*(gross_sal-3000));}
	else
	if(gross_sal>=4000.01 && gross_sal<=5000.00)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*(gross_sal-4000));}
	else
	if(gross_sal>=5000.01)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*1000)+(.01*(1000*static_cast<int>((gross_sal-5000)/1000)));};
	net_sal=gross_sal-tax_owed;
			   };
		break;

		//*skill level is 3(no retirement plan)*//
		case 3:{
			pay_rate=72.00;
			pay_rate_string="$72.00/hr";
			cout<<setw(20)<<"How many hours did you work?(0~60hr):";
			cin>>hour;
			if(hour>60 || hour<0)
			{cout<<"\n\nThe Hour is out of range, please do it again\n"<<endl;
			return 0;};
			//**Overtime rate(Over_Pay)**//
			if (hour > 40)
			{hour_2=hour-40;
				if (hour_2 <= 10 )
				over_pay=(1.5*pay_rate)*hour_2;
				else
				if(hour_2 <=20)
					over_pay=((1.5*pay_rate)*10) + ((hour_2-10)*(pay_rate*2));}//end of overpay
			//*benefit*//
		cout<<endl;
		cout<<setw(20)<<"** Pay rate for each benefit **"<<endl;
		cout<<setw(20)<<"0 : None"<<endl;
		cout<<setw(20)<<"1 : Medical Insurance($32.50)"<<endl;
		cout<<setw(20)<<"2 : Dental and Medical($52.50)"<<endl;
		cout<<setw(20)<<"3 : Dental, Medical, and long term care($62.50)"<<endl;
		cout<<setw(20)<<"** Pay rate for each benefit **"<<endl;
		cout<<endl;
			cout<<setw(20)<<"What is your current benefit code?(0~3):";
			cin>>type_ben;
				if(type_ben>3 || type_ben<0)//benefit correction
				{cout<<"Wrong interger please try again!!"<<endl;
				return 0;};
					switch(type_ben)
					{
					case 0:benefit=0;
						typ_ben="None";
						break;
					case 1:benefit=32.50;
						typ_ben="Medical Insurance";
						break;
					case 2:benefit=52.50;
						typ_ben="Dental & Medical Insurance";
						break;
					case 3:benefit=62.50;
						typ_ben="Dental, Medical, and long term Insurance";
					break;}


			//*gross salary*//
			if(hour > 40)
				gross_sal=(((hour-hour_2)*pay_rate)+(over_pay))-benefit;
			else
			if(hour < 40)
				gross_sal=(hour*pay_rate)-benefit;
			//*Tax Calculation*//
	if(gross_sal>=0 && gross_sal<=2000)
		{tax_owed=0;}
	else
	if(gross_sal>=2000.01 && gross_sal<=3000.00)
		{tax_owed=(.03*gross_sal);}
	else
	if(gross_sal>=3000.01 && gross_sal<=4000.00)
		{tax_owed=(.01*3000)+(.05*(gross_sal-3000));}
	else
	if(gross_sal>=4000.01 && gross_sal<=5000.00)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*(gross_sal-4000));}
	else
	if(gross_sal>=5000.01)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*1000)+(.01*(1000*static_cast<int>((gross_sal-5000)/1000)));};
	net_sal=gross_sal-tax_owed;

			   
			   };
		break;

		//*skill level is 4*//
		case 4:{
			pay_rate=125.00;
			pay_rate_string="$125.00/hr";
			cout<<setw(20)<<"How many hours did you work?(0~60hr):";
			cin>>hour;
			if(hour>60 || hour<0)
			{cout<<"\n\nThe Hour is out of range, please do it again\n"<<endl;
			return 0;};
			//**Overtime rate(Over_Pay)**//
			if (hour > 40)
			{hour_2=hour-40;
				if (hour_2 <= 10 )
				over_pay=(1.5*pay_rate)*hour_2;
				else
				if(hour_2 <=20)
					over_pay=((1.5*pay_rate)*10) + ((hour_2-10)*(pay_rate*2));}//end of overpay
			//*benefit*//
		cout<<endl;
		cout<<setw(20)<<"** Pay rate for each benefit **"<<endl;
		cout<<setw(20)<<"0 : None"<<endl;
		cout<<setw(20)<<"1 : Medical Insurance($32.50)"<<endl;
		cout<<setw(20)<<"2 : Dental and Medical($52.50)"<<endl;
		cout<<setw(20)<<"3 : Dental, Medical, and long term care($62.50)"<<endl;
		cout<<setw(20)<<"** Pay rate for each benefit **"<<endl;
		cout<<endl;
			cout<<setw(20)<<"What is your current benefit code?(0~3):";
			cin>>type_ben;
				if(type_ben>3 || type_ben<0)//benefit correction
				{cout<<"Wrong interger please try again!!"<<endl;
				return 0;}
					switch(type_ben)
					{
					case 0:benefit=0;
						typ_ben="None";
						break;
					case 1:benefit=32.50;
						typ_ben="Medical Insurance";
						break;
					case 2:benefit=52.50;
						typ_ben="Dental & Medical Insurance";
						break;
					case 3:benefit=62.50;
						typ_ben="Dental, Medical, and long term Insurance";
					break;}

			//*retirement plan*//
					cout<<setw(20)<<"What is your contribution rate?(0%~5%,number up to 2 decimal points only):";
			cin>>rate_retire_con;
				if(rate_retire_con>5 || rate_retire_con<0)//retirement plan rate correction
				{cout<<"Wrong interger please try again!!"<<endl;
				return 0;}
			rate_retire_con=(rate_retire_con/100);
			//*gross salary for Retirement plan and it's calculation*//
			if(hour > 40)
				gross_sal_retire=(((hour-hour_2)*pay_rate)+(over_pay));
			else
			if(hour < 40)
				gross_sal_retire=(hour*pay_rate);
			retire_con_pay=(gross_sal_retire*rate_retire_con);
			//*gross salary*//
			if(hour > 40)
				gross_sal=(((((hour-hour_2)*pay_rate)+(over_pay))-benefit)-retire_con_pay);
			else
			if(hour < 40)
				gross_sal=((hour*pay_rate)-benefit)-retire_con_pay;
			//*Tax Calculation*//
	if(gross_sal>=0 && gross_sal<=2000)
		{tax_owed=0;}
	else
	if(gross_sal>=2000.01 && gross_sal<=3000.00)
		{tax_owed=(.03*gross_sal);}
	else
	if(gross_sal>=3000.01 && gross_sal<=4000.00)
		{tax_owed=(.01*3000)+(.05*(gross_sal-3000));}
	else
	if(gross_sal>=4000.01 && gross_sal<=5000.00)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*(gross_sal-4000));}
	else
	if(gross_sal>=5000.01)
		{tax_owed=(.01*3000)+(.05*1000)+(.07*1000)+(.01*(1000*static_cast<int>((gross_sal-5000)/1000)));};
	net_sal=gross_sal-tax_owed;


			   };
		break;

	}


	//*output*//
	cout<<"\n\n"<<endl;
	cout<<"*************************************result***********************************"<<endl;
	cout<<endl;
	cout<<setw(20)<<"Name :"<<fst_name<<" "<<las_name<<endl;
	cout<<setw(20)<<"Tax id(SSN) :"<<ssn<<endl;
	cout<<setw(20)<<"Adress :"<<address<<endl;
	cout<<setw(20)<<"Skill level :"<<skill_lvl<<"("<<pay_rate_string<<")"<<endl;
	if(skill_lvl>1)
	{cout<<setw(20)<<"Type of Benefit :"<<type_ben<<"("<<typ_ben<<")"<<endl;};
	if(skill_lvl==1)
	{cout<<setw(20)<<"Type of Benefit :"<<"N/A"<<endl;};
	cout<<setw(20)<<"Tax amount owed :"<<"$"<<tax_owed<<endl;
	cout<<setw(20)<<"Gross Salary :"<<"$"<<gross_sal<<endl;
	cout<<setw(20)<<"Net Salary :"<<"$"<<net_sal<<endl;
	if(skill_lvl==4){
		cout<<setw(20)<<"Retirement contribution Percentage :"<<(rate_retire_con*100)<<"%"<<endl;}
	if(skill_lvl<4){
		cout<<setw(20)<<"Retirement contribution Percentage : "<<"N/A"<<endl;}
	cout<<endl;
	cout<<"*************************************result***********************************"<<endl;
	cout<<"\n\n"<<endl;
	return 0;
}
