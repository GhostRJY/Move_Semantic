#pragma once
#define DEBUG
#include<iostream>

class TestObject;

//��� ����� ���������
template <class T>
class SmartPointer
{
public:
    //������ ��������� �� ���������� ������
    SmartPointer(T *ptr = nullptr) :m_ptr{ ptr } {}

    //����������� �����������(�������� �����������)
    SmartPointer(const SmartPointer &obj)
    {
        m_ptr = new T;
        *m_ptr = *obj.m_ptr;

        std::cout << "����������� ��������� �����������(-)\n";
    }

#ifdef DEBUG
    //����������� �����������(�������� �����������)
    SmartPointer(SmartPointer &&obj) :m_ptr{ obj.m_ptr }
    {
        obj.m_ptr = nullptr;

        std::cout << "����������� �����������(+)\n";
    }
#endif
    //��������� ��������� �� ������
    ~SmartPointer() { 
        delete m_ptr;
        
    }

    //������������ ������������(�������� �����������)
    SmartPointer &operator=(const SmartPointer &obj)
    {
        if(this == &obj)
            return *this;

        delete m_ptr;   //������ ������ ���������

        m_ptr = new T;
        *m_ptr = *obj.m_ptr; //���������� �������� �� �������

        std::cout << "������� ������(-)\n";

        return *this;
    }

#ifdef DEBUG
    //������������ ������������(����� �������� ������������ ��������)
    SmartPointer &operator=(SmartPointer &&obj)
    {
        if(this == &obj)
            return *this;
                
        delete m_ptr;

        m_ptr = obj.m_ptr; //���������� ����� �������
        obj.m_ptr = nullptr;

        std::cout << "��������� ������+\n";

        return *this;
    }
#endif
    //�������� �������������
    T &operator *()const { return *m_ptr; }

    //�������� ��������� � ���������
    T *operator->()const { return m_ptr; }

    //�������� �� ������� ���������
    bool isNull() const { return m_ptr == nullptr; }

private:

    T *m_ptr; //��������� �� ������ ������� ����, ������� ����� ������ ���������
};

//����� �������� ���������
class TestObject
{
public:
    TestObject() { std::cout << "������ �������!\n"; }
    ~TestObject() { std::cout << "������ ���������!\n"; }

    friend std::ostream &operator<<(std::ostream &stream, const TestObject &object)
    {
        stream << object;
        return stream;
    }

};