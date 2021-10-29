#include <iostream>

using namespace std;

struct contact{
    char *name;
    long long int phone;
    char *email;
    char *address;

    contact *next;      // ��������� �� ����. ��-� ������
};

contact* init_list(char* name, long long int phone, char* email, char* address) {
    contact* lst = new contact;
    lst->name = name;
    lst->phone = phone;
    lst->email = email;
    lst->address = address;
    lst->next = NULL;

    return lst;
}

void add_elem(contact *lst, char* name, long long int phone, char* email, char* address) {
    // 2.1
    contact *p;
    contact *tmp = new contact; // �������� (��������� ������������ ������) ������ ���� ������

    // 2.2
    p = lst->next;      // ���������� ��������� �� ����. ����
    lst->next = tmp;    // ����. ���� ��������� �� ������� (�����������)
    tmp->next = p;

    // 2.3
    tmp->name = name;
    tmp->phone = phone;
    tmp->email = email;
    tmp->address = address;
}

void print_list(contact* lst) {
     contact *t = lst;

    do{
        cout << "name: " << t->name << endl;
        cout << "phone: " << t->phone << endl;
        cout << "email: " << t->email << endl;
        cout << "address: " << t->address << endl;
        cout << endl;

        t = t->next;    // ������� � ����. ��-��
    }while (t != NULL);
}

void delete_elem(contact *lst, int elem){
    contact *t = lst;
    contact *t1 = lst;

    for(int i=1; i<elem; i++) {
        if(i > 1){
            t1 = t1->next;
        }
        t = t->next;    // ������� � ����. ��-��
    }

    t1->next = t->next; // ����� ��������� � ����. �� ����. �� �����.
    free(t);            // �������� �����. ��-��
}

int main()
{
    int vibor;
    contact *lst = NULL;    // ������� ������ ��������� contact (������� ������)

    // ������������� ������
    lst = init_list("Vasya", 89991234122, "vasya@example.com", "Lenin street, 156");

    setlocale(LC_ALL, "");

    // ���������
    cout << "1 - �������� ������\n2 - ���������� ��������\n3 - �������� ��������\n4 - �����\n\n";

    bool run = true;

    while(run == true) {
        cout << "������� �����: ";
        cin >> vibor;

        switch (vibor)
        {
            case 1:
                print_list(lst);
                break;
            case 2:
                 add_elem(lst, "Ivan", 89990001122, "ivan@example.com", "Lenin street, 1");
                break;
            case 3:
                delete_elem(lst, 3);
                break;
            case 4:
                run = false;
                break;

            default:
                cout << "Error!" << endl;
        }
    }

    return 0;
}

/*
\/ 0. ������ (��-� ������)

    - ���       // char
    - ���       // int
    - e-mail    // char
    - �����     // char

    // ����������� �������� ������
\/ 1. �������� ������
\/ 2. ���������� ��-��
    \/ 2.1 �������� �������� ����������
    \/ 2.2 ���������
    \/ 2.3 ���������� ����� ��-��
\/ 3. �������� ��-��

4. ���������

1 - �������� ������
2 - ���������� ��������
3 - �������� ��������
4 - �����

������� �����:

\/ *. ������� ������� � �������

*/
