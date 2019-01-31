#pragma once

#include <crsf/CRAPI/TDynamicModuleInterface.h>

class EmptyModule: public crsf::TDynamicModuleInterface
{
public:
    EmptyModule();

    void OnLoad() override;
    void OnStart() override;
    void OnExit() override;

    // Write interfaces
    virtual int get_data() const;
    virtual void set_data(int data);

private:
    int data_;
};
