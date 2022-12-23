#include<iostream>
#include<exception>
using namespace std;
class  MonthError:public exception {
    int month;
    public:
      const char* what(){return "check out ur month input\n";}
      void setmonth(int month){this->month=month;}

   
};
class  DayError:public exception {
    int Day;
    public:
      const char* what(){return "check out ur Day input\n";}
      void setDay(int Day){this->Day=Day;}
      
   
};
void convert(int day,int month){
     if(month>12 || month<0){
        MonthError m;
        throw m;
    }
    string strmonth="";
switch (month)
{
case 1:
strmonth="january"; 
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 2:
strmonth="february";
if(day<0 || day>29){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 3:
strmonth="march";
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 4:
strmonth="april";
if(day<0 || day>30){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 5:
strmonth="may";
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 6:
strmonth="june";
if(day<0 || day>30){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 7:
strmonth="july";
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 8:
strmonth="august";
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 9:
strmonth="september";
if(day<0 || day>30){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 10:
strmonth="october";
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 11:
strmonth="november";
if(day<0 || day>30){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}
case 12:
strmonth="december";
if(day<0 || day>31){
    DayError d;
    throw d;
    break;
}
else{
    cout<< strmonth<<" "<<to_string(day);
    break;}

default:
    break;

}
}
int main(){
    int day ,month;
    cout<<"enter day and month number: ";
    cin>>day>>month;
   
    try
    {
        convert(day,month);
    }
    catch(MonthError m)
    {
        std::cerr << m.what() << '\n';
    }
    catch(DayError d)
    {
        std::cerr << d.what() << '\n';
    }
    
    
}