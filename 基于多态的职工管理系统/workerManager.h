#pragma once
#include <iostream>
#include "worker.h"
using namespace std;
#include <fstream>
#include <string>

const string FILENAME = "empFile.txt";
class WorkerManager {
public:

    WorkerManager();

    ~WorkerManager();

    //չʾ�˵�
    void ShowMeau();

    //�˳�ϵͳ
    void ExitSystem();

    //����ְ��
    void addEmp();

    //��¼ְ������
    int m_EmpNum;

    //��¼ְ��ָ��
    Worker** m_EmpArray;

    //�����ļ�
    void save();

    //�ж��ļ��Ƿ�Ϊ��
    bool m_FileIsempty;

    //ͳ���ļ��е�����
    int get_EmpNum();

    //��ʼ��ְ��
    void init_EMP();

    //��ʾְ��
    void show_EMP();

    //ɾ��ְ��
    void del_Emp();

    //�ж�ְ���Ƿ���ڣ������򷵻�λ��
    int isExit(int id);

    //�޸�ְ��
    void modify_EMP();

    //����ְ��
    void findEMP();

    //����ְ��
    void sortEmp();

    //�������
    void cleanFile();
};
