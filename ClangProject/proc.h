#pragma once

#undef INT8_MIN
#undef INT16_MIN
#undef INT32_MIN
#undef INT8_MAX
#undef INT16_MAX
#undef INT32_MAX
#undef UINT8_MAX
#undef UINT16_MAX
#undef UINT32_MAX

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <memory>
using namespace std;

#include "common.h"
#include "value.h"
#include "expression.h"
#include "statement.h"
#include "declaration.h"
#include "stackMachine.h"