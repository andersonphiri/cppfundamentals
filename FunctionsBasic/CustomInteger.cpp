#include "CustomInteger.h"

CustomInteger::CustomInteger()
{
    m_pInt = new int(0);
}

CustomInteger::CustomInteger(int value)
{
    m_pInt = new int(value);
}

int CustomInteger::GetValue() const
{
    return *m_pInt;
}

void CustomInteger::SetValue(int value)
{
    *m_pInt = value;
}

CustomInteger::~CustomInteger()
{
    delete m_pInt;
}
CustomInteger::CustomInteger(CustomInteger&& obj)
{
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}
CustomInteger CustomInteger::operator+(const CustomInteger& a) const
{
    CustomInteger temp;
    *temp.m_pInt = *m_pInt + *a.m_pInt;
    return temp;
}
CustomInteger  CustomInteger::operator++()
{
    ++(*m_pInt);
    return *this;
}
CustomInteger & CustomInteger::operator++(int)
{
    CustomInteger temp(*this);
    ++(*m_pInt);
    return temp;
}
bool CustomInteger::operator==(const CustomInteger& obj) const
{
    return *m_pInt == *obj.m_pInt;
}
CustomInteger& CustomInteger::operator=(const CustomInteger& a)
{
    if (this != &a)
    {
        delete m_pInt;
        m_pInt = new int(*a.m_pInt);
    }
    
    return *this;
}
CustomInteger& CustomInteger::operator= (CustomInteger&& a)
{
    if (this != &a) {
        delete m_pInt;
        m_pInt = a.m_pInt;
        a.m_pInt = nullptr;
    }
    return *this;
}
// copy constructor
CustomInteger::CustomInteger(const CustomInteger& obj)
{
    m_pInt = new int(*obj.m_pInt); // now created a deep copy
}

//