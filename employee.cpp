#include"employee.h"
Employee::Employee(int id,string name,int did){
    
    this->m_id=id;
    this->m_name=name;
    this->m_did=did;

}

 void Employee::showinfo(){
cout<<"ְ�����: "<<this->m_id<<"\tְ������: "<<this->m_name<<"\t��λ: "<<this->getdeptname()<<"\t��λְ��:��ɾ��������"<<endl;
}

string Employee::getdeptname(){
    return string("Ա��");
} 