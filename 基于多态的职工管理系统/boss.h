#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Boss :public Worker {
public:

    Boss(int id, string name, int dId);

    //��ȡ��λ����
    virtual string getDeptName();

    //��ʾ������Ϣ
    virtual void showInfo();
};
