#include"manager.h"

Manager::Manager(int id,string name ,int did){
this->m_id=id;
this->m_name=name;
this->m_did=did;

}

void Manager::showinfo(){
cout<<"ְ�����: "<<this->m_id<<"\tְ������: "<<this->m_name<<"\t��λ: "<<this->getdeptname()<<"\t��λְ��:����ϰ彻�������񣬲��·��������ͨԱ��"<<endl;
}

string Manager::getdeptname(){

    return string ("����");
}