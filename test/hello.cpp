#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(hello)

BOOST_AUTO_TEST_CASE(fortytwo)
{
	BOOST_CHECK_EQUAL(42, 42);
}

BOOST_AUTO_TEST_SUITE_END() // hello
