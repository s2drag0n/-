#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


WorkerManager::WorkerManager() {


    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //�ļ�������
    if (!ifs.is_open()) {
        //cout << "�ļ�������!" << endl;
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsempty = true;
        ifs.close();
        return;
    }

    //�ļ����ڵ�û�м�¼
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //cout << "�ļ�Ϊ��!" << endl;
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsempty = true;
        ifs.close();
        return;
    }

    //�ļ��������м�¼
    int num = this->get_EmpNum();
    //cout << "ְ������Ϊ��" << num << endl;
    this->m_EmpNum = num;

    //���ٿռ�
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    //���ݴ������
    this->init_EMP();

}

WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::ShowMeau() {

    cout << "********************************************************" << endl;
    cout << "********************��ӭʹ��ְ������ϵͳ*****************" << endl;
    cout << "********************0.�˳�����ϵͳ***********************" << endl;
    cout << "********************1.����ְ����Ϣ***********************" << endl;
    cout << "********************2.��ʾְ����Ϣ***********************" << endl;
    cout << "********************3.ɾ����ְְ��***********************" << endl;
    cout << "********************4.�޸�ְ����Ϣ***********************" << endl;
    cout << "********************5.����ְ����Ϣͳ*********************" << endl;
    cout << "********************6.���ձ������***********************" << endl;
    cout << "********************7.��������ĵ�***********************" << endl;
    cout << "********************************************************" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem() {
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);    // �˳�����
}

//����ְ��
void WorkerManager::addEmp() {
    cout << "���������ְ��������" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0) {

        //�����¿ռ��С
        int newSize = this->m_EmpNum + addNum;

        //�����¿ռ�
        Worker** newSpace = new Worker * [newSize];

        //��ԭ�������ݿ������¿ռ�
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //���������
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;

            cout << "�������" << i + 1 << "��" << "��ְ���ı��" << endl;
            cin >> id;

            cout << "�������" << i + 1 << "��" << "��ְ��������" << endl;
            cin >> name;

            cout << "��ѡ���" << i + 1 << "��" << "��ְ���ĸ�λ" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ܲ�" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect) {
            case 1:
                worker = new Employee(id, name, dSelect);
                break;
            case 2:
                worker = new Manager(id, name, dSelect);
                break;
            case 3:
                worker = new Boss(id, name, dSelect);
                break;
            default:
                break;
            }

            //��������ְ��ָ�뱣�浽����
            newSpace[this->m_EmpNum + i] = worker;
        }

        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;

        //�����¿ռ�ָ��
        this->m_EmpArray = newSpace;

        //�����µ�ְ������
        this->m_EmpNum = newSize;

        //����д���ļ�
        this->save();

        //��ʾ��ӳɹ�
        cout << "�ɹ����" << addNum << "����ְ��" << endl;

        //����Ա����Ϊ��
        this->m_FileIsempty = false;


    } else {
        cout << "��������" << endl;
    }

    //������� �����ص��ϼ�Ŀ¼
    system("pause");
    system("cls");
}

void WorkerManager::save() {

    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_ID << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }

    return num;
}

//��ʼ��Ա��
void WorkerManager::init_EMP() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker* worker = NULL;
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {
            worker = new Manager(id, name, dId);
        } else if (dId == 3) {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index++] = worker;
    }

    ifs.close();
}

//��ʾְ��
void WorkerManager::show_EMP() {
    if (this->m_FileIsempty) {
        cout << "ְ����Ϣ�ļ������ڻ���Ϊ��" << endl;
    } else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//ɾ��ְ��
void WorkerManager::del_Emp() {
    if (this->m_FileIsempty) {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    } else {
        //����ְ�����ɾ��
        cout << "��������Ҫɾ����ְ�����" << endl;
        int id = 0;
        cin >> id;

        int index = this->isExit(id);

        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
        } else {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
        }
    }

    //������� ����
    system("pause");
    system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManager::isExit(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_ID == id) {
            //�ҵ�ְ��
            index = i;
            break;
        }
    }
    return index;
}

//�޸�ְ��
void WorkerManager::modify_EMP() {
    if (this->m_FileIsempty) {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    } else {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->isExit(id);
        if (ret != -1) {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;
            cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
            cin >> newId;
            cout << "��������������" << endl;
            cin >> newName;
            cout << "�������λ��" << endl;
            cout << "1.��ְͨ����" << endl;
            cout << "2.����" << endl;
            cout << "3.�ܲã�" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect) {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            this->m_EmpArray[ret] = worker;

            if (this->m_EmpArray[ret] != NULL) {
            cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_DeptId << endl;
            }

            this->save();
        } else {

        }

    }

    system("pause");
    system("cls");
}

//����ְ��
void WorkerManager::findEMP() {
    if (this->m_FileIsempty) {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    } else {
        cout << "��������ҵķ�ʽ" << endl;
        cout << "1.��ְ�����" << endl;
        cout << "2.������" << endl;
        int select = 0;
        cin >> select;

        if (select == 1) {
            int id;
            cout << "��������ҵ�ְ�����" << endl;
            cin >> id;

            int ret = this->isExit(id);
            if (ret != -1) {
                cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
                if (this->m_EmpArray[ret] != NULL) {
                    this->m_EmpArray[ret]->showInfo();
                } else {
                    cout << "����ʧ�ܣ����޴���" << endl;
                }
            }
        } else if (select == 2) {
            string name;
            cout << "��������ҵ�ְ������" << endl;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->m_Name == name) {
                    flag = true;
                    cout << "���ҳɹ���ְ�����Ϊ" << this->m_EmpArray[i]->m_ID << "�������£�" << endl;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false) {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        } else {
            cout << "������Ϣ����" << endl;

        }
    }
    system("pause");
    system("cls");

}

//����ְ��
void WorkerManager::sortEmp() {
    if (this->m_FileIsempty) {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    } else {
        cout << "��ѡ������ʽ��" << endl;
        cout << "1.��ְ��������" << endl;
        cout << "2.��ְ���Ž���" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->m_EmpNum; i++) {
            int minOrMax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++) {
                if (select == 1) {
                    if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID) {
                        minOrMax = j;
                    }
                } else if (select == 2) {
                    if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID) {
                        minOrMax = j;
                    }
                } else {
                    cout << "��������" << endl;
                }
                if (i != minOrMax) {
                    Worker* worker = m_EmpArray[i];
                    m_EmpArray[i] = m_EmpArray[minOrMax];
                    m_EmpArray[minOrMax] = worker;
                }
            }
        }
        save();
    }
    system("pause");
    system("cls");
}

//�������
void WorkerManager::cleanFile() {
    cout << "ȷ����գ�" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.ȡ��" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);//trunc��ʾɾ���ļ������´���
        ofs.close();

        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i] != NULL) {
                    delete this->m_EmpArray[i];
                    m_EmpArray[i] = NULL;
                }
            }
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsempty = true;
        }
        cout << "��ճɹ�" << endl;
    }
    system("pause");
    system("cls");
}