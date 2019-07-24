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
