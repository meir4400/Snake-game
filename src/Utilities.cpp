
#include "Utilities.h"

Utilities Utilities::m_util;

Utilities::Utilities() {}


Utilities* Utilities::instance()
{
	return &m_util;
}

