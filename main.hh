#ifndef MAIN_HH
#define MAIN_HH

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <funcs.hpp>

#include "rtti.hh"

class RttiRecover : public plugmod_t
{
private:
public:
    RttiRecover();
    virtual ~RttiRecover();

    virtual bool idaapi run(size_t arg) override;
};

#endif /* MAIN_HH */
