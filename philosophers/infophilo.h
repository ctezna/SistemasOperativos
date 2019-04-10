#pragma once
#include "table.h"

struct infophilo {
  infophilo(Table& table, int pos) : table(table), pos(pos) { }
  Table& table;
  int pos;
};

typedef infophilo* PInfoFilo;