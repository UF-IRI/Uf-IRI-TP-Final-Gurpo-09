#include "gmock/gmock.h"

#include "example.h"

using namespace testing;

namespace Casos_Base::tests {
	TEST(Casos_Base, Caso_I) {
		foobar::Example example{};
        ASSERT_THAT(example.getValue(), Eq(88));
	}

	TEST(Casos_Base, Caso_II) {
		foobar::Example example{};
        ASSERT_THAT(example.getValue(), Eq(88));
	}

	TEST(Casos_Base, Caso_III) {
		foobar::Example example{};
        ASSERT_THAT(example.getValue(), Eq(88));
	}
}