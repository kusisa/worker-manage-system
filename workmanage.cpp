#include"workmanage.h"

WorkManage::WorkManage()
{

ifstream ifs;
ifs.open(FILENAME,ios::in);
//1.文件不存在
if(!ifs.is_open()){
    //cout<<"文件不存在"<<endl;
    this->m_Empnum=0;
    this->m_EmpArray=NULL;
    this->m_FileIsEmpty=true;
    ifs.close();
    return ;
}
//2.文件存在 数据为空
char ch;
ifs>>ch;
if(ifs.eof()){
    //cout<<"文件为空"<<endl;
    this->m_Empnum=0;
    this->m_EmpArray=NULL;
    this->m_FileIsEmpty=true;
    ifs.close();
    return ;
}
//3.文件和数据都存在
int num=this->get_Empnum();
//cout<<"职工数量为 : "<<num<<endl;
this->m_Empnum=num;
this->m_EmpArray=new Worker*[this->m_Empnum];
this->init_Emp();

//for(int i=0;i<this->m_Empnum;i++){
//    cout<<"职工编号: "<<this->m_EmpArray[i]->m_id
//    <<"姓名: "<<this->m_EmpArray[i]->m_name
//    <<"岗位: "<<this->m_EmpArray[i]->m_did<<endl;
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
    cout<<"**欢迎使用职工管理系统**"<<endl;
    cout<<"*****0.退出管理程序*****"<<endl;
    cout<<"*****1.增加职工信息*****"<<endl;
    cout<<"*****2.显示职工信息*****"<<endl;
    cout<<"*****3.删除离职职工*****"<<endl;
    cout<<"*****4.修改职工信息*****"<<endl;
    cout<<"*****5.查找职工信息*****"<<endl;
    cout<<"*****6.按照编号排序*****"<<endl;
    cout<<"*****7.清空所有文档*****"<<endl;
    cout<<"************************"<<endl;
    cout<<endl;
}

//0
void WorkManage::exitsystem(){
cout<<"欢迎下次使用"<<endl;
//system("pause");
exit(EXIT_SUCCESS);
}
//1
void WorkManage::Add_Emp(){
cout<<"请输入要添加的职工数量"<<endl;
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

            cout<<"请输入第"<<i+1<<"个新职工的编号:"<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工的姓名:"<<endl;
            cin>>name;
            cout<<"请输入第"<<i+1<<"个新职工的岗位:"<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
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
        cout<<"成功添加："<<addNum<<"人"<<endl;
        this->save();
    }
   
else{
    cout<<"输入有误"<<endl;
}

system("pause");
system("cls");
}
//保存
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
//读职工数量
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

//2.显示职工
void WorkManage::show_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
    }else{
        for(int i=0;i<this->m_Empnum;i++){
            this->m_EmpArray[i]->showinfo();
        }
    }
    system("pause");
    system("cls");
}
//3.删除职工
void WorkManage::Del_Emp(){
if(this->m_FileIsEmpty){
    cout<<"文件不存在或记录为空"<<endl;
}
else
{
cout<<"请输入要删除的职工编号"<<endl;
int id=0;   
cin>>id;

int index=this->IsExist(id);
if(index!=-1){
    for(int i=index;i<this->m_Empnum-1;i++){
        this->m_EmpArray[i]=this->m_EmpArray[i+1];
    }
    this->m_Empnum--;
    this->save();
    cout<<"删除成功"<<endl;
}
else{
    cout<<"删除失败，未找到该职工"<<endl;
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
//4.修改职工
void WorkManage::Mod_Emp(){
if(this->m_FileIsEmpty){
    cout<<"文件不存在或记录为空"<<endl;
}
else
{
cout<<"请输入要修改的职工编号"<<endl;
int id=0;
cin>>id;    

int ret=this->IsExist(id);
if(ret!=-1){
    delete this->m_EmpArray[ret];

    int newId=0;
    string newName="";
    int newDid=0;

    cout<<"查到："<<id<<"号职工，请输入新职工号"<<endl;
    cin>>newId;
    cout<<"请输入新姓名"<<endl;
    cin>>newName;
    cout<<"请输入新岗位"<<endl;
    cout<<"1.普通职工"<<endl;
    cout<<"2.经理"<<endl;
    cout<<"3.老板"<<endl;
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
    cout<<"修改成功"<<endl;
    this->save();
}
else{
    cout<<"修改失败，未找到该职工"<<endl;

}
}
}
//5.查找职工
void WorkManage::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入查找的方式"<<endl;
        cout<<"1.按职工编号查找"<<endl;
        cout<<"2.按职工姓名查找"<<endl;

        int select=0;
        cin>>select;
        if(select==1){

            int id;
            cout<<"请输入查找的职工编号"<<endl;
            cin>>id;

            int ret=IsExist(id);
            if(ret!=-1){
                cout<<"查找成功，找到此人,该职工信息如下"<<endl;
                this->m_EmpArray[ret]->showinfo();
            }else{
                cout<<"查找失败"<<endl;

            }
        }
        else if(select==2){
            string name;
            cout<<"请输入想查找的人的名字"<<endl;
            cin>>name;
            bool flag=false;

            for(int i=0;i<m_Empnum;i++){
                if(this->m_EmpArray[i]->m_name==name){
                    cout<<"查找成功，职工编号为"
                    <<this->m_EmpArray[i]->m_id<<
                    "的职工信息如下"<<endl;
                    flag=true;
                    this->m_EmpArray[i]->showinfo();
                }
            }
            if(flag==false){
                cout<<"查无此人"<<endl;
            }
            else{
                cout<<"输入选项有误"<<endl;
            }
        }
            system("pause");
            system("cls");
        }
    }
    
    //6.按照编号排序
    void WorkManage::Sort_Emp(){
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或记录为空"<<endl;
        }
        else{
            cout<<"请选择排序方式"<<endl;
            cout<<"1.按职工号升序"<<endl;
            cout<<"2.按职工号降序"<<endl;

            int select=0;
            cout<<"请选择："<<endl;
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
            cout<<"排序成功，排序后结果为"<<endl;
            this->save();
            this->show_Emp();
        }
    }
//7.清空所有文档
void WorkManage::Clean_File(){
    cout<<"确认清空？"<<endl;
    cout<<"1.确认"<<endl;
    cout<<"2.返回"<<endl;

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
        cout<<"清空成功"<<endl;
    }
    system("pause");
    system("cls");
} 
