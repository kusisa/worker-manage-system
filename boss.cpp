#include"boss.h"

Boss::Boss(int id,string name ,int did){
this->m_id=id;
this->m_name=name;
this->m_did=did;

}

void Boss::showinfo(){
cout<<"ְ�����: "<<this->m_id<<"\tְ������: "<<this->m_name<<"\t��λ: "<<this->getdeptname()<<"\t��λְ��:��ɹ�˾��������"<<endl;
}

string Boss::getdeptname(){

    return string ("�ϰ�");
}