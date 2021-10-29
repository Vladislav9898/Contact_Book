#include <iostream>

using namespace std;

struct contact{
    char *name;
    long long int phone;
    char *email;
    char *address;

    contact *next;      // указатель на след. эл-т списка
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
    contact *tmp = new contact; // Создание (выделение динамической памяти) нового узла списка

    // 2.2
    p = lst->next;      // Сохранение указатель на след. узел
    lst->next = tmp;    // пред. узел указывает на текущий (создаваемый)
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

        t = t->next;    // Переход к след. эл-ту
    }while (t != NULL);
}

void delete_elem(contact *lst, int elem){
    contact *t = lst;
    contact *t1 = lst;

    for(int i=1; i<elem; i++) {
        if(i > 1){
            t1 = t1->next;
        }
        t = t->next;    // Переход к след. эл-ту
    }

    t1->next = t->next; // Смена указателя с пред. на след. за текущ.
    free(t);            // Удаление текущ. эл-та
}

int main()
{
    int vibor;
    contact *lst = NULL;    // Создаем объект структуры contact (Создаем список)

    // Инициализация списка
    lst = init_list("Vasya", 89991234122, "vasya@example.com", "Lenin street, 156");

    setlocale(LC_ALL, "");

    // Интерфейс
    cout << "1 - просмотр списка\n2 - добавление элемента\n3 - удаление элемента\n4 - выход\n\n";

    bool run = true;

    while(run == true) {
        cout << "Введите число: ";
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
\/ 0. Данные (эл-т списка)

    - ФИО       // char
    - тлф       // int
    - e-mail    // char
    - адрес     // char

    // односвязный линейный список
\/ 1. просмотр списка
\/ 2. добавление эл-та
    \/ 2.1 создание временых переменных
    \/ 2.2 рокировка
    \/ 2.3 заполнение полей эл-та
\/ 3. удаление эл-та

4. интерфейс

1 - просмотр списка
2 - добавление элемента
3 - удаление элемента
4 - выход

Введите число:

\/ *. Перенос пунктов в функции

*/
