#include "utils.hh"

#include <string>

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <funcs.hpp>
#include <loader.hpp>

OsType get_os()
{
    char buffer[BUFFER_SIZE];
    std::string name;

    get_file_type_name(buffer, BUFFER_SIZE);
    name = std::string(buffer);
    msg("%s\n", name.c_str());

    if (name.find("ELF") != std::string::npos) {
        return OsType::Linux;
    } else if (name.find("PE") != std::string::npos) {
        return OsType::Nt;
    } else {
        return OsType::Other;
    }
}
