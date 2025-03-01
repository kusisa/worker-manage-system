#include"manager.h"

Manager::Manager(int id,string name ,int did){
this->m_id=id;
this->m_name=name;
this->m_did=did;

}

void Manager::showinfo(){
cout<<"职工编号: "<<this->m_id<<"\t职工姓名: "<<this->m_name<<"\t岗位: "<<this->getdeptname()<<"\t岗位职责:完成老板交给的任务，并下发任务给普通员工"<<endl;
}

string Manager::getdeptname(){

    return string ("经理");
}