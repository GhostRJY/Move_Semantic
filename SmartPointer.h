#pragma once
#define DEBUG
#include<iostream>

class TestObject;

//мой умный указатель
template <class T>
class SmartPointer
{
public:
    //создаю указатель на полученный объект
    SmartPointer(T *ptr = nullptr) :m_ptr{ ptr } {}

    //конструктор копирования(глубокое копирование)
    SmartPointer(const SmartPointer &obj)
    {
        m_ptr = new T;
        *m_ptr = *obj.m_ptr;

        std::cout << "конструктор глубокого копирования(-)\n";
    }

#ifdef DEBUG
    //конструктор перемещения(глубокое копирование)
    SmartPointer(SmartPointer &&obj) :m_ptr{ obj.m_ptr }
    {
        obj.m_ptr = nullptr;

        std::cout << "конструктор перемещения(+)\n";
    }
#endif
    //уничтожаю указатель на объект
    ~SmartPointer() { 
        delete m_ptr;
        
    }

    //Присваивание копированием(глубокое копирование)
    SmartPointer &operator=(const SmartPointer &obj)
    {
        if(this == &obj)
            return *this;

        delete m_ptr;   //удалюя старый указатель

        m_ptr = new T;
        *m_ptr = *obj.m_ptr; //присваиваю значение из объекта

        std::cout << "Копирую объект(-)\n";

        return *this;
    }

#ifdef DEBUG
    //Присваивание перемещением(отдаю владение передаваемым объектом)
    SmartPointer &operator=(SmartPointer &&obj)
    {
        if(this == &obj)
            return *this;
                
        delete m_ptr;

        m_ptr = obj.m_ptr; //присваиваю адрес объекта
        obj.m_ptr = nullptr;

        std::cout << "Перемещаю объект+\n";

        return *this;
    }
#endif
    //оператор разыменования
    T &operator *()const { return *m_ptr; }

    //оператор обращения к указателю
    T *operator->()const { return m_ptr; }

    //проверяю на нулевой указатель
    bool isNull() const { return m_ptr == nullptr; }

private:

    T *m_ptr; //указаталь на объект нужного типа, получаю когда создаю указатель
};

//класс проверки указателя
class TestObject
{
public:
    TestObject() { std::cout << "Объект получен!\n"; }
    ~TestObject() { std::cout << "Объект Уничтожен!\n"; }

    friend std::ostream &operator<<(std::ostream &stream, const TestObject &object)
    {
        stream << object;
        return stream;
    }

};