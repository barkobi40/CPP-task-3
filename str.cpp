// Created by Bar Kobi on 19/05/2023.
#include "str.h"

//Default Ctor, initializes the string to "none"
Str::Str(){
    m_str = new char[5];
    strcpy(m_str, "none");
}

//Copy Ctor, initializes the string to a copy of the given string
Str::Str(const Str& other){
    m_str = new char[strlen(other.m_str) + 1];

    strcpy(m_str, other.m_str);
}

//Move Ctor, initializes the string to a copy of the given string
Str::Str(const char* str){
    m_str = new char[strlen(str) + 1];

    strcpy(m_str, str);
}

//Deletes all the dynamic allocations
Str::~Str(){
    delete[] m_str;
}

//An operator for comparing two strings
bool Str::operator==(const Str& other) const{
    if (strcmp(m_str, other.m_str) == 0)
        return true;
    else
        return false;
}

//An operator for comparing two strings
bool Str::operator!=(const Str& other) const{
    if (strcmp(m_str, other.m_str) != 0)
        return true;
    else
        return false;
}

//Compares two strings lexicographically
bool Str::operator>(const Str& other) const{
    if (strcmp(m_str, other.m_str) > 0)
        return true;
    else
        return false;
}

//Compares two strings lexicographically
bool Str::operator<(const Str& other) const{
    if (strcmp(m_str, other.m_str) < 0)
        return true;
    else
        return false;
}

//Object placement operator
const Str& Str::operator=(const Str& other){
    if (&other != this) {
        delete[] this->m_str;

        m_str = new char[strlen(other.m_str) + 1];

        strcpy(m_str, other.m_str);
    }
    return *this;
}

//String assignment operator
const Str& Str::operator=(const char* str){
    if (this->m_str != str) {
        delete[] this->m_str;

        m_str = new char[strlen(str) + 1];

        strcpy(m_str, str);
    }
    return *this;
}

//returns the character instead of the index
char& Str::operator[](int index) const{

    return this->m_str[index];
}

//Advances the ASCII value by 1
const Str& Str::operator++(){
    for (unsigned int i = 0; i < strlen(this->m_str); i++) {
        this->m_str[i] = this->m_str[i] + 1;
    }
    return *this;
}

//Advances the ASCII value by 1
Str Str::operator++(int){
    Str tmp = *this;
    ++* this;
    return tmp;
}

//Return the string length
Str::operator int() const{
    return (int)strlen(this->m_str);
}

//Should return the first position where the character Ch appears
int Str::operator()(char ch) const{
    for (int i = 0; i != strlen(m_str); i++){
        if (this->m_str[i] == ch){
            return i;
        }
    }
    return -1;
}

//Concatenates between strings
Str Str::operator+(const Str& other) const{
    char* newStr = new char[strlen(this->m_str) + strlen(other.m_str) + 1];

    strcpy(newStr, this->m_str);
    strcat(newStr, other.m_str);

    Str str = Str(newStr);
    return str;
}

//Concatenates between strings
Str operator+(const char* str, const Str& other){
    char* newStr = new char[strlen(str) + strlen(other.m_str) + 1];

    strcpy(newStr, str);
    strcat(newStr, other.m_str);

    Str strFinal = Str(newStr);
    return strFinal;
}

//Concatenates the string it receives as a parameter, "num" times
Str operator*(int num, const Str& other){
    char* newStr = new char[strlen(other.m_str) * num + 1];

    strcpy(newStr, other.m_str);
    for (int i = 0; i < num - 1; i++) {
        strcat(newStr, other.m_str);
    }

    Str finalStr = Str(newStr);
    return finalStr;
}

//Concatenates between strings
const Str& Str::operator+=(const Str& other){
    char* newStr = new char[strlen(this->m_str) + strlen(other.m_str) + 1];

    strcpy(newStr, this->m_str);
    strcat(newStr, other.m_str);

    *this = *this + other;
    return *this;
}
