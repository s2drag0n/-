#include <iostream>
#include "workerManager.h"
using namespace std;



int main() {


    //ʵ�������������
    WorkerManager wm;

    //����չʾ�˵�����


    int choice = 0;

    while (true) {

        wm.ShowMeau();

        cout << "����������ѡ��" << endl;
        cin >> choice;

        switch (choice) {
        case 0:
            //�˳�
            wm.ExitSystem();
            break;
        case 1:
            //����ְ����Ϣ
            wm.addEmp();
            break;
        case 2:
            //��ʾְ��
            wm.show_EMP();
            break;
        case 3:
            //ɾ��ְ��
            wm.del_Emp();
            break;
        case 4:
            //�޸�ְ��
            wm.modify_EMP();
            break;
        case 5:
            //����ְ��
            wm.findEMP();
            break;
        case 6:
            //����ְ��
            wm.sortEmp();
            break;
        case 7:
            //�������
            wm.cleanFile();
            break;
        default:
            system("cls");//��Ч���־������Ļ
            break;
        }
    }

    return 0;
}