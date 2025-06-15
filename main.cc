#include "main.hh"

#include "utils.hh"

RttiRecover::RttiRecover()
{
}

RttiRecover::~RttiRecover()
{
}

bool RttiRecover::run(__attribute__((unused)) size_t arg)
{
    msg("Run RTTI Recover\n");
    switch (get_os()) {
    case OsType::Nt:
        msg("NT file\n");
        return process_nt_vtable();
    case OsType::Linux:
        msg("Linux file\n");
        return false;
    case OsType::Other:
        msg("Other file\n");
        return false;
    }
    return false;
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
