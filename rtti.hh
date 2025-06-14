#ifndef RTTI_HH
#define RTTI_HH

#include <cstdint>

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <funcs.hpp>

struct TypeInfo32
{
    uint32_t vfptr;
    uint32_t data;
    char name[];
} __attribute__((packed));

struct TypeInfo64
{
    uint32_t vfptr;
    uint32_t data;
    char name[];
} __attribute__((packed));

struct MemberDataPointer
{
    uint32_t member_dislacement;
    uint32_t vftable_dislacement;
    uint32_t vftable_index;
} __attribute__((packed));

struct BaseClassDescriptor
{
    uint32_t type_descriptor;
    uint32_t nested_classes;
    uint32_t flags;
    uint32_t class_descriptor;
} __attribute__((packed));

struct ClassHierarchyDescriptor
{
    uint32_t signature;
    uint32_t attributes;
    uint32_t base_class_count;
    uint32_t base_class_array;
} __attribute__((packed));

struct CompleteObjectLocator
{
    uint32_t signature;
    uint32_t offset;
    uint32_t type_descriptor;
    uint32_t class_descriptor;
} __attribute__((packed));

struct CompleteObjectLocator64
{
    uint32_t signature;
    uint32_t offset;
    uint32_t type_descriptor;
    uint32_t class_descriptor;
    uint32_t object_base;
} __attribute__((packed));

bool process_vftable(ea_t table, ea_t col, bool known = false);

#endif /* RTTI_HH */
