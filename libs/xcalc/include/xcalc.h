#ifndef XCALC_CORE_XCALC_H
#define XCALC_CORE_XCALC_H

#include <string>

#include "DegreeMode.h"

namespace xcalc {

    std::string evaluate(DegreeMode degreeMode, const std::string& input);

} // namespace xcalc

#endif //XCALC_CORE_XCALC_H
