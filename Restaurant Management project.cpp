#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class hotel{
public:
 char name[30];
 long int mno;
 int amount, tableno, time, pay;
 int tables[10];
 hotel(){
 amount= 0;
 int temp[10]= {1,0,0,0,1,1,0,0,1,1};
 for(int i=0; i<10; i++){
 tables[i]= temp[i];
 }
 }
};
class booking : public hotel{
public:
 string items = "";
 void getdata(){
 cout<<"Enter your name: ";
 cin.getline(name, 30);
 cout<<"Mobile number: ";
 cin>>mno;
 cout<<"Enter booking time (0-23): ";
 cin>>time;
 if(time<0 || time> 23){
 cout<<"Invalid time! Setting default 12.\n";
 time= 12;
 }
 }
 void book();
 void orderFood();
 void generateBill();
 void saveToFile();
};
void booking::book(){
 cout<<"\nAvailableTables:\n";
 for(int i=0; i<10; i++){
 if(tables[i] == 0){cout<<"Table No: "<<i+1<<endl;
 }
 }
 while(true){
 cout<<"Enter table number: "; 
 cin>>tableno; 
 try{
     if (tableno<1 || tableno> 10){
         throw "Invalid table number!";
 }
 if (tables[tableno- 1] == 1){
     throw "Table already booked! Try another.";
 }
 tables[tableno- 1]= 1;
 cout << "Table booked successfully!\n";
 break;
 }
 catch (const char* msg){
 cout << msg << endl;
 }
}}
void booking::orderFood(){
 int n, choice, qty;
 cout<<"\nHow many items do you want to order? ";
 cin>>n;
 for(int i=0; i<n; i++){
 cout<<"\n---- MENU ----\n";
 cout<<"1. Pizza- 200\n";
 cout<<"2. Burger- 100\n";
 cout<<"3. Pasta- 150\n";
 cout<<"4. Coffee- 50\n";
 cout<<"Enter choice: ";
 cin>>choice;
 cout<<"Enter quantity: ";
 cin>>qty;
 stringstream ss;
 ss << qty;
 switch(choice){
 case 1:
 amount += 200 * qty;
 items += "Pizza x" + ss.str() + "\n";
 break;
 case 2:
 amount += 100 * qty;
 items += "Burger x" + ss.str() + "\n";
 break;
 case 3:
 amount += 150 * qty;
 items += "Pasta x" + ss.str() + "\n";
 break;
 case 4:
 amount += 50 * qty;
 items += "Coffee x" + ss.str() + "\n";
 break;
 default:
 cout<<"Invalid choice! Try again.\n";
 i--; // retry
 }
 }
}
void booking::generateBill(){
cout<<" SEBYEOL RESTAURANT \n";
 cout<<"\n----- BILL -----\n";
 cout<<"Name: "<<name<<endl;
 cout<<"Mobile: "<<mno<<endl;
 cout<<"Time: "<<time<<endl;
 cout<<"Table No: "<<tableno<<endl;
 cout<<"\nItems Ordered:\n"<<items;
 cout<<"Total Amount: Rs."<<amount<<endl;
 do{
 cout<<"Enter payment: ";
 cin>>pay;
 if(pay < amount){
 cout<<"Insufficient payment! Try again.\n";}
 
} while(pay< amount);
 cout<<"Payment Successful!\n";
 cout<<"Balance: "<<pay- amount<<endl;
}
void booking::saveToFile(){
 ofstream file("hotel_records.txt", ios::app);
 if(!file){
 cout<<"Error opening file!\n";
 return;
 
}
 file<<"----- CUSTOMER RECORD -----\n";
 file<<"Name: "<<name<<endl;
 file<<"Mobile: "<<mno<<endl;
 file<<"Time: "<<time<<endl;
 file<<"Table No: "<<tableno<<endl;
 file<<"Items Ordered:\n"<<items;
 file<<"Total Amount: Rs."<<amount<<endl;
 file<<"---------------------------\n\n";
 file.close();
 switch(tableno){
 case 2:
 cout<<"Verify Code: BYL2781";
 break;
 case 3:
 cout<<"Verify Code: BYL2782";
 break;
 case 4:
 cout<<"Verify Code: BYL2783";
 break;
 case 7:
 cout<<"Verify Code: BYL2784";
 break;
 case 8:
 cout<<"Verify Code: BYL2785";
 break;
 default:
 cout<<"Verify Code: BYL0000"; }
cout<<"\nData saved to file successfully!\n";
}
int main(){
cout<<" WELCOME TO SEBYEOL!!! \n";
 booking b;
 b.getdata();
 b.book();
 b.orderFood();
 b.generateBill();
 b.saveToFile();
 return 0;
}
