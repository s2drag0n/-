#pragma once
#include <iostream>
#include <string>
using namespace std;

//ְ��������
class Worker {
public:

    //���
    int m_ID;

    //����
    string m_Name;

    //���ű��
    int m_DeptId;

    //��ȡ��λ����
    virtual string getDeptName() = 0;

    //��ʾ������Ϣ
    virtual void showInfo() = 0;
};