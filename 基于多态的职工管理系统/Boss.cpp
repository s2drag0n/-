#include "boss.h"

Boss::Boss(int id, string name, int dId) {
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//��ȡ��λ����
string Boss::getDeptName() {
    return string("�ܲ�");
}

//��ʾ������Ϣ
void Boss::showInfo() {
    cout << "ְ�����:" << this->m_ID
        << "\tְ��������" << this->m_Name
        << "\t��λ������" << this->getDeptName()
        << "\t��λְ�𣺹���˾��������" << endl;
}