#include"workmanage.h"

WorkManage::WorkManage()
{

ifstream ifs;
ifs.open(FILENAME,ios::in);
//1.�ļ�������
if(!ifs.is_open()){
    //cout<<"�ļ�������"<<endl;
    this->m_Empnum=0;
    this->m_EmpArray=NULL;
    this->m_FileIsEmpty=true;
    ifs.close();
    return ;
}
//2.�ļ����� ����Ϊ��
char ch;
ifs>>ch;
if(ifs.eof()){
    //cout<<"�ļ�Ϊ��"<<endl;
    this->m_Empnum=0;
    this->m_EmpArray=NULL;
    this->m_FileIsEmpty=true;
    ifs.close();
    return ;
}
//3.�ļ������ݶ�����
int num=this->get_Empnum();
//cout<<"ְ������Ϊ : "<<num<<endl;
this->m_Empnum=num;
this->m_EmpArray=new Worker*[this->m_Empnum];
this->init_Emp();

//for(int i=0;i<this->m_Empnum;i++){
//    cout<<"ְ�����: "<<this->m_EmpArray[i]->m_id
//    <<"����: "<<this->m_EmpArray[i]->m_name
//    <<"��λ: "<<this->m_EmpArray[i]->m_did<<endl;
//}
}
    
WorkManage::~WorkManage()
{
    for(int i=0;i<this->m_Empnum;i++){
        if(this->m_EmpArray[i]!=NULL){
            delete this->m_EmpArray[i];
        }
    }
    delete[]this->m_EmpArray;
    this->m_EmpArray=NULL;
}

void WorkManage::showmenu()
{
    cout<<"************************"<<endl;
    cout<<"**��ӭʹ��ְ������ϵͳ**"<<endl;
    cout<<"*****0.�˳��������*****"<<endl;
    cout<<"*****1.����ְ����Ϣ*****"<<endl;
    cout<<"*****2.��ʾְ����Ϣ*****"<<endl;
    cout<<"*****3.ɾ����ְְ��*****"<<endl;
    cout<<"*****4.�޸�ְ����Ϣ*****"<<endl;
    cout<<"*****5.����ְ����Ϣ*****"<<endl;
    cout<<"*****6.���ձ������*****"<<endl;
    cout<<"*****7.��������ĵ�*****"<<endl;
    cout<<"************************"<<endl;
    cout<<endl;
}

//0
void WorkManage::exitsystem(){
cout<<"��ӭ�´�ʹ��"<<endl;
//system("pause");
exit(EXIT_SUCCESS);
}
//1
void WorkManage::Add_Emp(){
cout<<"������Ҫ��ӵ�ְ������"<<endl;
int addNum=0;
cin>>addNum;

if(addNum>0){
    int newSize=this->m_Empnum+addNum;

    Worker**newSpace=new Worker*[newSize];

    if(this->m_EmpArray!=NULL){
        for(int i=0;i<m_Empnum;i++){
            newSpace[i]=this->m_EmpArray[i];
        }
    }
        for(int i=0;i<addNum;i++){
            int id;
            string name;
            int did;

            cout<<"�������"<<i+1<<"����ְ���ı��:"<<endl;
            cin>>id;
            cout<<"�������"<<i+1<<"����ְ��������:"<<endl;
            cin>>name;
            cout<<"�������"<<i+1<<"����ְ���ĸ�λ:"<<endl;
            cout<<"1.��ְͨ��"<<endl;
            cout<<"2.����"<<endl;
            cout<<"3.�ϰ�"<<endl;
            cin>>did;

            Worker*worker=NULL;

            switch(did){
                case 1:
                worker=new Employee(id,name,did);
                break;
                case 2:
                worker=new Manager(id,name,did);
                break;
                case 3:
                worker=new Boss(id,name,did);
                break;
                default:
                break;
            }
            newSpace[this->m_Empnum+i]=worker;
        }
        delete[]this->m_EmpArray;
        this->m_EmpArray=newSpace;
        this->m_Empnum=newSize;
        this->m_FileIsEmpty=false;
        cout<<"�ɹ���ӣ�"<<addNum<<"��"<<endl;
        this->save();
    }
   
else{
    cout<<"��������"<<endl;
}

system("pause");
system("cls");
}
//����
void WorkManage::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    for(int i=0;i<this->m_Empnum;i++){
        ofs<<this->m_EmpArray[i]->m_id<<" "
        <<this->m_EmpArray[i]->m_name<<" "
        <<this->m_EmpArray[i]->m_did<<endl;
    }
    ofs.close();
}
//��ְ������
int WorkManage::get_Empnum(){
ifstream ifs;
ifs.open(FILENAME,ios::in);

int id;
string name;
int did;

int num=0;

while(ifs>>id&&ifs>>name&&ifs>>did){
    num++;
}
return num;
}

void WorkManage::init_Emp(){
ifstream ifs;
ifs.open(FILENAME,ios::in);

int id;
string name;
int did;

int index=0;
while(ifs>>id&&ifs>>name&&ifs>>did){
    Worker *worker=NULL;

   if(did==1){
    worker=new Employee (id,name,did);
   }else{
    if(did==2){
        worker=new Manager(id,name,did);
    }
    else{
        if(did==3){
            worker=new Boss(id,name,did);
        }
    }
   }
this->m_EmpArray[index]=worker;
index++;    
}
ifs.close();
}

