#include "employee.h"

Employee::Employee(int id, string name, int dId) {
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//��ȡ��λ����
string Employee::getDeptName() {
    return string("Ա��");
}

//��ʾ������Ϣ
void Employee::showInfo() {
    cout << "ְ�����:" << this->m_ID
        << "\tְ��������" << this->m_Name
        << "\t��λ������" << this->getDeptName()
        << "\t��λְ����ɾ�����������" << endl;
}