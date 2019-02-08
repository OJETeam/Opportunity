#include "Test.h"
#include "../Opportunity/Api.h"

int Test::GetPosition(void* unit)
{
	return Api::GetPosition(nullptr);
}
