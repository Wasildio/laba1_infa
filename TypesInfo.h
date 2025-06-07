#ifndef TYPES_INFO_H
#define TYPES_INFO_H

#include <stddef.h>
#include "DataTypes.h"

typedef struct TypeInfo {
  size_t size;
  void (*div) (void*, void*, void*);
  void (*diff) (void*, void*, void*);
  void (*sum) (void*, void*, void*);
  void (*prod) (void*, void*, void*);
  DataType_t type;
} TypeInfo_t;

#endif // TYPES_INFO_H