//2.��ʾְ��
void WorkManage::show_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }else{
        for(int i=0;i<this->m_Empnum;i++){
            this->m_EmpArray[i]->showinfo();
        }
    }
    system("pause");
    system("cls");
}
//3.ɾ��ְ��
void WorkManage::Del_Emp(){
if(this->m_FileIsEmpty){
    cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
}
else
{
cout<<"������Ҫɾ����ְ�����"<<endl;
int id=0;   
cin>>id;

int index=this->IsExist(id);
if(index!=-1){
    for(int i=index;i<this->m_Empnum-1;i++){
        this->m_EmpArray[i]=this->m_EmpArray[i+1];
    }
    this->m_Empnum--;
    this->save();
    cout<<"ɾ���ɹ�"<<endl;
}
else{
    cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<endl;
}
}
system("pause");
system("cls");

}
int WorkManage::IsExist(int id){
int index=-1;

for(int i=0;i<this->m_Empnum;i++){
    if(this->m_EmpArray[i]->m_id==id){
        index=i;
        break;
    }
}
return index;
}
//4.�޸�ְ��
void WorkManage::Mod_Emp(){
if(this->m_FileIsEmpty){
    cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
}
else
{
cout<<"������Ҫ�޸ĵ�ְ�����"<<endl;
int id=0;
cin>>id;    

int ret=this->IsExist(id);
if(ret!=-1){
    delete this->m_EmpArray[ret];

    int newId=0;
    string newName="";
    int newDid=0;

    cout<<"�鵽��"<<id<<"��ְ������������ְ����"<<endl;
    cin>>newId;
    cout<<"������������"<<endl;
    cin>>newName;
    cout<<"�������¸�λ"<<endl;
    cout<<"1.��ְͨ��"<<endl;
    cout<<"2.����"<<endl;
    cout<<"3.�ϰ�"<<endl;
    cin>>newDid;

    Worker*worker=NULL;
    switch(newDid){
        case 1:
        worker=new Employee(newId,newName,newDid);
        break;
        case 2:
        worker=new Manager(newId,newName,newDid);
        break;
        case 3:
        worker=new Boss(newId,newName,newDid);
        break;
        default:
        break;
    }
    this->m_EmpArray[ret]=worker;
    cout<<"�޸ĳɹ�"<<endl;
    this->save();
}
else{
    cout<<"�޸�ʧ�ܣ�δ�ҵ���ְ��"<<endl;

}
}
}
//5.����ְ��
void WorkManage::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"��������ҵķ�ʽ"<<endl;
        cout<<"1.��ְ����Ų���"<<endl;
        cout<<"2.��ְ����������"<<endl;

        int select=0;
        cin>>select;
        if(select==1){

            int id;
            cout<<"��������ҵ�ְ�����"<<endl;
            cin>>id;

            int ret=IsExist(id);
            if(ret!=-1){
                cout<<"���ҳɹ����ҵ�����,��ְ����Ϣ����"<<endl;
                this->m_EmpArray[ret]->showinfo();
            }else{
                cout<<"����ʧ��"<<endl;

            }
        }
        else if(select==2){
            string name;
            cout<<"����������ҵ��˵�����"<<endl;
            cin>>name;
            bool flag=false;

            for(int i=0;i<m_Empnum;i++){
                if(this->m_EmpArray[i]->m_name==name){
                    cout<<"���ҳɹ���ְ�����Ϊ"
                    <<this->m_EmpArray[i]->m_id<<
                    "��ְ����Ϣ����"<<endl;
                    flag=true;
                    this->m_EmpArray[i]->showinfo();
                }
            }
            if(flag==false){
                cout<<"���޴���"<<endl;
            }
            else{
                cout<<"����ѡ������"<<endl;
            }
        }
            system("pause");
            system("cls");
        }
    }
    
    //6.���ձ������
    void WorkManage::Sort_Emp(){
        if(this->m_FileIsEmpty){
            cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
        }
        else{
            cout<<"��ѡ������ʽ"<<endl;
            cout<<"1.��ְ��������"<<endl;
            cout<<"2.��ְ���Ž���"<<endl;

            int select=0;
            cout<<"��ѡ��"<<endl;
            cin>>select;

            for(int i=0;i<this->m_Empnum;i++){
                int minOrMax=i;
                for(int j=i+1;j<this->m_Empnum;j++){
                    if(select==1){
                        if(this->m_EmpArray[minOrMax]->m_id>this->m_EmpArray[j]->m_id){
                            minOrMax=j;
                        }
                    }
                    else{
                        if(this->m_EmpArray[minOrMax]->m_id<this->m_EmpArray[j]->m_id){
                            minOrMax=j;
                        }
                    }
                }
                if(i!=minOrMax){
                    Worker*temp=this->m_EmpArray[i];
                    this->m_EmpArray[i]=this->m_EmpArray[minOrMax];
                    this->m_EmpArray[minOrMax]=temp;
                }
            }
            cout<<"����ɹ����������Ϊ"<<endl;
            this->save();
            this->show_Emp();
        }
    }
//7.��������ĵ�
void WorkManage::Clean_File(){
    cout<<"ȷ����գ�"<<endl;
    cout<<"1.ȷ��"<<endl;
    cout<<"2.����"<<endl;

    int select=0;
    cin>>select;
    if(select==1){
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_Empnum;i++){
                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];
                }
            }
            this->m_Empnum=0;
            delete[]this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_FileIsEmpty=true;
        }
        cout<<"��ճɹ�"<<endl;
    }
    system("pause");
    system("cls");
} 
