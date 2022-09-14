#include "gmock/gmock.h"

#include "example.h"

using namespace testing;

namespace Casos_Base::tests {
	TEST(Casos_Base, Test_Caso1) {
		foobar::Example example{};
        ASSERT_THAT(example.getValue(), Eq(88));
	}

	TEST(Casos_Base, Test_Caso2) {
		foobar::Example example{};
        ASSERT_THAT(example.getValue(), Eq(88));
	}

	TEST(Casos_Base, Test_Caso3) {
		foobar::Example example{};
        ASSERT_THAT(example.getValue(), Eq(99));
	}
}