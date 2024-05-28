#include <iostream>

struct Node {
    int value;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void addFront(int value) {
        Node* newNode = new Node{ value, head };
        head = newNode;
    }

    void addAt(int index, int value) {
        Node* newNode = new Node{ value, nullptr };
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1 && current != nullptr; ++i) {
                current = current->next;
            }
            if (current != nullptr) {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void addBack(int value) {
        Node* newNode = new Node{ value, nullptr };
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeFront() {
        if (head != nullptr) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    void removeBack() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            }
            else {
                Node* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
        }
    }

    void removeAt(int index) {
        if (index == 0) {
            removeFront();
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1 && current != nullptr; ++i) {
                current = current->next;
            }
            if (current != nullptr && current->next != nullptr) {
                Node* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            }
        }
    }

    void updateAt(int index, int value) {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            current->value = value;
        }
    }

    int getValueAt(int index) {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i) {
            current = current->next;
        }
        return (current != nullptr) ? current->value : -1;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    LinkedList list;
    int value, index, choice, size;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> size;
    std::cout << "Введите элементы списка:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> value;
        list.addBack(value);
    }

    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Добавить элемент в начало\n";
        std::cout << "2. Добавить элемент по индексу\n";
        std::cout << "3. Добавить элемент в конец\n";
        std::cout << "4. Удалить первый элемент\n";
        std::cout << "5. Удалить последний элемент\n";
        std::cout << "6. Удалить элемент по индексу\n";
        std::cout << "7. Обновить элемент по индексу\n";
        std::cout << "8. Найти элемент по индексу\n";
        std::cout << "9. Вывести список\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент: ";
            std::cin >> value;
            list.addFront(value);
            break;
        case 2:
            std::cout << "Введите индекс и элемент: ";
            std::cin >> index >> value;
            list.addAt(index, value);
            break;
        case 3:
            std::cout << "Введите элемент: ";
            std::cin >> value;
            list.addBack(value);
            break;
        case 4:
            list.removeFront();
            break;
        case 5:
            list.removeBack();
            break;
        case 6:
            std::cout << "Введите индекс: ";
            std::cin >> index;
            list.removeAt(index);
            break;
        case 7:
            std::cout << "Введите индекс и новый элемент: ";
            std::cin >> index >> value;
            list.updateAt(index, value);
            break;
        case 8:
            std::cout << "Введите индекс: ";
            std::cin >> index;
            std::cout << "Элемент по индексу " << index << ": " << list.getValueAt(index) << std::endl;
            break;
        case 9:
            list.display();
            break;
        }

        if (choice != 0 && choice != 8 && choice != 9) {
            std::cout << "Промежуточный результат: ";
            list.display();
        }
    } while (choice != 0);

    return 0;
}
