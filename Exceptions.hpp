#pragma once
class Exception
{
 public:
    void virtual getException();
};
 class ExceptionChangeEngine : public Exception
{
 public:
     void getException();
};
class ExcepptionMaxSpeed :public Exception
{
public:
    void getException();
};
class ExcepptionRSpeed :public Exception
{
public:
    void getException();
};
