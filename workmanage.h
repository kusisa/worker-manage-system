#pragma once//��ֹͷ�ļ��ظ�����
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
//��ʾ�˵�
void showmenu();
//0.�˳�ϵͳ
void exitsystem();
//1.���ְ��
void Add_Emp();
//2.��ʾְ��
void show_Emp();
//3.ɾ��ְ��
void Del_Emp();
//4.�޸�ְ��
void Mod_Emp();
//5.����ְ��
void Find_Emp();
//6.���ձ������
void Sort_Emp();
//7.��������ĵ�
void Clean_File();
//��¼ְ������
int m_Empnum;
//ָ��ְ�������ָ��
Worker **m_EmpArray;
//�����ļ��е�ְ������
void save();
//�ж��ļ��Ƿ�Ϊ�յı�׼
bool m_FileIsEmpty=false;
//ͳ���ļ��е�����
int get_Empnum();
//��ʼ��ְ��
void init_Emp();
//�ж�ְ���Ƿ����
int IsExist(int id);

WorkManage();
~WorkManage();
};


