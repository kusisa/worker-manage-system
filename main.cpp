#include<iostream>

#include"workmanage.h"
#include "workmanage.cpp"
#include"employee.h"
#include"employee.cpp"
#include"manager.h"
#include"manager.cpp"
#include"boss.h"
#include"boss.cpp"


using namespace std;


int main(){
    int choice=0;
    WorkManage wm;
    //测试代码
   // Worker* worker =NULL;
   // worker =new Employee (1,"张三",1);
   // worker->showinfo();
   // delete worker;
   
   // worker=new Manager(2,"李四",2);
   // worker->showinfo();
   // delete worker;

   // worker=new Boss(3,"王五",3);
   // worker->showinfo();
   // delete worker;

    
  

    while (true){
    wm.showmenu();
    cout<<"请输入您的选择"<<endl;  
    cin>>choice;

    switch(choice){
    case 0:
    wm.exitsystem();
    break;
    case 1:
    wm.Add_Emp();
    break;
    case 2:
    wm.show_Emp();
    break; 
    case 3:
    wm.Del_Emp();
    break;
    case 4:
    wm.Mod_Emp();
    break;
    case 5:
    wm.Find_Emp();
    break;
    case 6:
    break;
    case 7:
    break;
    default:
    system("cls");
    break;
    }
 system("pause");
}
}
