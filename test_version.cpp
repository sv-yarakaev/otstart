//
// Created by tophy on 28-Sep-20.
//
#define BOOST_TEST_MODULE otstart_test_module
#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(otstart_test_suite)

BOOST_AUTO_TEST_CASE(ostsart_test_version)
        {
            BOOST_CHECK(version() > 0);
        }
        BOOST_AUTO_TEST_SUITE_END()