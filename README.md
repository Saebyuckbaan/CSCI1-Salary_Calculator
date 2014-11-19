CSCI1-Salary_Calculator
=======================

<b>2nd Assignment in CSCI1</b>

//A complete program <br>


ID block  ---------------------------------------+ <br>
+ Programmer : 	Davis Yi  	           	+  <br>
+ Course     : 	Computer Science 1    	+ <br>
+ Assignment : 	Assignment 2	      	+ <br>
+ Due Date   : 	March 17 2009          	+ <br>
+----------------------------------------------------
<br>



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

2. Constants given Skill level  <br>
	1 – $15.00<br>
	2 – $25.00 <br>
	3 – $72.00 <br>
	4 – $125.00  <br>

	Type of Benefits<br>
	0 - $0 <br>
	1 - $32.50 <br>
	2 - $52.50 <br>
	3 - $62.50  <br>

	Overtime rate <br>
	40 ~ 50 – 1.5*(Pay rate*Hour) <br>
	50 ~ 60 – 2*(Pay rate*Hour)  <br>
	Retirement plan for only Skill level 4 Up to 5% from original salary(2digit)  <br>

	Tax rate  
	0 – 2000 = 0% <br>
	2000.01 – 3000.00 = 3% of amount <br>
	over $2000 3000.01 – 4000.00 = 1% of first $3000 + 5% of the remainder <br>
	4000.01 – 5000.00 = 1% of first $3000 + 5% of the next $1000 + 7% of the remainder Over <br>
	5000.01 =1% of first $3000 + 5% of the next $1000 + 7% of the next $1000 + 1% for every $1000 over $5000 <br>
	
3. Calculations 	
	 Overtime rate 	<br>
	 	IF (Hour > 40) -> Hour – 40= Hour_2<br>
		If (Hour_2 =< 10 ) -> 1.5*Hour_2<br>
	    if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)<br>
	 	Pay_rate = ((Original Hour-Over hour)*Payment of the skill rate) + Overtime rate 	<br>

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
	Tax ID(SSN)<br>
	Adress<br>
	Skill level<br>
	Type of Benefit<br>
	Tax amount owed<br>
	Gross Salary<br>
	Net Salary<br>
	Retirement Contribution percentage(0 if not participating)<br>
 
************************ Algorithm *****************************	
<b>Step 1 - Input<br> </b>
Prompt worker for Name (string)<br>
First name Last name<br>
Prompt worker for Social Security Number with no dashes (long)<br>
Prompt worker for Address[street, zip, city, state] (string) <br>
Prompt worker for Hours Worked (float) <br>
Prompt worker for Pay Rate by skill level(float)<br>
Prompt worker for Type of benefit (int)<br>
Prompt worker for Type of skill level (int)<br>
Prompt worker for rate of Retirement Contribution[level 4 only](float)<br>


<b>Step 2 -  Process<br> </b>
Overtime rate(Over_Pay) 		<br>
    for over 40 hour -> (Hour – 40)= Hour_2<br>
		If (Hour_2 =< 10 ) -> 1.5*Hour_2<br>
    if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)<br>
	
Gross Salary<br>
Gross_Sal = ((Hour-Hour_2)*Pay_rate) + Over_Pay<br>
   	Retirement plan 	If skill level 4 only 		   <br>
    Gross_Sal * rate_retire_con = retire_con_pay<br>
	
Subtotal<br>
Sub_tot = Gross_Sal – benefit – Retire_con_pay<br> 
Tax Calculation if Sub total is.. <br>
less than 2000 = 0 2000.01 - 3000.00 = (sub_tot - 2000.01)*.03 <br>
3000.01 - 4000.00 = (3000*.01) + {(sub_tot -3000)*.05}<br>
4000.01 - 5000.00 = (3000*.01) + (1000*.05) +{( sub_tot -4000)*.07} <br>
Over 5000.01 =  (3000*.01) + (1000*.05) +{1000*.07} + {X(1000*.01)}	 <br>
{X= Pay_rate-5000} - for over 5000.01 only, X must drop the decimals. 	<br>

<b>Step 3 - Output</b> <br>
Print Full Name with an informative label on line 1 <br>
Print Social Security # with an informative label on line 2 <br>
Print Adress with an informative label on line 3  <br>
Print Skill level with an informative label on line 4<br>
Print Type of benefit with an informative label on line 5 <br>
Print Tax amount owed with an informative label on line 6<br>
Print Gross salary an informative label on line 7<br>
Print Net salary with an informative label on line 8  <br>
Print retirement contribution percentage with an informative label on line 9<br>
************************ End of Algorithm *****************************/	 

