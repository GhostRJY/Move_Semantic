#pragma once
#include<iostream>

template<class T>
class DynArray
{
public:
    DynArray(int length)
        :m_arrPtr{ new T[length] }, m_length{ length }
    {}

    ~DynArray()
    {
        delete [] m_arrPtr;
    }

    //������ ����-� �����������
    DynArray(const DynArray &) = delete;

    //������ �������� ������������ copy
    DynArray &operator = (const DynArray &) = delete;

    //����-� �����������
    DynArray(DynArray &&argArr)
        : m_arrPtr{ argArr.m_arrPtr }, m_length{ argArr.m_length }
    {
        argArr.m_arrPtr = nullptr;
        argArr.m_length = 0;
    }

    //�������� ������������ move
    DynArray &operator=(DynArray &&argArr)
    {
        if(this == &argArr)
            return *this;

        delete[]m_arrPtr;

        m_length = argArr.m_length;
        m_arrPtr = argArr.m_arrPtr;
        argArr.m_arrPtr = nullptr;
        argArr.m_length = 0;

        return *this;
    }

    int getLength()const
    { return m_length; }

    T &operator[](int index)
    {
        if(index < 0) {
            std::cout << "������ �� ����� ���� ������ ����!!!\n���� ������ ������� �������!!!\n";
            return m_arrPtr[0];
        }
        else if(index >= m_length) {
            std::cout << "������ ������ �������!!!\n���� ��������� ������� �������!!!\n";
            return m_arrPtr[m_length - 1];
        }
        else {
            return m_arrPtr[index];
        }
    }

    const T &operator[](int index) const
    {
        if(index < 0) {
            std::cout << "������ �� ����� ���� ������ ����!!!\n���� ������ ������� �������!!!\n";
            return m_arrPtr[0];
        } else if(index >= m_length) {
            std::cout << "������ ������ �������!!!\n���� ��������� ������� �������!!!\n";
            return m_arrPtr[m_length - 1];
        } else {
            return m_arrPtr[index];
        }
    }

private:
    T *m_arrPtr;
    int m_length;
};

