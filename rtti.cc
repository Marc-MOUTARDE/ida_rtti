#include "rtti.hh"

#include <name.hpp>
#include <xref.hpp>
#include <demangle.hpp>

bool process_nt_vtable()
{
    ea_t base, flags;
    qstring name, mangled;
    xrefblk_t ref;
    bool i;
   
    msg("try to get type info...\n");
    base = get_name_ea(BADADDR, "??_7type_info@@6B@");
    if (base == BADADDR) {
        msg("Failed\n");
        return false;
    }

    for (i = ref.first_to(base, XREF_ALL); i; i = ref.next_to()) {
        flags = get_full_flags(ref.from);
        if (is_code(flags)) {
            continue;
        }

        mangled = get_name(ref.from);
        demangle_name(&name, mangled.c_str(), MNG_SHORT_FORM);

        msg("class name (mng): %s\n", mangled.c_str());
        msg("class name(dmng): %s\n", name.c_str());

    }
    return true;
}
