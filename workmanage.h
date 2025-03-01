#pragma once//防止头文件重复包含
#include<iostream>
#include<stdlib.h>
#include"worker.h"
#include"manager.h"
#include"boss.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

class WorkManage
{
public:
//显示菜单
void showmenu();
//0.退出系统
void exitsystem();
//1.添加职工
void Add_Emp();
//2.显示职工
void show_Emp();
//3.删除职工
void Del_Emp();
//4.修改职工
void Mod_Emp();
//5.查找职工
void Find_Emp();
//6.按照编号排序
void Sort_Emp();
//7.清空所有文档
void Clean_File();
//记录职工人数
int m_Empnum;
//指向职工数组的指针
Worker **m_EmpArray;
//保存文件中的职工个数
void save();
//判断文件是否为空的标准
bool m_FileIsEmpty=false;
//统计文件中的人数
int get_Empnum();
//初始化职工
void init_Emp();
//判断职工是否存在
int IsExist(int id);

WorkManage();
~WorkManage();
};


