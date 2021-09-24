#pragma once

class Chargeable {
public:
    virtual ~Chargeable() = default;
    virtual void charge() = 0;
};
