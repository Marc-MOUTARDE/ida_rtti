#include "main.hh"

RttiRecover::RttiRecover()
{
}

RttiRecover::~RttiRecover()
{
}

bool RttiRecover::run(size_t arg)
{
    return true;
}

static plugmod_t *idaapi init()
{
    return new RttiRecover();
}

plugin_t PLUGIN = {
    IDP_INTERFACE_VERSION,
    PLUGIN_MULTI,
    init,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "Recover RTTI from executable",
    ""
};
