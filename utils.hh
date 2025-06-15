#ifndef UTILS_HH
#define UTILS_HH

enum class OsType
{
    Nt = 0,
    Linux,
    Other
};

#define BUFFER_SIZE 0x1000

OsType get_os();

#endif /* UTILS_HH */
