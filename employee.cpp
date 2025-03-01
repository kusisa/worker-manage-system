#include"employee.h"
Employee::Employee(int id,string name,int did){
    
    this->m_id=id;
    this->m_name=name;
    this->m_did=did;

}

 void Employee::showinfo(){
cout<<"职工编号: "<<this->m_id<<"\t职工姓名: "<<this->m_name<<"\t岗位: "<<this->getdeptname()<<"\t岗位职责:完成经理的任务"<<endl;
}

string Employee::getdeptname(){
    return string("员工");
} 