//
// Created by erik on 06.07.17.
//

#pragma once

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int theAnswer() { return 6*9; }

TEST_CASE( "Life, the universe and everything", "[42][theAnswer]" ) {
    REQUIRE( theAnswer() == 42 );
}