#include"boss.h"

Boss::Boss(int id,string name ,int did){
this->m_id=id;
this->m_name=name;
this->m_did=did;

}

void Boss::showinfo(){
cout<<"职工编号: "<<this->m_id<<"\t职工姓名: "<<this->m_name<<"\t岗位: "<<this->getdeptname()<<"\t岗位职责:完成公司所有事务"<<endl;
}

string Boss::getdeptname(){

    return string ("老板");
}