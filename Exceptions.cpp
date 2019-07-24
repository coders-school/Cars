#include"Exceptions.hpp"
#include<iostream>

using namespace std;

void Exception::getException() {};
void ExceptionChangeEngine::getException() {cout<<"Impossible change Engine"<<endl;}
void ExcepptionMaxSpeed::getException()    {cout<<"Over max speed"<<endl;}
void ExcepptionRSpeed::getException() {cout<< "You move back to fast";}
